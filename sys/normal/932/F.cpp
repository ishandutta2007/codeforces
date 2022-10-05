#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, tree_ct, cnt, head[Maxn], rt[Maxn];
long long a[Maxn], b[Maxn], mini[Maxn];
struct Tree
{
	int lson, rson;
	pair <long long, long long> val;
} tree[40 * Maxn];
long long f(pair <long long, long long> val, int x)
{
	return val.first * x + val.second;
}
void insert(int &root, int lt, int rt, pair <long long, long long> val)
{
	if (val.second == 0x3f3f3f3f3f3f3f3fLL) return ;
	if (!root) root = ++tree_ct, tree[root].val.second = 0x3f3f3f3f3f3f3f3fLL;
	if (lt + 1 == rt)
	{
		if (f(val, lt) < f(tree[root].val, lt))
			tree[root].val = val;
	}
	else
	{
		int mid = (lt + rt) >> 1;
		if (val.first < tree[root].val.first)
		{
			if (f(val, mid) < f(tree[root].val, mid))
				insert(tree[root].lson, lt, mid, tree[root].val), tree[root].val = val;
			else insert(tree[root].rson, mid, rt, val);
		}
		else
		{
			if (f(val, mid) < f(tree[root].val, mid))
				insert(tree[root].rson, mid, rt, tree[root].val), tree[root].val = val;
			else insert(tree[root].lson, lt, mid, val);
		}
	}
}
int merge(int root1, int root2, int lt, int rt)
{
	if (!root1 || !root2) return root1 + root2;
	int new_node = ++tree_ct, mid = (lt + rt) >> 1;
	tree[new_node].val.second = 0x3f3f3f3f3f3f3f3fLL;
	tree[new_node].lson = merge(tree[root1].lson, tree[root2].lson, lt, mid);
	tree[new_node].rson = merge(tree[root1].rson, tree[root2].rson, mid, rt);
	if (tree[root1].val.first < tree[root2].val.first)
	{
		if (f(tree[root1].val, mid) < f(tree[root2].val, mid))
			insert(tree[new_node].lson, lt, mid, tree[root2].val), tree[new_node].val = tree[root1].val;
		else insert(tree[new_node].rson, mid, rt, tree[root1].val), tree[new_node].val = tree[root2].val;
	}
	else
	{
		if (f(tree[root1].val, mid) < f(tree[root2].val, mid))
			insert(tree[new_node].rson, mid, rt, tree[root2].val), tree[new_node].val = tree[root1].val;
		else insert(tree[new_node].lson, lt, mid, tree[root1].val), tree[new_node].val = tree[root2].val;
	}
	return new_node;
}
long long ask(int root, int lt, int rt, int pos)
{
	if (!root) return 0x3f3f3f3f3f3f3f3fLL;
	if (lt + 1 == rt) return f(tree[root].val, pos);
	else
	{
		int mid = (lt + rt) >> 1;
		if (pos >= mid) return min(f(tree[root].val, pos), ask(tree[root].rson, mid, rt, pos));
		else return min(f(tree[root].val, pos), ask(tree[root].lson, lt, mid, pos));
	}
}
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u, int fa)
{
	rt[u] = ++tree_ct;
	tree[rt[u]].val.second = 0x3f3f3f3f3f3f3f3fLL;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u);
			rt[u] = merge(rt[u], rt[to], -1e5, 1e5 + 1);
		}
	}
	mini[u] = ask(rt[u], -1e5, 1e5 + 1, a[u]);
	if (u != 1 && !edge[head[u]].nxt) mini[u] = 0;
	insert(rt[u], -1e5, 1e5 + 1, make_pair(b[u], mini[u]));
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &b[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		printf("%lld ", mini[i]);
	return 0;
}