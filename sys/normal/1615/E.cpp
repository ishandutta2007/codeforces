#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, k, cnt, fa[Maxn], head[Maxn], maxdep[Maxn], siz[Maxn], son[Maxn], ord[Maxn];
long long ans = -0x3f3f3f3f3f3f3f3fLL;
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs1(int u, int fa)
{
	maxdep[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs1(to, u);
			maxdep[u] = max(maxdep[to] + 1, maxdep[u]);
			if (maxdep[to] > maxdep[son[u]]) son[u] = to;
		}
	}
}
void dfs2(int u, int tp, int fa)
{
	siz[tp]++;
	if (son[u]) dfs2(son[u], tp, u);
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa && to != son[u])
			dfs2(to, to, u);
	}
}
long long cal(int x, int y)
{
	int b = min(y, n / 2);
	return 1LL * (n - x - b) * (x - b);
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs1(1, 0), dfs2(1, 1, 0);
	for (int i = 1; i <= n; i++)
		ord[i] = i;
	sort(ord + 1, ord + 1 + n, [](int x, int y){return siz[x] > siz[y];});
	int tot = 0;
	for (int i = 0; i <= k; i++)
	{
		tot += siz[ord[i]];
		ans = max(ans, cal(i, n - tot));
	}
	printf("%lld", ans);
	return 0;
}