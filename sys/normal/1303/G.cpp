#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 150005;
int n, cnt, tot, root, a[Maxn], siz[Maxn], maxi[Maxn], head[Maxn];
long long ans;
bool vis[Maxn];
struct Tree
{
	int lt, rt;
	pair <long long, long long> val;
	bool tag;
} tree[4 * Maxn];
void pushdown(int root)
{
	if (tree[root].tag)
	{
		tree[root << 1].val = make_pair(0, -0x3f3f3f3f3f3f3f3fLL), tree[root << 1].tag = true;
		tree[root << 1 | 1].val = make_pair(0, -0x3f3f3f3f3f3f3f3fLL), tree[root << 1 | 1].tag = true;
		tree[root].tag = 0;
	}
}
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, make_pair(0, -0x3f3f3f3f3f3f3f3fLL), false};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
	}
}
long long f(pair <long long, long long> now, long long x)
{
	return now.first * x + now.second;
}
void insert(int root, pair <long long, long long> val)
{
	if (tree[root].lt + 1 == tree[root].rt)
	{
		if (f(tree[root].val, tree[root].lt) < f(val, tree[root].lt))
			tree[root].val = val;
	}
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (tree[root].val.first >= val.first)
		{
			if (f(tree[root].val, mid) < f(val, mid))
				insert(root << 1 | 1, tree[root].val), tree[root].val = val;
			else
				insert(root << 1, val);
		}
		else
		{
			if (f(tree[root].val, mid) < f(val, mid))
				insert(root << 1, tree[root].val), tree[root].val = val;
			else
				insert(root << 1 | 1, val);
		}
	}
}
vector <int> G[Maxn];
void get_root(int u, int fa)
{
	siz[u] = 1, maxi[u] = 0;
	for (auto to : G[u])
		if (to != fa && !vis[to])
		{
			get_root(to, u);
			siz[u] += siz[to];
			maxi[u] = max(maxi[u], siz[to]);
		}
	maxi[u] = max(maxi[u], tot - siz[u]);
	if (maxi[u] < maxi[root]) root = u;
}
long long ask(int root, int pos)
{
	if (tree[root].lt + 1 == tree[root].rt) return f(tree[root].val, pos);
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) return max(ask(root << 1 | 1, pos), f(tree[root].val, pos));
		else return max(ask(root << 1, pos), f(tree[root].val, pos));
	}
}
void modify(int u, int fa, int dep, long long sum1, long long sum2)
{
	sum1 += a[u], sum2 += dep * (long long) a[u];
	ans = max(ans, sum2);
	insert(1, make_pair(sum1, sum2));
	for (auto to : G[u])
		if (to != fa && !vis[to]) modify(to, u, dep + 1, sum1, sum2);
}
void work(int u, int fa, int dep, long long sum1, long long sum2)
{
	sum1 += a[u], sum2 += sum1;
	ans = max(ans, sum2 + ask(1, dep));
	for (auto to : G[u])
		if (to != fa && !vis[to]) work(to, u, dep + 1, sum1, sum2);
}
void divide(int u)
{
	vis[u] = true;
	tree[1].val = make_pair(0, -0x3f3f3f3f3f3f3f3fLL), tree[1].tag = true;
	insert(1, make_pair(a[u], a[u]));
	for (vector <int> :: iterator it = G[u].begin(); it != G[u].end(); it++)
		if (!vis[*it])
			work(*it, 0, 1, 0, 0), modify(*it, 0, 2, a[u], a[u]);
	tree[1].val = make_pair(0, -0x3f3f3f3f3f3f3f3fLL), tree[1].tag = true;
	insert(1, make_pair(a[u], a[u]));
	for (vector <int> :: reverse_iterator it = G[u].rbegin(); it != G[u].rend(); it++)
		if (!vis[*it])
			work(*it, 0, 1, 0, 0), modify(*it, 0, 2, a[u], a[u]);
	for (auto to : G[u])
		if (!vis[to])
		{
			get_root(to, 0), tot = siz[to], root = 0, get_root(to, 0);
			divide(root);
		}
}
int main()
{
	maxi[0] = 0x3f3f3f3f;
	scanf("%d", &n);
	build(1, 1, n + 1);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	tot = n, get_root(1, 0);
	divide(root);
	printf("%lld", ans);
	return 0;
}