#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 1 << 17;
const int BASE = 60;

int n, q;
int a[MOD];

struct Node
{
	int val;
	int l, r;
	int arr[BASE];

	Node () : val(), l(), r(), arr() {}
	Node (int _val, int _l, int _r)
	{
		l = _l;
		r = _r;
		setVal(_val);
	}
	Node (int _l, int _r)
	{
		l = _l;
		r = _r;
	}

	void setVal(int w)
	{
		val = w;
		for (int i = 0; i < BASE; i++)
			if (i % w == 0)
				arr[i] = 2;
			else
				arr[i] = 1;
	}
};

Node tree[2 * MOD];

void update(int v)
{
	if (v >= MOD) throw;
	for (int i = 0; i < BASE; i++)
	{
		int x = (i + tree[2 * v].arr[i]) % BASE;
		tree[v].arr[i] = tree[2 * v].arr[i] + tree[2 * v + 1].arr[x];
	}
	return;
}

void buildTree()
{
	for (int i = 0; i < MOD; i++)
	{
		if (i < n)
			tree[MOD + i] = Node(a[i], i, i);
		else
			tree[MOD + i] = Node(1, i, i);
	}
	for (int i = MOD - 1; i > 0; i--)
	{
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
		update(i);
	}
	return;
}

void setVal(int v, int w)
{
	v += MOD;
	tree[v].setVal(w);
	v /= 2;
	while (v > 0)
	{
		update(v);
		v /= 2;
	}
	return;
}

int getTime(int v, int l, int r, int tm)
{
	if (l > tree[v].r || r < tree[v].l)
		return tm;
	if (l <= tree[v].l && tree[v].r <= r)
		return tm + tree[v].arr[tm % BASE];
	return getTime(2 * v + 1, l, r, getTime(2 * v, l, r, tm));
}

void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	buildTree();

	scanf("%d", &q);
	while(q--)
	{
		char c;
		int x, y;
		scanf(" %c %d %d", &c, &x, &y);
		if (c == 'A')
		{
			x--;
			y -= 2;
			printf("%d\n", getTime(1, x, y, 0));
		}
		else
		{
			x--;
			setVal(x, y);
		}
	}

	return 0;
}