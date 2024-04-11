#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, k, cnt, head[Maxn], dep[Maxn], siz[Maxn];
long long ans;
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u, int fa)
{
	siz[u] = 1;
	dep[u] = dep[fa] + 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
			dfs(to, u), siz[u] += siz[to];
	}
	dep[u] -= siz[u];
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
	dfs(1, 0);
	sort(dep + 1, dep + 1 + n);
	for (int i = n; i >= n - k + 1; i--)
		ans += dep[i];
	printf("%lld", ans);
	return 0;
}