#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m;
map <pair <int, int>, int> Ma;
struct edg
{
	int nxt, to, w;
};
namespace Flow
{
	int s, t, ct, cnt, ans, head[Maxn], dis[Maxn], cur[Maxn];
	edg edge[40 * Maxn];
	void add(int x, int y, int w)
	{
		edge[++cnt] = (edg){head[x], y, w};
		head[x] = cnt;
		edge[++cnt] = (edg){head[y], x, 0};
		head[y] = cnt;
	}
	queue <int> Qu;
	bool bfs(void)
	{
		memset(dis, 0, sizeof(int[ct + 1]));
		Qu.push(s);
		while (!Qu.empty())
		{
			int u = Qu.front();
			Qu.pop();
			for (int i = head[u]; i; i = edge[i].nxt)
			{
				int to = edge[i].to;
				if (edge[i].w && to != s && !dis[to])
					dis[to] = dis[u] + 1, Qu.push(to);
			}
		}
		return dis[t];
	}
	int dfs(int u, int mini)
	{
		if (u == t || !mini) return mini;
		int w, used = 0;
		for (int & i = cur[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (dis[to] == dis[u] + 1 && edge[i].w)
			{
				w = dfs(to, min(mini - used, edge[i].w));
				used += w, edge[i].w -= w, edge[((i - 1) ^ 1) + 1].w += w;
				if (used == mini) return used;
			}
		}
		return used;
	}
	void dinic(void)
	{
		while (bfs())
		{
			memcpy(cur, head, sizeof(int[ct + 1]));
			ans += dfs(s, 0x3f3f3f3f);
		}
	}
}
namespace Tree
{
	int cnt, dfn_cnt, bel[Maxn], head[Maxn], dfn[Maxn], siz[Maxn], dep[Maxn], fa[Maxn], son[Maxn], top[Maxn];
	edg edge[2 * Maxn];
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
		dfn[u] = ++dfn_cnt;
		bel[dfn_cnt] = u;
		top[u] = tp;
		if (son[u]) dfs2(son[u], tp);
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (to != son[u] && to != fa[u])
				dfs2(to, to);
		}
	}
	struct Tree
	{
		int lt, rt, id;
	} tree[4 * Maxn];
	void build(int root, int lt, int rt)
	{
		tree[root] = (Tree){lt, rt, ++Flow::ct};
		if (lt + 1 == rt)
		{
			if (lt != 1) Flow::add(tree[root].id, Flow::t, 1);
		}
		else
		{
			int mid = (lt + rt) >> 1;
			build(root << 1, lt, mid);
			build(root << 1 | 1, mid, rt);
			Flow::add(tree[root].id, tree[root << 1].id, 0x3f3f3f3f), Flow::add(tree[root].id, tree[root << 1 | 1].id, 0x3f3f3f3f);
		}
	}
	void link(int root, int lt, int rt, int id)
	{
		if (tree[root].lt == lt && tree[root].rt == rt)
			Flow::add(id, tree[root].id, 0x3f3f3f3f);
		else
		{
			int mid = (tree[root].lt + tree[root].rt) >> 1;
			if (lt >= mid) link(root << 1 | 1, lt, rt, id);
			else if (rt <= mid) link(root << 1, lt, rt, id);
			else link(root << 1, lt, mid, id), link(root << 1 | 1, mid, rt, id);
		}
	}
	void work(int x, int y, int id)
	{
		while (x != y)
		{
			if (top[x] == top[y])
			{
				if (dep[x] < dep[y]) swap(x, y);
				link(1, dfn[y] + 1, dfn[x] + 1, id);
				break;
			}
			else
			{
				if (dep[top[x]] < dep[top[y]]) swap(x, y);
				link(1, dfn[top[x]], dfn[x] + 1, id);
				x = fa[top[x]];
			}
		}
	}
}
bool vis[Maxn];
void dfs(int u)
{
	vis[u] = true;
	for (int i = Flow::head[u]; i; i = Flow::edge[i].nxt)
	{
		int to = Flow::edge[i].to;
		if (Flow::edge[i].w && !vis[to]) dfs(to);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	Flow::s = ++Flow::ct, Flow::t = ++Flow::ct;
	for (int i = 1; i <= m; i++)
	{
		++Flow::ct;
		Flow::add(Flow::s, Flow::ct, 1);
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		Tree::add(x, y), Tree::add(y, x);
		Ma[make_pair(x, y)] = Ma[make_pair(y, x)] = i;
	}
	Tree::dfs1(1, 0), Tree::dfs2(1, 1), Tree::build(1, 1, n + 1);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		Tree::work(x, y, i + 2);
	}
	Flow::dinic();
	printf("%d\n", Flow::ans);
	dfs(Flow::s);
	int cnt1 = 0;
	for (int i = Flow::head[Flow::s]; i; i = Flow::edge[i].nxt)
		if (!vis[Flow::edge[i].to])
			cnt1++;
	printf("%d ", cnt1);
	for (int i = Flow::head[Flow::s]; i; i = Flow::edge[i].nxt)
		if (!vis[Flow::edge[i].to])
			printf("%d ", Flow::edge[i].to - 2);
	printf("\n%d ", Flow::ans - cnt1);
	int tmp = n;
	for (int i = Flow::head[Flow::t]; i; i = Flow::edge[i].nxt)
	{
		if (vis[Flow::edge[i].to])
			printf("%d ", Ma[make_pair(Tree::bel[tmp], Tree::fa[Tree::bel[tmp]])]);
		tmp--;
	}
	return 0;
}