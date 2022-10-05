#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, k, cnt, ans1, ans2, x[Maxn], y[Maxn], p[Maxn], head[Maxn], dis[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
queue <int> Qu;
void bfs()
{
	Qu.push(p[k]);
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (!dis[to] && to != p[k])
			{
				dis[to] = dis[u] + 1;
				Qu.push(to);
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		add(y[i], x[i]);
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
		scanf("%d", &p[i]);
	bfs();
	memset(head, 0, sizeof(head));
	cnt = 0;
	for (int i = 1; i <= m; i++)
		add(x[i], y[i]);
	for (int u = 1; u < k; u++)
	{
		if (dis[p[u + 1]] + 1 != dis[p[u]]) ans1++;
		for (int i = head[p[u]]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (to == p[u + 1]) continue;
			if (dis[to] + 1 == dis[p[u]])
			{
				ans2++;
				break;
			}
		}
	}
	printf("%d %d", ans1, ans2);
	return 0;
}