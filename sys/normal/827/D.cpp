#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, cnt, dfn_cnt, head[Maxn], dfn[Maxn], fa[Maxn], siz[Maxn], dep[Maxn], son[Maxn], anc[Maxn][21], maxi[Maxn][21], top[Maxn];
bool vis[Maxn];
struct edg
{
	int nxt, to, w;
}edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
}
void dfs1(int u, int F)
{
	anc[u][0] = F;
	fa[u] = F;
	siz[u] = 1;
	dep[u] = dep[F] + 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != F)
		{
			maxi[to][0] = edge[i].w;
			dfs1(to, u);
			siz[u] += siz[to];
			if (siz[u] > siz[son[u]]) son[u] = to;
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
		if (to != fa[u] && to != son[u])
			dfs2(to, to);
	}
}
void init(void)
{
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
		{
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
			maxi[i][j] = max(maxi[i][j - 1], maxi[anc[i][j - 1]][j - 1]);
		}
}
int mini[4 * Maxn];
void insert(int root, int lt, int rt, int L, int R, int val)
{
	if (lt == L && rt == R) mini[root] = min(mini[root], val);
	else
	{
		int mid = (lt + rt) >> 1;
		if (L >= mid) insert(root << 1 | 1, mid, rt, L, R, val);
		else if (R <= mid) insert(root << 1, lt, mid, L, R, val);
		else insert(root << 1, lt, mid, L, mid, val), insert(root << 1 | 1, mid, rt, mid, R, val);
	}
}
int ask(int root, int lt, int rt, int L, int R)
{
	if (lt == L && rt == R) return mini[root];
	else
	{
		int mid = (lt + rt) >> 1;
		if (L >= mid) return min(mini[root], ask(root << 1 | 1, mid, rt, L, R));
		else if (R <= mid) return min(mini[root], ask(root << 1, lt, mid, L, R));
		else return min(mini[root], min(ask(root << 1, lt, mid, L, mid), ask(root << 1 | 1, mid, rt, mid, R)));
	}
}
int lca(int x, int y)
{
	int ans = 0;
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--)
		if ((dep[x] - dep[y]) & (1 << i)) ans = max(ans, maxi[x][i]), x = anc[x][i];
	if (x == y) return ans;
	for (int i = 20; i >= 0; i--)
		if (anc[x][i] != anc[y][i])
		{
			ans = max(ans, max(maxi[x][i], maxi[y][i]));
			x = anc[x][i], y = anc[y][i];
		}
	ans = max(ans, max(maxi[x][0], maxi[y][0]));
	return ans;
}
void work(int x, int y, int w)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		insert(1, 1, n + 1, dfn[top[x]], dfn[x] + 1, w);
		x = fa[top[x]];
	}
	if (dep[x] < dep[y]) swap(x, y); 
	if (x != y) insert(1, 1, n + 1, dfn[y] + 1, dfn[x] + 1, w);
}
struct Edg
{
	int x, y, w, id;
	bool operator < (const Edg &tmp) const
	{
		return w < tmp.w;
	}
}Edge[2 * Maxn];
int Fa[Maxn];
int get_fa(int x)
{
	return x == Fa[x] ? x : Fa[x] = get_fa(Fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	Fa[a] = b;
}
void kruskal(void)
{
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &Edge[i].x, &Edge[i].y, &Edge[i].w), Edge[i].id = i;
	sort(Edge + 1, Edge + 1 + m); 
	for (int i = 1; i <= n; i++)
		Fa[i] = i; 
	for (int i = 1; i <= m; i++)
	{
		if (get_fa(Edge[i].x) != get_fa(Edge[i].y))
		{
			merge(Edge[i].x, Edge[i].y);
			add(Edge[i].x, Edge[i].y, Edge[i].w);
			add(Edge[i].y, Edge[i].x, Edge[i].w);
			vis[i] = true;
		}
	}
}
int ans[Maxn];
int main()
{
	memset(mini, 0x3f, sizeof(mini));
	scanf("%d%d", &n, &m);
	kruskal();
	dfs1(1, 0);
	dfs2(1, 1);
	init();
	for (int i = 1; i <= m; i++)
		if (!vis[i])
			ans[Edge[i].id] = lca(Edge[i].x, Edge[i].y), work(Edge[i].x, Edge[i].y, Edge[i].w);
	for (int i = 1; i <= m; i++)
	{
		if (dep[Edge[i].x] < dep[Edge[i].y]) swap(Edge[i].x, Edge[i].y);
		if (vis[i]) ans[Edge[i].id] = ask(1, 1, n + 1, dfn[Edge[i].x], dfn[Edge[i].x] + 1);
	}
	for (int i = 1; i <= m; i++)
		if (ans[i] == 0x3f3f3f3f) printf("-1 ");
		else printf("%d ", ans[i] - 1);
	return 0;
}