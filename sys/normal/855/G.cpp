#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, q, cnt, fa[Maxn], F[Maxn], head[Maxn], dep[Maxn];
long long ans, siz[Maxn], siz2[Maxn], val[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u, int f)
{
	siz2[u] = siz[u] = 1;
	dep[u] = dep[f] + 1;
	F[u] = f;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != f) dfs(to, u), siz2[u] += siz2[to], val[u] += siz2[to] * (siz2[to] - 1);
	}
}
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	ans -= siz[x] * (siz[x] - 1) * (siz[x] - 2) + 2 * siz[x] * (siz[x] - 1) * (n - siz[x]) + siz[x] * ((n - siz[x]) * (n - siz[x] - 1) - val[x] - (n - siz2[x]) * (n - siz2[x] - 1));
	ans -= siz[y] * (siz[y] - 1) * (siz[y] - 2) + 2 * siz[y] * (siz[y] - 1) * (n - siz[y]) + siz[y] * ((n - siz[y]) * (n - siz[y] - 1) - val[y] - (n - siz2[y]) * (n - siz2[y] - 1));
	siz[x] += siz[y];
	val[x] += val[y] - siz2[y] * (siz2[y] - 1);
	fa[y] = x;
	ans += siz[x] * (siz[x] - 1) * (siz[x] - 2) + 2 * siz[x] * (siz[x] - 1) * (n - siz[x]) + siz[x] * ((n - siz[x]) * (n - siz[x] - 1) - val[x] - (n - siz2[x]) * (n - siz2[x] - 1));
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		ans += ((n - 1) * (n - 2LL) - val[i] - (n - siz2[i]) * (n - siz2[i] - 1)), fa[i] = i;
	printf("%lld\n", ans);
	scanf("%d", &q);
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x = get_fa(x), y = get_fa(y);
		while (x != y)
		{
			if (dep[x] < dep[y]) swap(x, y);
			merge(get_fa(F[x]), x);
			x = get_fa(x);
		}
		printf("%lld\n", ans);
	}
	return 0;
}