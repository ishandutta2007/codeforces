#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
struct edge
{
	int to, nxt;
	edge(int to = 0, int nxt = -1) : to(to), nxt(nxt) {}
} e[400001];
int n, k, E, head[200001], sz[200001], dep[200001];
bool vis[200001];
void add(int f, int t)
{
	e[E].to = t;
	e[E].nxt = head[f];
	head[f] = E++;
}
void dfs(int u, int fa)
{
	sz[u] = 1;
	dep[u] = dep[fa] + 1;
	for (int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		if (v == fa)
		{
			continue;
		}
		dfs(v, u);
		sz[u] += sz[v];
	}
}
int main()
{
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
	long long ans = 0;
	priority_queue<pair<int, int> > q;
	q.push(make_pair(sz[1] - 1, 1));
	vis[1] = 1;
	k = n - k;
	while (!q.empty() && k)
	{
		ans += q.top().first;
		int u = q.top().second;
		q.pop();
		k--;
		for (int i = head[u]; i != -1; i = e[i].nxt)
		{
			int v = e[i].to;
			if (vis[v])
			{
				continue;
			}
			q.push(make_pair(sz[v] - dep[v], v));
			vis[v] = 1;
		}
	}
	printf("%lld", ans);
	return 0;
}