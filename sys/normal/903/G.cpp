#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, q, head[Maxn];
long long ans[Maxn], x[Maxn], y[Maxn];
struct Tree
{
	int lt, rt;
	long long mini, tag;
} tree[4 * Maxn];
void build(int root, int lt, int rt, long long val[])
{
	tree[root] = (Tree){lt, rt, 0, 0};
	if (lt + 1 == rt)
		tree[root].mini = val[lt];
	else
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid, val), build(root << 1 | 1, mid, rt, val);
		tree[root].mini = min(tree[root << 1].mini, tree[root << 1 | 1].mini);
	}
}
void pushdown(int root)
{
	tree[root << 1].mini += tree[root].tag;
	tree[root << 1].tag += tree[root].tag;
	tree[root << 1 | 1].mini += tree[root].tag;
	tree[root << 1 | 1].tag += tree[root].tag;
	tree[root].tag = 0;
}
void insert(int root, int lt, int rt, int val)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
		tree[root].mini += val, tree[root].tag += val;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) insert(root << 1 | 1, lt, rt, val);
		else if (rt <= mid) insert(root << 1, lt, rt, val);
		else insert(root << 1, lt, mid, val), insert(root << 1 | 1, mid, rt, val);
		tree[root].mini = min(tree[root << 1].mini, tree[root << 1 | 1].mini);
	}
}
struct edg
{
	int nxt, to, w;
} edge[Maxn];
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i < n; i++)
		scanf("%lld%lld", &x[i], &y[i + 1]);
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		edge[i] = (edg){head[x], y, z}, head[x] = i;
	}
	build(1, 1, n + 1, y);
	for (int u = 1; u <= n; u++)
	{
		for (int i = head[u]; i; i = edge[i].nxt)
			insert(1, 1, edge[i].to + 1, edge[i].w);
		ans[u] = tree[1].mini + x[u];
	}
	build(1, 1, n + 1, ans);
	printf("%lld\n", tree[1].mini);
	while (q--)
	{
		int u, w;
		scanf("%d%d", &u, &w);
		insert(1, u, u + 1, w - x[u]);
		x[u] = w;
		printf("%lld\n", tree[1].mini);
	}
	return 0;
}