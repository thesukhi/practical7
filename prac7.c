#include <stdio.h>
#include <stdlib.h>
struct node {
 int data;
 struct node *next;
};
struct node *s;
void create() {
 struct node *p, *q;
 int ch;
 p = (struct node *)malloc(sizeof(struct node));
 prinƞ("Enter the data of the first node\n");
 scanf("%d", &p->data);
 s = p;
 do {
 q = (struct node *)malloc(sizeof(struct node));
 prinƞ("Enter the data of the next node\n");
 scanf("%d", &q->data);
 p->next = q;
 p = q;
 prinƞ("\nPress 1 for the next node :\n");
 scanf("%d", &ch);
 } while (ch == 1);
 p->next = s;
}
void insert_beg() {
 struct node *x, *p;
 x = (struct node *)malloc(sizeof(struct node));
 prinƞ("Enter the data of new node\n");
 scanf("%d", &x->data);
 if (s == NULL) {
 x->next = x;
 s = x;
 } else {
 p = s;
 while (p->next != s) {
 p = p->next;
 }
 x->next = s;
 p->next = x;
 s = x;
 }
}
void insert_end() {
 struct node *x, *p;
 x = (struct node *)malloc(sizeof(struct node));
 prinƞ("Enter the data of new node\n");
 scanf("%d", &x->data);
 if (s == NULL) {
 x->next = x;
 s = x;
 } else {
 p = s;
 while (p->next != s) {
 p = p->next;
 }
 x->next = s;
 p->next = x;
 }
}
void delete_first() {
 struct node *q;
 if (s == NULL) {
 prinƞ("Circular linked list is empty. Cannot delete.\n");
 return;
 }
 q = s;
 while (q->next != s) {
 q = q->next;
 }
 if (q == s) {
 free(s);
 s = NULL;
 } else {
 q->next = s->next;
 free(s);
 s = q->next;
 }
}
void delete_last() {
 struct node *p = s, *q = NULL;
 if (s == NULL) {
 prinƞ("Circular linked list is empty. Cannot delete.\n");
 return;
 }
 while (p->next != s) {
 q = p;
 p = p->next;
 }
 if (q == NULL) {
 free(p);
 s = NULL;
 } else {
 q->next = s;
 free(p);
 }
}
void printCircularList() {
 if (s == NULL) {
 prinƞ("Circular linked list is empty.\n");
 return;
 }
 struct node *p = s;
 do {
 prinƞ("%d ", p->data);
 p = p->next;
 } while (p != s);
 prinƞ("\n");
}
int main() {
 int choice;
 do {
 prinƞ("\nMenu:\n");
 prinƞ("1. Create Circular Linked List\n");
 prinƞ("2. Insert at Beginning\n");
 prinƞ("3. Insert at End\n");
 prinƞ("4. Delete First Node\n");
 prinƞ("5. Delete Last Node\n");
 prinƞ("6. Print Circular Linked List\n");
 prinƞ("7. Exit\n");
 prinƞ("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 create();
 break;
 case 2:
 insert_beg();
 break;
 case 3:
 insert_end();
 break;
 case 4:
 delete_first();
 break;
 case 5:
 delete_last();
 break;
 case 6:
 printCircularList();
 break;
 case 7:
 prinƞ("ExiƟng...\n");
 break;
 default:
 prinƞ("Invalid choice. Please try again.\n");
 }
 } while (choice != 7);
 return 0;
}