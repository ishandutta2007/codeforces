#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, cnt, tot, w[Maxn], fa[Maxn], head[Maxn], siz[Maxn], dfn[Maxn], dep[Maxn], anc[Maxn][21], maxi[Maxn][21];
bool vis[Maxn];
long long ans;
vector <int> G[Maxn];
struct edg
{
	int nxt, to, w;
} edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
}
struct Edg
{
	int x, y, w, id;
	bool operator < (const Edg &tmp) const
	{
		return w < tmp.w;
	}
} E[2 * Maxn];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	fa[a] = b;
}
void kruskal(void)
{
	sort(E + 1, E + 1 + n);
	for (int i = 1; i <= n; i++)
		if (get_fa(E[i].x) != get_fa(E[i].y))
			merge(E[i].x, E[i].y), ans += E[i].w, add(E[i].x, E[i].y, E[i].w), add(E[i].y, E[i].x, E[i].w);
}
void init_dfs(int u, int fa)
{
	if (u != 1 && G[u].size() == 1) siz[u] = 1, dfn[u] = ++dfn[0];
	else dfn[u] = 0x3f3f3f3f;
	for (auto to : G[u])
		if (to != fa)
			init_dfs(to, u), siz[u] += siz[to], dfn[u] = min(dfn[u], dfn[to]);
}
void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	anc[u][0] = fa;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
			maxi[to][0] = edge[i].w, dfs(to, u);
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
int get_maxi(int x, int y)
{
	int ans = 0;
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 19; i >= 0; i--)
		if ((dep[x] - dep[y]) & (1 << i)) ans = max(ans, maxi[x][i]), x = anc[x][i];
	if (x == y) return ans;
	for (int i = 19; i >= 0; i--)
		if (anc[x][i] != anc[y][i]) ans = max(ans, max(maxi[x][i], maxi[y][i])), x = anc[x][i], y = anc[y][i];
	return max(ans, max(maxi[x][0], maxi[y][0]));
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]), fa[i] = i;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	init_dfs(1, 0);
	for (int i = 1; i <= n; i++)
		E[i] = (Edg){dfn[i], dfn[i] + siz[i], w[i], i};
	kruskal();
	dfs(1, 0), init();
	for (int i = 1; i <= n; i++)
		if (get_maxi(dfn[i], dfn[i] + siz[i]) == w[i]) vis[i] = true, tot++;
	printf("%lld %d\n", ans, tot);
	for (int i = 1; i <= n; i++)
		if (vis[i]) printf("%d ", i);
	return 0;
}