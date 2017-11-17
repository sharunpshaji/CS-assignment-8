#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class linked_list {
private:
	node *head, *tail;
public:
	linked_list() {
		head = NULL;
		tail = NULL;
	}
	void addNode(int n) {
		node *temp = new node;
		temp->data = n;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}
	void insert_start(int n) {
		node *temp = new node;
		temp->data = n;
		temp->next = head;
		head = temp;
	}
	void insert(int pos, int value) {
		node *previous = new node;
		node *current = new node;
		node *temp = new node;
		current = head;
		for (int i = 1; i < pos; i++) {
			previous = current;
			current = current->next;
		}
		previous->next = temp;
		temp->data = value;
		temp->next = current;
	}
	void displayNode() {
		node *temp = new node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	void delete_first() {
		node *temp = new node;
		temp = head;
		head = head->next;
		delete temp;
	}
	void delete_last() {
		node *previous = new node;
		node *current = new node;
		while(current->next != NULL) {
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = NULL;
		delete current;
	}
	void delete_pos(int pos) {
		node *previous = new node;
		node *current = new node;
		current = head;
		for (int i = 1; i < pos; i++) {
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		delete current;
	}
};

int main() {
	linked_list firstNode;
	firstNode.addNode(4);
	firstNode.addNode(6);
	firstNode.displayNode();
	cout << endl;
	return 0;
}

