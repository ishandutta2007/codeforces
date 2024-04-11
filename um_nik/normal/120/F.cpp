#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = 111;
int t;
int n;
vector<int> g[N];
int ans;

const int INF = 10000;
int dist[N];
int q[N];
int qSz;

void bfs(int v)
{
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[v] = 0;
	qSz = 1;
	q[0] = v;
	for (int k = 0; k < qSz; k++)
	{
		v = q[k];
		for (int i = 0; i < (int)g[v].size(); i++)
		{
			int u = g[v][i];
			if (dist[u] <= dist[v] + 1) continue;
			dist[u] = dist[v] + 1;
			q[qSz++] = u;
		}
	}
	return;
}

int solve()
{
	for (int i = 0; i < N; i++)
		g[i].clear();
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	bfs(0);
	int v = 0;
	for (int i = 0; i < n; i++)
		if (dist[i] > dist[v])
			v = i;
	bfs(v);
	int x = 0;
	for (int i = 0; i < n; i++)
		x = max(x, dist[i]);
	return x;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ans = 0;
	scanf("%d", &t);
	while(t--)
		ans += solve();
	printf("%d\n", ans);

	return 0;
}