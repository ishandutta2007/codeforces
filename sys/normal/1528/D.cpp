#include <bits/stdc++.h>
using namespace std;

const int Maxn = 605;
int n, m, dis[Maxn][Maxn];
bool vis[Maxn];
vector <pair <int, int> > Ve[Maxn];
void dijkstra(int s, int d[])
{
	memset(d, 0x3f, sizeof(int[n + 2]));
	d[s] = 0;
	memset(vis, 0, sizeof(bool[n + 2]));
	for (int i = 1; i <= n + 1; i++)
	{
		int u = 0;
		for (int j = 1; j <= n + 1; j++)
			if (d[j] < d[u] && !vis[j]) u = j;
		if (vis[u]) return ;
		vis[u] = true;
		if (u != s)
		{
			int to = (u == n + 1 ? s % n + 1 : u % n + 1);
			if (to == s)
				to = n + 1;
			d[to] = min(d[to], d[u] + 1);
		}
		for (auto now : Ve[u])
		{
			int to = (n + now.first + d[u] - 1) % n + 1;
			if (to == s) to = n + 1;
			d[to] = min(d[to], d[u] + now.second);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		x++, y++;
		Ve[x].push_back(make_pair(y, w));
	}
	for (int i = 1; i <= n; i++)
		dijkstra(i, dis[i]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", dis[i][j]);
		puts("");
	}
	return 0;
}