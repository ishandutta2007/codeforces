#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, cnt, dfn_cnt, fa[Maxn], siz[Maxn], bel[Maxn], son[Maxn], dfn[Maxn], top[Maxn], dep[Maxn], ans[Maxn], head[Maxn];
struct Message
{
	int s, t, id;
	bool operator < (const Message &tmp) const
	{
		return make_pair(t + dep[s], s) < make_pair(tmp.t + dep[tmp.s], tmp.s);
	}
} M[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs1(int u, int f)
{
	siz[u] = 1;
	dep[u] = dep[f] + 1;
	fa[u] = f;
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
	top[u] = tp;
	dfn[u] = ++dfn_cnt, bel[dfn_cnt] = u;
	if (son[u]) dfs2(son[u], tp);
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa[u] && to != son[u])
			dfs2(to, to);
	}
}
struct Tree
{
	int lt, rt, maxi, tag;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, 0, -0x3f3f3f3f};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid), build(root << 1 | 1, mid, rt);
	}
}
void pushdown(int root)
{
	if (tree[root].tag != -0x3f3f3f3f)
	{
		tree[root << 1].tag = max(tree[root << 1].tag, tree[root].tag);
		tree[root << 1].maxi = max(tree[root << 1].maxi, tree[root].tag + 2 * (tree[root << 1].rt - 1));
		tree[root << 1 | 1].tag = max(tree[root << 1 | 1].tag, tree[root].tag);
		tree[root << 1 | 1].maxi = max(tree[root << 1 | 1].maxi, tree[root].tag + 2 * (tree[root << 1 | 1].rt - 1));
		tree[root].tag = -0x3f3f3f3f;
	}
}
void modify(int root, int lt, int rt, int val)
{
	if (tree[root].lt == lt && tree[root].rt == rt)
		tree[root].maxi = max(tree[root].maxi, val + 2 * (rt - 1)), tree[root].tag = max(tree[root].tag, val);
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) modify(root << 1 | 1, lt, rt, val);
		else if (rt <= mid) modify(root << 1, lt, rt, val);
		else modify(root << 1, lt, mid, val), modify(root << 1 | 1, mid, rt, val);
		tree[root].maxi = max(tree[root << 1].maxi, tree[root << 1 | 1].maxi);
	}
}
int work(int root, int lt, int rt, int val)
{
	if (tree[root].maxi < val) return 0;
	if (tree[root].lt + 1 == tree[root].rt)
		return tree[root].lt;
	else if (tree[root].lt == lt && tree[root].rt == rt)
	{
		pushdown(root);
		int mid = (lt + rt) >> 1;
		if (tree[root << 1 | 1].maxi >= val) return work(root << 1 | 1, mid, rt, val);
		return work(root << 1, lt, mid, val);
	}
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) return work(root << 1 | 1, lt, rt, val);
		else if (rt <= mid) return work(root << 1, lt, rt, val);
		else return max(work(root << 1, lt, mid, val), work(root << 1 | 1, mid, rt, val));
	}
}
int work(int s, int t)
{
	int pos, T = t + 2 * (dep[s] - 1), res = s;
	while (s)
	{
		if ((pos = bel[work(1, dfn[top[s]], dfn[s] + 1, dep[res] + t + 1)]))
		{
			T = t + 2 * (dep[res] - dep[pos]);
			break;
		}
		s = fa[top[s]];
	}
	if (!pos) pos = 1;
	s = res;
	while (true)
	{
		if (top[s] == top[pos])
		{
			modify(1, dfn[pos], dfn[s] + 1, T - dep[res] + 2 * (dep[s] - dfn[s]));
			break;
		}
		modify(1, dfn[top[s]], dfn[s] + 1, T - dep[res] + 2 * (dep[s] - dfn[s]));	
		s = fa[top[s]];
	}
	return T;
}
int main()
{
	scanf("%d%d", &n, &m);
	n++;
	build(1, 1, n + 1);
	for (int i = 2; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		x++;
		if (x) add(i, x), add(x, i);
	}
	dfs1(1, 0), dfs2(1, 1);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &M[i].s, &M[i].t), M[i].s++, M[i].id = i;
	sort(M + 1, M + 1 + m);
	for (int i = 1; i <= m; i++)
		ans[M[i].id] = work(M[i].s, M[i].t);
	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	return 0;
}