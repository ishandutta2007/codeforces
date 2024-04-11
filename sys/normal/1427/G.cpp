#include <bits/stdc++.h>
using namespace std;

const int Maxn = 40005;
int n, m, c, s, t, ct, cnt, ans, b[Maxn], dis[Maxn], head[Maxn], cur[Maxn], a[205][205], id[205][205];
long long tot;
bool vis[Maxn];
struct edg
{
	int nxt, to, w;
} edge[10 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
	edge[++cnt] = (edg){head[y], x, 0};
	head[y] = cnt;
}
int dfs(int u, int T, int mini)
{
	if (u == T || !mini) return mini;
	int w, used = 0;
	vis[u] = true;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (!vis[to] && edge[i].w)
		{
			w = dfs(to, T, min(mini - used, edge[i].w));
			used += w, edge[i].w -= w, edge[((i - 1) ^ 1) + 1].w += w;
			if (mini == used) return used;
		}
	}
	return used;
}
void dinic(int S = s, int T = t, int W = 0x3f3f3f3f, bool type = false)
{
	int used;
	while (memset(vis, 0, sizeof(bool[ct + 1])), used = dfs(S, T, W)) W -= used, ans += type ? -used : used;
}
int main()
{
	scanf("%d", &n);
	s = ++ct, t = ++ct;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			id[i][j] = ++ct;
			scanf("%d", &a[i][j]);
			if (a[i][j] > 0) b[++m] = a[i][j];
			if (!a[i][j]) c++;
		}
	sort(b + 1, b + 1 + m);
	m = unique(b + 1, b + 1 + m) - b - 1;
	for (int j = 1; j <= n; j++)
		for (int k = 1; k <= n; k++)
		{
			if (a[j][k] == -1) continue;
			if (j != n && a[j + 1][k] != -1) add(id[j][k], id[j + 1][k], 1), add(id[j + 1][k], id[j][k], 1);
			if (k != n && a[j][k + 1] != -1) add(id[j][k], id[j][k + 1], 1), add(id[j][k + 1], id[j][k], 1);
			if (a[j][k] <= 0) continue;
			add(id[j][k], t, 0x3f3f3f3f);
		}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (a[j][k] == b[i])
				{
					int w;
					for (int q = head[id[j][k]]; q; q = edge[q].nxt)
						if (edge[q].to == t)
						{
							w = edge[q].w;
							edge[q].w = edge[((q - 1) ^ 1) + 1].w = 0;
							break;
						}
					dinic(id[j][k], s, 0x3f3f3f3f - w, true);
					add(s, id[j][k], 0x3f3f3f3f);
				}
		dinic();
		tot += ans * (long long) (b[i + 1] - b[i]);
	}
	printf("%lld", tot);
	return 0;
}