#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int n, top, a[Maxn], b[Maxn], sta[Maxn], ans[Maxn];
bool vis[Maxn];
struct Tree
{
	int lt, rt;
	pair <int, int> maxi;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt};
	if (lt + 1 == rt)
		tree[root].maxi = make_pair(b[lt], lt);
	else
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
		tree[root].maxi = max(tree[root << 1].maxi, tree[root << 1 | 1].maxi);
	}
}
void modify(int root, int pos)
{
	if (tree[root].lt + 1 == tree[root].rt)
		tree[root].maxi = make_pair(0, 0);
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) modify(root << 1 | 1, pos);
		else modify(root << 1, pos);
		tree[root].maxi = max(tree[root << 1].maxi, tree[root << 1 | 1].maxi);
	}
}
pair <int, int> get_maxi(int root, int lt, int rt)
{
	if (lt == rt) return make_pair(0, 0);
	if (lt == tree[root].lt && rt == tree[root].rt)
		return tree[root].maxi;
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) return get_maxi(root << 1 | 1, lt, rt);
		else if (rt <= mid) return get_maxi(root << 1, lt, rt);
		else return max(get_maxi(root << 1, lt, mid), get_maxi(root << 1 | 1, mid, rt));
	}
}
void dfs(int u)
{
	vis[u] = true;
	modify(1, u);
	if (!vis[b[u]]) dfs(b[u]);
	pair <int, int> now = get_maxi(1, 1, a[u]);
	while (now.first > u)
		dfs(now.second), now = get_maxi(1, 1, a[u]);
	sta[++top] = u;
}
int main()
{
	scanf("%d", &n);
	vis[n + 1] = true;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == -1) a[i] = n + 1;
		b[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		if (!b[i]) b[i] = n + 1;
	build(1, 1, n + 1);
	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs(i);
	for (int i = n; i >= 1; i--)
		ans[sta[i]] = i;
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}