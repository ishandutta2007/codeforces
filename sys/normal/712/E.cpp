#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, q;
struct Tree
{
	int lt, rt;
	double prod, sum;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, 0, 0};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
	}
}
void modify(int root, int pos, double val)
{
	if (tree[root].lt + 1 == tree[root].rt)
		tree[root].prod = tree[root].sum = val;
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) modify(root << 1 | 1, pos, val);
		else modify(root << 1, pos, val);
		tree[root].prod = tree[root << 1].prod * tree[root << 1 | 1].prod;
		tree[root].sum = tree[root << 1].sum + tree[root << 1].prod * tree[root << 1 | 1].sum;
	}
}
pair <double, double> ask(int root, int lt, int rt)
{
	if (tree[root].lt == lt && tree[root].rt == rt)
		return make_pair(tree[root].prod, tree[root].sum);
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) return ask(root << 1 | 1, lt, rt);
		else if (rt <= mid) return ask(root << 1, lt, rt);
		else
		{
			pair <double, double> tmp1 = ask(root << 1, lt, mid), tmp2 = ask(root << 1 | 1, mid, rt);
			return make_pair(tmp1.first * tmp2.first, tmp1.second + tmp1.first * tmp2.second);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	build(1, 1, n + 1);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		double w = x / (double) y;
		modify(1, i, (1 - w) / w);
	}
	while (q--)
	{
		int opt;
		scanf("%d", &opt);
		if (opt == 1)
		{
			int pos, x, y;
			scanf("%d%d%d", &pos, &x, &y);
			double w = x / (double) y;
			modify(1, pos, (1 - w) / w);
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%.10lf\n", 1 / (1 + ask(1, l, r + 1).second));
		}
	}
	return 0;
}