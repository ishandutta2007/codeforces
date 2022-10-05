#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int n, q, a[Maxn];
struct Tree
{
	int lt, rt, mini, cnt, lazy;
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
void update(int root)
{
	tree[root].cnt = 0;
	tree[root].mini = min(tree[root << 1].mini, tree[root << 1 | 1].mini);
	if (tree[root << 1].mini == tree[root].mini) tree[root].cnt += tree[root << 1].cnt;
	if (tree[root << 1 | 1].mini == tree[root].mini) tree[root].cnt += tree[root << 1 | 1].cnt;
}
void pushdown(int root)
{
	if (tree[root].lazy)
	{
		tree[root << 1].mini += tree[root].lazy;
		tree[root << 1 | 1].mini += tree[root].lazy;
		tree[root << 1].lazy += tree[root].lazy;
		tree[root << 1 | 1].lazy += tree[root].lazy;
		tree[root].lazy = 0;
	}
}
void modify1(int root, int pos, int w)
{
	if (tree[root].lt + 1 == tree[root].rt) tree[root].cnt += w;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) modify1(root << 1 | 1, pos, w);
		else modify1(root << 1, pos, w);
		update(root);
	}
}
void modify2(int root, int lt, int rt, int w)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
		tree[root].mini += w, tree[root].lazy += w;
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
int query(int root, int lt, int rt)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
		return tree[root].mini == 1 ? tree[root].cnt : 0;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) return query(root << 1 | 1, lt, rt);
		else if (rt <= mid) return query(root << 1, lt, rt);
		else return query(root << 1, lt, mid) + query(root << 1 | 1, mid, rt);
	}
}
void change(int lt, int rt, int w)
{
	if (lt == rt) return ;
	if (lt > rt) swap(lt, rt);
	modify2(1, lt, rt, w);
}
int main()
{
	scanf("%d%d", &n, &q);
	build(1, 1, 1000003);
	a[0] = 1000002, a[n + 1] = 1;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), a[i]++;
	for (int i = 0; i <= n; i++)
		change(a[i], a[i + 1], 1), modify1(1, a[i], 1);
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		y++;
		change(a[x - 1], a[x], -1), change(a[x], a[x + 1], -1), modify1(1, a[x], -1);
		a[x] = y;
		change(a[x - 1], a[x], 1), change(a[x], a[x + 1], 1), modify1(1, a[x], 1);
		printf("%d\n", query(1, 2, 1000002));
	}
	return 0;
}