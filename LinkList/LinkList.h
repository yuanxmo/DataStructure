/*** 
 * 使用C语言实现单链表源代码
 * @author YuanxMo
 * @since 2024/9/13
 * @version 1.0
*/

#ifndef LINK_LIST_H
#define LINK_LIST_H

// 头文件
#include <stdio.h>
#include <stdlib.h>


/**
 * 链表结点结构类型的定义
 * 
 * @param (int)data 数据域
 * @param (struct Node*)next 指针域
 */
typedef struct Node {
    int data;
    struct Node* next;
} ListNode, *LinkList;


/**
 * 以 ()->()->NULL 形式打印链表
 * 
 * @param (ListNode*) listNode 链表结点指针
 */
void ListNode_print_Link(ListNode* listNode) {
    if (listNode == NULL)
        return;
    ListNode* p = listNode->next;
    printf("Head->");
    while (p != NULL) {
        printf("%d ->", p->data);
    }
    printf("NULL\n");
}

/**
 * 初始化头结点
 * 
 * @return 初始化完成的头结点指针(不确保成功)
 */
ListNode *ListNode_init() {
    LinkList head = (LinkList)malloc(sizeof(ListNode));
    if (head == NULL)
        return head;
    head->next = NULL;
    return head;
}

/**
 * 销毁链表
 * 
 * @param (ListNode*) listNode 链表结点指针
 */
void ListNode_destroy(LinkList* listNode) {
    // 对链表判空
    if ((*listNode) == NULL)
        return;
    ListNode* p = (*listNode)->next;
    ListNode* q = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    free(*listNode);
    *listNode = NULL;
}

/**
 * 在链表头插入结点
 * 
 * @param (ListNode*) listNode 链表结点指针
 * @param (int) data 要插入的数据
 * @return 插入成功返回1，否则返回0
 */
int ListNode_insert_head(LinkList listNode, int data) {
    // 链表判空
    if (listNode == NULL)
        return 0;
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    if (p == NULL)
        return 0;
    p->data = data;
    p->next = listNode->next;
    listNode->next = p;
    return 1;
}

/**
 * 在链表尾插入结点
 * 
 * @param (ListNode*) listNode 链表结点指针
 * @param (int) data 要插入的数据
 * @return 插入成功返回1，否则返回0
 */
int ListNode_insert_tail(LinkList listNode, int data) {
    // 链表判空
    if (listNode == NULL)
        return 0;
    ListNode *p = listNode;
    while (p->next != NULL)
        p = p->next;
    ListNode *q = (ListNode*)malloc(sizeof(ListNode));
    if (q == NULL)
        return 0;
    q->data = data;
    q->next = NULL;
    p->next = q;
    return 1;
}

/**
 * 在链表指定位置插入结点
 * 
 * @param (ListNode*) listNode 链表结点指针
 * @param (int) data 要插入的数据
 * @param (int) index 要插入的位置
 * @return 插入成功返回1，否则返回0
 */
int ListNode_insert_index(LinkList listNode, int data, int index) {
    // 链表判空
    if (listNode == NULL)
        return 0;
    ListNode *p = listNode;
    int i = 0;
    while (p->next != NULL && i < index - 1) {
        p = p->next;
        i++;
    }
    if (i != index - 1)
        return 0;
    ListNode *q = (ListNode*)malloc(sizeof(ListNode));
    if (q == NULL)
        return 0;
    q->data = data;
    q->next = p->next;
    p->next = q;
    return 1;
}








#endif