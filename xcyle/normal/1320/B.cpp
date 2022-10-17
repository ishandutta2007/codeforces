#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define maxn 200005
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, u, v, len, p[maxn];
vector<int> G[maxn];
int vis[maxn], dis[maxn], cnt[maxn];
struct node
{
	int id, data;
	bool friend operator < (node a, node b)
	{
		return a.data > b.data;
	}
};
priority_queue<node> q;
void dijk(int s)
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = INF;
	}
	dis[s] = 0;
	q.push({s, 0});
	while(!q.empty())
	{
		int u = q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < G[u].size(); i++)
		{
			int V = G[u][i];
			if(dis[V] > dis[u] + 1)
			{
				dis[V] = dis[u] + 1;
				if(!vis[V]) q.push({V, dis[V]});
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		G[v].push_back(u);
	}
	scanf("%d", &len);
	for (int i = 1; i <= len; i++)
	{
		scanf("%d", &p[i]);
	}
	dijk(p[len]);
	for (int i = 1; i <= n; i++)
	{
//		printf("%d ", dis[i]);
		for (int j = 0; j < G[i].size(); j++)
		{
			int V = G[i][j];
			if(dis[V] == dis[i] + 1) cnt[V]++;
		} 
	} 
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i < len; i++)
	{
		if(dis[p[i + 1]] != dis[p[i]] - 1)
		{
			ans1++;
			ans2++;
		}
		else if(cnt[p[i]] != 1)
		{
			ans2++;
		}
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}