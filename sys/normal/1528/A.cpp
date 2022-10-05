#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, cnt, l[Maxn], r[Maxn], a[Maxn], head[Maxn];
long long f[Maxn][2];
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
	f[u][0] = f[u][1] = 0;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u);
			f[u][0] += max(f[to][0] + abs(l[to] - l[u]), f[to][1] + abs(r[to] - l[u]));
			f[u][1] += max(f[to][0] + abs(l[to] - r[u]), f[to][1] + abs(r[to] - r[u]));
		}
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cnt = 0;
		memset(head, 0, sizeof(int[n + 1]));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &l[i], &r[i]);
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y), add(y, x);
		}
		dfs(1, 0);
		printf("%lld\n", max(f[1][0], f[1][1]));
	}
	return 0;
}