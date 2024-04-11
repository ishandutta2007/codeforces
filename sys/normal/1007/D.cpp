#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
int n, m, ct, cnt, dfn_cnt, scc_ct, tp, head[Maxn], sta[40 * Maxn], dep[Maxn], fa[Maxn], siz[Maxn], son[Maxn], top[Maxn], bel[40 * Maxn], dfn[40 * Maxn], low[40 * Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void tree_add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs1(int u, int f)
{
	fa[u] = f;
	dep[u] = dep[f] + 1;
	siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != f)
		{
			dfs1(to, u);
			siz[u] += siz[to];
			if (siz[to] > siz[son[u]]) son[u] = to;
		}
	}
}
void dfs2(int u, int tp)
{
	dfn[u] = ++dfn_cnt;
	top[u] = tp;
	if (son[u]) dfs2(son[u], tp);
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != son[u] && to != fa[u])
			dfs2(to, to);
	}
}
vector <int> G[40 * Maxn];
void add(int x, int y)
{
	G[x].push_back(y);
	G[y ^ 1].push_back(x ^ 1);
}
struct Tree
{
	int lt, rt;
	vector <int> Ve;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
	}
}
void modify(int root, int lt, int rt, int id)
{
	if (lt == rt) return ;
	if (lt == tree[root].lt && rt == tree[root].rt)
		tree[root].Ve.push_back(id);
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) modify(root << 1 | 1, lt, rt, id);
		else if (rt <= mid) modify(root << 1, lt, rt, id);
		else modify(root << 1, lt, mid, id), modify(root << 1 | 1, mid, rt, id);
	}
}
void work(int x, int y, int w)
{
	while (x != y)
	{
		if (top[x] == top[y])
		{
			if (dep[x] < dep[y]) swap(x, y);
			modify(1, dfn[y] + 1, dfn[x] + 1, w);
			break;
		}
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		modify(1, dfn[top[x]], dfn[x] + 1, w);
		x = fa[top[x]];
	}
}
void dfs(int root, int las)
{
	int siz = tree[root].Ve.size();
	int S = ++ct, T = (ct += siz);
	if (siz) add((T - 1) << 1, T << 1);
	else if (las) add(las << 1, T << 1);
	for (int i = 0; i < siz; i++)
	{
		int now = tree[root].Ve[i];
		add(now, (S + i) << 1);
		if (i) add((S + i - 1) << 1, (S + i) << 1), add((S + i - 1) << 1, now ^ 1);
		else if (las) add(las << 1, S << 1), add(las << 1, now ^ 1);
	}
	if (tree[root].lt + 1 != tree[root].rt)
		dfs(root << 1, T), dfs(root << 1 | 1, T);
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++dfn_cnt;
	sta[++tp] = u;
	for (vector <int> :: iterator it = G[u].begin(); it != G[u].end(); it++)
	{
		int to = *it;
		if (!low[to])
		{
			tarjan(to);
			low[u] = min(low[u], low[to]);
		}
		else if (!bel[to]) low[u] = min(low[u], dfn[to]);
	}
	if (low[u] == dfn[u])
	{
		bel[u] = ++scc_ct;
		while (sta[tp] != u) bel[sta[tp]] = scc_ct, tp--;
		tp--;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		tree_add(x, y), tree_add(y, x);
	}
	dfs1(1, 0), dfs2(1, 1);
	build(1, 1, n + 1);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		work(x, y, i << 1);
		scanf("%d%d", &x, &y);
		work(x, y, i << 1 | 1);
	}
	ct = m;
	dfs(1, 0);
	dfn_cnt = 0;
	for (int i = 0; i < (ct << 1); i++)
		if (!low[i]) tarjan(i);
	for (int i = 0; i < m; i++)
		if (bel[i << 1] == bel[i << 1 | 1])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	for (int i = 0; i < m; i++)
		printf("%d\n", 1 + (bel[i << 1] > bel[i << 1 | 1]));
	return 0;
}