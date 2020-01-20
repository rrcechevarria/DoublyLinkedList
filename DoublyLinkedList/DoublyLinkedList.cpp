// DoublyLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

struct Node {
	int data;
	Node *prev;
	Node *next;
};

Node * addnode(int);
void insertnode(int);
void forwardDisplay();
void backwardDisplay();
void deletenode(int);
Node* head;

int main()
{

	insertnode(3);
	insertnode(5);
	insertnode(10);
	forwardDisplay();
	cout << endl;
	backwardDisplay();
	cout << endl;
	deletenode(3);
	forwardDisplay();

	getchar();
	return 0;
}

void deletenode(int n) {
	Node *current = head;
	Node *prev = NULL;
	Node *temp;
	if (current == NULL) {
		cout << "List Empty";
		return;
	}
	if (current->data == n) {
		temp = current;
		current = current->next;
		current->prev = NULL;
		head = current;
		delete temp;
		return;
	}
	while (current != NULL) {
		if (current->data == n && current->next == NULL) {
			prev->next = NULL;
			delete current;
			return;
		}
		if(current->data == n){
			prev->next = current->next;	
			temp = current;
			current = current->next;
			delete temp;
			current->prev = prev;
			return;
		}
		prev = current;
		current = current->next;
	}


}

void backwardDisplay() {
	Node *current = head;
	if (head == NULL){
		cout << "List Empty";
		return;
	}
	while (current->next != NULL) {
		current = current->next;
	}
	while (current != NULL) {
		cout << current->data << ' ';
		current = current->prev;
	}

}

void forwardDisplay() {
	Node *current = head;
	if (head == NULL) {
		cout << "List empty";
		return;
	}
	while (current != NULL)
	{
		cout << current->data << ' ';
		current = current->next;
	}
	return;
}




void insertnode(int n) {
	Node *newNode = addnode(n);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}


Node* addnode(int n) {
	Node *newNode = new Node;
	newNode->data = n,
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}