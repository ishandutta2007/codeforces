#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define maxn 72
#define maxm 205
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, a, b, u, v, w; 
struct node
{
	int v, w;
};
vector<node> G[maxn];
int cnt, color[maxn];
int tmp = 0;
void dfs(int x)
{
	color[x] = cnt;
	tmp++;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i].v;
		if(color[V] || G[x][i].w != a) continue;
		dfs(V);
	}
}
queue<int> q[2];
int dis[maxn * (1 << 17)], vis[maxn * (1 << 17)];
void dijk()
{
	for (int i = 0; i < maxn * (1 << 17); i++) dis[i] = INF;
	int x = 0;
	if(color[1] != n + 1) x += (1 << (color[1] - 1)) * n;
	dis[x] = 0;
	q[0].push(x);
	while(!q[0].empty() || !q[1].empty())
	{
		int type;
		if(q[0].empty()) type = 1;
		else if(q[1].empty()) type = 0;
		else type = (dis[q[0].front()] < dis[q[1].front()] ? 0 : 1);
		int tmp = q[type].front();
		q[type].pop();
		if(vis[tmp]) continue;
//		printf("%d %d %d\n", tmp / n, tmp % n, dis[tmp]);
		vis[tmp] = 1;
		int i = tmp / n, j = tmp % n + 1;
		for (register int k = 0; k < G[j].size(); k++)
		{
			int V = G[j][k].v;
			if(color[j] == color[V] && G[j][k].w == b) continue;
			if(G[j][k].w == b && color[V] <= n && ((i >> (color[V] - 1)) & 1)) continue;
			int st = i;
			if(G[j][k].w == b && color[V] <= n) st |= (1 << (color[V] - 1));
			st = st * n + V - 1;
			if(dis[st] > dis[tmp] + G[j][k].w)
			{
				dis[st] = dis[tmp] + G[j][k].w;
				if(G[j][k].w == a) q[0].push(st);
				else q[1].push(st);
//				printf("%d %d %d %d %d\n", j, V, i, st, G[j][k].w);
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for (int i = 1; i <= n; i++) 
	{
		if(color[i]) continue;
		cnt++;
		tmp = 0;
		dfs(i);
		if(tmp < 4)
		{
			for (int j = 1; j <= n; j++)
			{
				if(color[j] == cnt) color[j] = n + i;
			}
			cnt--;
		}
	}
//	for (int i = 1; i <= n; i++) printf("%d ", color[i]);
//	printf("\n");
	dijk();
	for (int i = 1; i <= n; i++)
	{
		int ans = INF;
		for (int j = 0; j < (1 << cnt); j++)
		{
			ans = min(ans, dis[j * n + i - 1]);
		}
		printf("%d ", ans);
	}
	return 0;
}