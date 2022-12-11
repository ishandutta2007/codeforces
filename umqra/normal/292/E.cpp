#include <iostream>
#include <cstdio>
using namespace std;

const int N = (int)2e5;
const int pow2 = (1 << 18);

struct item
{
	int tree[pow2 * 2];        
	void build()
	{
		for (int i = 0; i < pow2 * 2; i++)
			tree[i] = 0;
	}
	void push(int v)
	{
		if (tree[v] != 0)
		{
			tree[2 * v] = tree[2 * v + 1] = tree[v];
			tree[v] = 0;
		}
	}
	void setVal(int a, int b, int val, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l >= a && r <= b)
		{
			tree[v] = val;
			return;
		}
		if (l > b || r < a)
			return;
		push(v);
		int m = (l + r) / 2;
		setVal(a, b, val, 2 * v, l, m);
		setVal(a, b, val, 2 * v + 1, m + 1, r);
	}	
	int getVal(int x, int v = 1, int l = 0, int r = pow2 - 1)
	{                     
		if (l == r)
			return tree[v];
		push(v);
		int m = (l + r) / 2;
		if (x <= m)
			return getVal(x, 2 * v, l, m);
		else
			return getVal(x, 2 * v + 1, m + 1, r);
	}
} tree;

int a[N], b[N];

int qA[N], qB[N], qK[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	tree.build();
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= m; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int x, y, k;
			scanf("%d%d%d", &x, &y, &k);
			tree.setVal(y, y + k - 1, i);
			qA[i] = x;
			qB[i] = y;
			qK[i] = k;
		}
		else
		{
			int ind;
			scanf("%d", &ind);
			int q = tree.getVal(ind);
			if (q == 0)
				printf("%d\n", b[ind]);
			else
				printf("%d\n", a[qA[q] + (ind - qB[q])]);
		}
	}

	return 0;
}