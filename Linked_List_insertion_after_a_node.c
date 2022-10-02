#include <stdio.h>
#include <stdlib.h>

//struct definition
struct node
{
    int data;   //struct variables
    struct node *next;
};

//print Linked List

void printLinkedList(struct node *temp_node) //passing the address of head to a temporary node
{
    while(temp_node!=NULL)
    {
        printf("%d ",temp_node->data);
        temp_node=temp_node->next;
    }
    printf("\n");
}

void insertAtFirst(struct node** head_ref,int new_data)
{
    //allocating memory for new node

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=(*head_ref);
    *head_ref=new_node;
}

void insertAfter(struct node* prev_node,int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (prev_node==NULL)
    {
        printf("The previous node cannot be null!!");
    }
    new_node->data=new_data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}

int main()
{
    //initialize the nodes

    struct node* head;
    struct node* one;
    struct node* two;
    struct node* three;

    //allocate memory to the nodes

    one=malloc(sizeof(struct node));
    two=malloc(sizeof(struct node));
    three=malloc(sizeof(struct node));

    //assign values

    one->data=1;
    two->data=2;
    three->data=3;

    //connect the nodes

    one->next=two;
    two->next=three;
    three->next=NULL;

    //printing node

    head=one;
    insertAtFirst(&head,0);
    insertAfter(two,4);
    printLinkedList(head);

}