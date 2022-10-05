#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int s, n, m, x[Maxn], y[Maxn], w[Maxn], head[Maxn], cnt, val[Maxn], son[Maxn], anc[Maxn][20], dep[Maxn];
long long ans, sum[Maxn];
struct edg
{
	int nxt, to, spec;
}edge[2 * Maxn];
void add(int x, int y, int spec)
{
	edge[++cnt] = (edg){head[x], y, spec};
	head[x] = cnt;
}
int lca(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 19; i >= 0; i--)
		if (i & (dep[x] - dep[y])) x = anc[x][i];
	if (x == y) return x;
	for (int i = 19; i >= 0; i--)
		if (anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
	return anc[x][0];
}
void dfs(int u)
{
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (!edge[i].spec)
			val[u]++, val[to]++;
	}
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (edge[i].spec && dep[to] > dep[u])
			dfs(to), val[u] += val[to];
	}
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (edge[i].spec && dep[to] > dep[u]) sum[u] = max(sum[to], sum[u]);
	}
	sum[u] += w[u];
}
int fa[Maxn];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	fa[a] = b;
}
void dfs1(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	anc[u][0] = fa;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
			dfs1(to, u);
	}
}
void init(void)
{
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
}
int main()
{
//	freopen("E.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]), fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		if (get_fa(x[i]) != get_fa(y[i]))
			merge(x[i], y[i]), add(x[i], y[i], 1), add(y[i], x[i], 1), x[i] = y[i] = 0;
	}
	scanf("%d", &s);
	dfs1(s, 0);
	val[s] = 1;
	for (int i = 1; i <= m; i++)
		if (x[i]) add(x[i], y[i], 0), add(y[i], x[i], 0);
	init();
	dfs(s);
	long long maxi = 0;
	for (int i = 1; i <= n; i++)
		if (val[i]) ans += w[i];
		else maxi = max(maxi, sum[i]);
	printf("%lld", ans + maxi);
	return 0;
}