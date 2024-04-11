//luogu sb!!!
#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
int n, m, cnt, top, bcc, dfn_cnt, dep[Maxn], siz[Maxn], s[Maxn], bel[Maxn], x[Maxn * Maxn], y[Maxn * Maxn], sta[Maxn], dfn[Maxn], low[Maxn], head[Maxn];
long long ans, maxi, tot;
bool vis[Maxn];
vector <int> G[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void Tarjan(int u, int fa)
{
	dfn[u] = low[u] = ++dfn_cnt;
	sta[++top] = u;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to == fa) continue;
		if (!dfn[to])
		{
			Tarjan(to, u);
			low[u] = min(low[u], low[to]);
		}
		else low[u] = min(low[u], dfn[to]);
	}
	if (low[u] == dfn[u])
	{
		bcc++;
		int x;
		do
		{
			x = sta[top--];
			bel[x] = bcc;
			s[bcc]++;
		} while (x != u);
	}
}
void dfs(int u, int fa)
{
	tot += dep[u] * s[u];
	siz[u] = s[u];
	for (auto to : G[u])
		if (to != fa) dep[to] = dep[u] + s[to], dfs(to, u), siz[u] += siz[to];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		add(x[i], y[i]), add(y[i], x[i]);
	}
	Tarjan(1, 0);
	for (int i = 1; i <= m; i++)
		if (bel[x[i]] != bel[y[i]])
			G[bel[x[i]]].push_back(bel[y[i]]), G[bel[y[i]]].push_back(bel[x[i]]);
	for (int i = 1; i <= bcc; i++)
	{
		tot = 0;
		dep[i] = s[i];
		dfs(i, 0);
		memset(vis, false, sizeof(bool[n + 1]));
		vis[0] = true;
		for (auto to : G[i])
			for (int j = n; j >= siz[to]; j--)
				vis[j] |= vis[j - siz[to]];
		for (int j = (n - s[i]) / 2; j <= n - s[i]; j++)
			if (vis[j]) maxi = max(maxi, tot + j * (long long) (n - j - s[i]));
	}
	printf("%lld", maxi);
	return 0;
}