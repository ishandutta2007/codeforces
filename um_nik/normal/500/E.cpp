#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = (int)2e5 + 200;
int n, q;
int x[N], y[N];
int a[N][20][2];

struct Node
{
	int l, r;
	int val;

	Node () : l(), r(), val() {}
	Node (int _l, int _r) : l(_l), r(_r), val(0) {}
};
const int MOD = 1 << 18;
Node tree[2 * MOD];

void build_tree()
{
	for (int i = 0; i < MOD; i++)
		tree[MOD + i] = Node(i, i + 1);
	for (int i = MOD - 1; i > 0; i--)
		tree[i] = Node( tree[2 * i].l, tree[2 * i + 1].r);
	return;
}

void setVal(int v, int w)
{
	v += MOD;
	tree[v].val = w;
	v /= 2;
	while (v > 0)
	{
		tree[v].val = max(tree[2 * v].val, tree[2 * v + 1].val);
		v /= 2;
	}
	return;
}

int getMaxY(int v, int l, int r)
{
	if (l >= tree[v].r || tree[v].l >= r)
		return -1;
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].val;
	return max( getMaxY(2 * v, l, r), getMaxY(2 * v + 1, l, r) );
}

void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &x[i], &y[i]);
	return;
}

void init()
{
	build_tree();
	for (int i = n - 1; i >= 0; i--)
	{
		y[i] += x[i];
		int r = upper_bound(x + i, x + n, y[i]) - x;
		y[i] = max(y[i], getMaxY(1, i, r));
		setVal(i, y[i]);
	}
	for (int i = 0; i < n; i++)
	{
		int r = upper_bound(x + i, x + n, y[i]) - x;
		if (r == n)
		{
			a[i][0][0] = n - 1;
			a[i][0][1] = 0;
			continue;
		}
		a[i][0][0] = r;
		a[i][0][1] = x[r] - y[i];
	}
	for (int it = 1; it < 20; it++)
		for (int i = 0; i < n; i++)
		{
			int r = a[i][it - 1][0];
			a[i][it][0] = a[r][it - 1][0];
			a[i][it][1] = a[i][it - 1][1] + a[r][it - 1][1];
		}
	return;
}

int solve(int l, int r)
{
	if (y[l] >= x[r]) return 0;
	int ans = 0;
	for (int it = 19; it >= 0; it--)
	{
		if (a[l][it][0] >= r) continue;
		ans += a[l][it][1];
		l = a[l][it][0];
	}
	if (y[l] < x[r])
		ans += x[r] - y[l];
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	read();
	init();

	scanf("%d", &q);
	while(q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r--;
		printf("%d\n", solve(l, r));
	}

	return 0;
}