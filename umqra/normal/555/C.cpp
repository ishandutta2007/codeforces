#include <iostream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node
{
	Node *l, *r;
	int val;
	Node () : l(), r(), val(-1) {}
	Node (int x) : l(), r(), val(x) {}
	Node (Node *_l, Node *_r, int x) : l(_l), r(_r), val(x) {}
};

Node *rootL = new Node();
Node *rootU = new Node();

void push(Node* v)
{
	if (v -> l != NULL)
		v -> l -> val = max(v -> l -> val, v -> val);
	else
		v -> l = new Node(v -> val);
	if (v -> r != NULL)
		v -> r -> val = max(v -> r -> val, v -> val);
	else
		v -> r = new Node(v -> val);
	v -> val = -1;
}

Node* setVal(int a, int b, int val, Node *v, int l, int r)
{
	if (l > b || r < a)
		return v;
	if (v == NULL)
		v = new Node();
	if (l >= a && r <= b)
	{
		v -> val = max(v -> val, val);
		return v;
	}
	push(v);
	int m = (l + r) / 2;
	v -> l = setVal(a, b, val, v -> l, l, m);
	v -> r = setVal(a, b, val, v -> r, m + 1, r);
	return v;
}

int getVal(int pos, Node *v, int l, int r)
{
	if (v == NULL)
		return -1;
	if (l == r)
		return v -> val;
	push(v);
	int m = (l + r) / 2;
	if (pos <= m)
		return getVal(pos, v -> l, l, m);
	return getVal(pos, v -> r, m + 1, r);
}

set <int> used;

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; i++)
	{
		int x, y;
		char t;
		scanf("%d%d %c", &x, &y, &t);
		x--, y--;

		if (used.count(x) != 0)
		{
			puts("0");
			continue;
		}
		used.insert(x);
		if (t == 'L')
		{
			int b = getVal(x, rootL, 0, n - 1);
			printf("%d\n", x - b);
			setVal(b, x, y, rootU, 0, n - 1);
		}
		else
		{
			int b = getVal(x, rootU, 0, n - 1);
			printf("%d\n", y - b);
			setVal(x, x + (y - b) - 1, x, rootL, 0, n - 1);
		}
	}
	return 0;
}