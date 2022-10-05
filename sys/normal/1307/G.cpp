#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2505;
int n, m, T, cnt, flow, sum, head[Maxn], dis[Maxn], las[Maxn], from[Maxn];
bool vis[Maxn];
vector <pair <int, int> > Ve;
struct edg
{
	int nxt, to, w, c;
} edge[2 * Maxn];
void add(int x, int y, int w, int c)
{
	edge[++cnt] = (edg){head[x], y, w, c};
	head[x] = cnt;
	edge[++cnt] = (edg){head[y], x, 0, -c};
	head[y] = cnt;
}
queue <int> Qu;
bool SPFA(void)
{
	memset(dis, 0x3f, sizeof(int[n + 1]));
	Qu.push(1);
	dis[1] = 0;
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		vis[u] = false;
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (dis[to] > dis[u] + edge[i].c && edge[i].w)
			{
				dis[to] = dis[u] + edge[i].c;
				from[to] = u;
				las[to] = i;
				if (!vis[to]) Qu.push(to), vis[to] = true;
			}
		}
	}
	return dis[n] != 0x3f3f3f3f;
}
void MCMF(void)
{
	while (SPFA())
	{
		flow++;
		sum += dis[n];
		Ve.push_back(make_pair(flow, sum));
		int u = n;
		while (u != 1)
		{
			edge[las[u]].w--, edge[((las[u] - 1) ^ 1) + 1].w++;
			u = from[u];
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
		add(x, y, 1, w);
	}
	MCMF();
	scanf("%d", &T);
	while (T--)
	{
		double ans = 1e18;
		int x;
		scanf("%d", &x);
		for (vector <pair <int, int> > :: iterator it = Ve.begin(); it != Ve.end(); it++)
			ans = min(ans, (it -> second + x) / (double) it -> first);
		printf("%.10lf\n", ans);
	}
	return 0;
}