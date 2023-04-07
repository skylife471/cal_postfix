#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100
typedef char element;
typedef struct {
	element data[MAX_SIZE];
	int top;
}stacktype;

void init_stack(stacktype* s)
{
	// s가 가르키는 stacktype구조체의 탑의 값을 -1로 지정한다.
	s->top = -1;
}

int is_empty(stacktype* s)
{
	return (s->top == -1);
}
int is_full(stacktype* s)
{
	return (s->top == (MAX_SIZE - 1));
}
void push(stacktype* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "Stack Full!\n");
		return;
	}
	else
	{
		s->data[++s->top] = item;
	}
}
element pop(stacktype* s)
{
	if (is_empty(s))
	{

		exit(1);
	}
	else return s->data[(s->top)--];
}

int eval(char exp[])
{
	int op1, op2, i, value;
	int len = strlen(exp);
	char ch;
	stacktype s;
	init_stack(&s);
	for (i = 0; i < len; i++)
	{
		ch = exp[i];
		if (ch >= '0' && ch <= '9')
		{
			value = ch - '0';
			push(&s, value);
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch)
			{
			case '+':
				push(&s, op1 + op2); break;
			case '-':
				push(&s, op1 - op2); break;
			case '*':
				push(&s, op1 * op2); break;
			case '/':
				push(&s, op1 / op2); break;
			}
		}
		else
		{
			printf("Error: Mismatched parentheses");
			exit(1);
		}
	}
	return pop(&s);
}
int main(void)
{
	int result;
	char a[20];
	printf("Enter an infix expression:");
	scanf("%s", &a);
	result = eval(a);
	printf("Result: %d", result);

	return 0;
}