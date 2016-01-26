#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	list_t* ptr = head;
	// nead to reassign head if it is less than head
	while (1)
	{
		if(ptr->index > ptr->next->index)
		{
			int temp = ptr->index;
			ptr->index = new_element->index;
			ptr->next->index = temp;
			break;
		}
		else
		{
			ptr = ptr->next;
		}
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t *temp = head;
	list_t *back = temp;

	int count =0;
	while(temp->next)
	{
		count++;
		temp = temp->next;
	}
	int copy;

	temp = head;
	back = head;
	int i = 0;
	while ( i < count)
	{
		int j = 0;
		while( j < count - i)
		{
			assert(back->next);
			back = back->next;
			j++;
		}
		copy = temp->index;
		temp->index = back->index;
		back->index = copy;
		temp = temp->next;
		i++;
	}

	return head;
}

