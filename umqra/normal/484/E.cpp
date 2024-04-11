#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node
{
	int prefixLength;
	int suffixLength;
	int allLength;
	int answer;
	Node ()
	{
		prefixLength = suffixLength = 0;
		allLength = 0;
		answer = 0;
	}
	Node (int p, int s, int all, int ans) : prefixLength(p), suffixLength(s), allLength(all), answer(ans) {}
	void print()
	{
		printf("Node(prefix %d, suffix %d, length %d, answer %d)\n", prefixLength, suffixLength, allLength, answer);
	}
};

Node relax(Node a, Node b)
{
	Node result = Node();
	result.allLength = a.allLength + b.allLength;
	result.prefixLength = a.prefixLength + (a.prefixLength == a.allLength ? b.prefixLength : 0);
	result.suffixLength = b.suffixLength + (b.suffixLength == b.allLength ? a.suffixLength : 0);

	result.answer = max(a.suffixLength + b.prefixLength, max(a.answer, b.answer));
	return result;
}

struct Tree
{
	Node node;
	Tree *l, *r;
	Tree ()
	{
		node = Node();
		l = r = NULL;
	}
	Tree (Node _node, Tree* _l, Tree* _r)
	{
		node = _node;
		l = _l;
		r = _r;
	}
	Tree (Tree* _l, Tree* _r)
	{
		l = _l;
		r = _r;
		node = relax(l -> node, r -> node);
	}
};

typedef Tree* Tree_ptr;

const int N = (int)1e5 + 10;
const int pow2 = (1 << 18);

Tree_ptr root[N];

Tree_ptr buildTree(int l = 0, int r = pow2 - 1)
{
	if (l == r)
		return new Tree(Node(1, 1, 1, 1), NULL, NULL);
	int m = (l + r) / 2;
	return new Tree(buildTree(l, m), buildTree(m + 1, r));
}

Tree_ptr setValue(int pos, int value, Tree_ptr v, int l = 0, int r = pow2 - 1)
{
	if (l == r)
	{
		Node x = Node();
		x.allLength = 1;
		x.prefixLength = x.suffixLength = value;
		x.answer = value;
		return new Tree(x, NULL, NULL);
	}
	int m = (l + r) / 2;
	if (pos <= m)
		return new Tree(setValue(pos, value, v -> l, l, m), v -> r);
	return new Tree(v -> l, setValue(pos, value, v -> r, m + 1, r));
}

Node getValue(int a, int b, Tree_ptr v, int l = 0, int r = pow2 - 1)
{
	if (l >= a && r <= b)
	{
		return v -> node;
	}
	if (l > b || r < a)
		return Node();
	int m = (l + r) / 2;

	Node LL = getValue(a, b, v -> l,  l, m);
	Node RR = getValue(a, b, v -> r, m + 1, r);
//	printf("l = %d, r = %d\n", l, r);
//	LL.print();
//	RR.print();
	return relax(LL, RR);
}

int h[N];
int allH[N];
vector <int> positions[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &h[i]);
		allH[i] = h[i];
	}
	sort(allH, allH + n);
	int cnt = unique(allH, allH + n) - allH;
	for (int i = 0; i < n; i++)
	{
		int pos = lower_bound(allH, allH + cnt, h[i]) - allH;
		h[i] = pos;
		positions[h[i]].push_back(i);
	}

	root[0] = buildTree();
	for (int i = 1; i < cnt; i++)
	{
		root[i] = root[i - 1];
		for (int p : positions[i - 1])
		{
			root[i] = setValue(p, 0, root[i]);
		}
	}
	
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		a--, b--;
		int l = 0, r = cnt;
		while (r - l > 1)
		{
			int mid = (l + r) / 2;
//			printf("Mid = %d\n", mid);
			Node x = getValue(a, b, root[mid]);
//			printf("Result:\n");
//			x.print();
			if (x.answer < w)
				r = mid;
			else
				l = mid;
		}
		printf("%d\n", allH[l]);
	}

	return 0;
}