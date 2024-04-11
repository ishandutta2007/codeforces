#include <bits/stdc++.h>
using namespace std;

const int Maxn = 600005;
int T, n, cnt, head[Maxn], siz[Maxn];
long long G, B;
struct edg
{
	int nxt, to, w;
}edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
}
void dfs(int u, int fa)
{
	siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u);
			siz[u] += siz[to];
			G += (siz[to] & 1) * edge[i].w;
			B += (long long) min(siz[to], n - siz[to]) * edge[i].w;
		}
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		G = B = 0;
		scanf("%d", &n);
		n *= 2;
		cnt = 0;
		memset(head, 0, sizeof(int[n + 1]));
		for (int i = 1; i < n; i++)
		{
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			add(x, y, w);
			add(y, x, w);
		}
		dfs(1, 0);
		printf("%lld %lld\n", G, B);
	}
	return 0;
}