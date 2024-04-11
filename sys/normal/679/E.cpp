#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 100005;
int n, q, ct;
long long p42[20];
struct Tree
{
	int lt, rt;
	long long val, mini, add_tag;
	bool tag;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, 0, 1, 0, true};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
	}
}
void update(int root)
{
	tree[root].mini = min(tree[root << 1].mini, tree[root << 1 | 1].mini);
	tree[root].tag = tree[root << 1].tag && tree[root << 1 | 1].tag && (tree[root << 1].val == tree[root << 1 | 1].val);
	tree[root].val = tree[root << 1].val;
}
void pushdown(int root)
{
	if (tree[root].add_tag)
	{
		tree[root << 1].val += tree[root].add_tag;
		tree[root << 1 | 1].val += tree[root].add_tag;
		tree[root << 1].add_tag += tree[root].add_tag;
		tree[root << 1 | 1].add_tag += tree[root].add_tag;
		tree[root << 1].mini -= tree[root].add_tag;
		tree[root << 1 | 1].mini -= tree[root].add_tag;
		if (tree[root << 1].tag)
			tree[root << 1].mini = *lower_bound(p42 + 1, p42 + 1 + ct, tree[root << 1].val) - tree[root << 1].val;
		if (tree[root << 1 | 1].tag)
			tree[root << 1 | 1].mini = *lower_bound(p42 + 1, p42 + 1 + ct, tree[root << 1 | 1].val) - tree[root << 1 | 1].val;
		tree[root].add_tag = 0;
	}
	if (tree[root].tag)
	{
		tree[root << 1].val = tree[root << 1 | 1].val = tree[root].val;
		tree[root << 1].mini = tree[root << 1 | 1].mini = tree[root].mini;
		tree[root << 1].tag = tree[root << 1 | 1].tag = true;
	}
}
void modify1(int root, int lt, int rt, int val)
{
	if (tree[root].lt == lt && tree[root].rt == rt)
	{
		tree[root].val = val;
		tree[root].mini = *lower_bound(p42 + 1, p42 + 1 + ct, val) - val;
		tree[root].tag = true;
	}
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) modify1(root << 1 | 1, lt, rt, val);
		else if (rt <= mid) modify1(root << 1, lt, rt, val);
		else modify1(root << 1, lt, mid, val), modify1(root << 1 | 1, mid, rt, val);
		update(root);
	}
}
void modify2(int root, int lt, int rt, int w)
{
	if (tree[root].lt == lt && tree[root].rt == rt)
	{
		if (tree[root].tag)
		{
			tree[root].val += w;
			tree[root].mini = *lower_bound(p42 + 1, p42 + 1 + ct, tree[root].val) - tree[root].val;
			tree[root].add_tag += w;
		}
		else if (tree[root].mini >= w) tree[root].mini -= w, tree[root].add_tag += w;
		else
		{
			pushdown(root);
			int mid = (lt + rt) >> 1;
			modify2(root << 1, lt, mid, w);
			modify2(root << 1 | 1, mid, rt, w);
			update(root);
		}
	}
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) modify2(root << 1 | 1, lt, rt, w);
		else if (rt <= mid) modify2(root << 1, lt, rt, w);
		else modify2(root << 1, lt, mid, w), modify2(root << 1 | 1, mid, rt, w);
		update(root);
	}
}
long long ask(int root, int pos)
{
	if (tree[root].lt + 1 == tree[root].rt)
		return tree[root].val;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) return ask(root << 1 | 1, pos);
		else return ask(root << 1, pos);
	}
}
int main()
{
	p42[1] = 1;
	for (ct = 2; ; ct++)
	{
		if (p42[ct - 1] >= 1e16)
		{
			ct--;
			break;
		}
		p42[ct] = p42[ct - 1] * 42;
	}
	scanf("%d%d", &n, &q);
	build(1, 1, n + 1);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		modify2(1, i, i + 1, x);
	}
	for (int i = 1; i <= q; i++)
	{
		int opt;
		scanf("%d", &opt);
		if (opt == 1)
		{
			int x;
			scanf("%d", &x);
			printf("%lld\n", ask(1, x));
		}
		else if (opt == 2)
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			modify1(1, l, r + 1, x);
		}
		else
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			do
				modify2(1, l, r + 1, x);
			while (tree[1].mini <= 0);
		}
	}
	return 0;
}