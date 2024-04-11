#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, k, ct, p1, p2, las, ans, cnt, a[Maxn], dis1[Maxn], dis2[Maxn], head[Maxn], from[Maxn], b[Maxn];
bool vis[Maxn], vis2[Maxn];
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
void bfs(int dis[], int s)
{
	memset(dis, 0x3f, sizeof(int[n + 1]));
	dis[s] = 0;
	Qu.push(s);
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (dis[u] + 1 < dis[to])
			{
				dis[to] = dis[u] + 1;
				from[to] = u;
				Qu.push(to);
			}
		}
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	bfs(dis1, 1);
	bfs(dis2, n);
	sort(a + 1, a + 1 + k, [](int x, int y){return dis1[x] < dis1[y];});
	for (int i = 2; i <= k; i++)
		ans = max(ans, min(dis1[n], 1 + dis1[a[i - 1]] + dis2[a[i]]));
	printf("%d", ans);
	return 0;
}