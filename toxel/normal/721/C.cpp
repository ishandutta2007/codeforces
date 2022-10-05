#include<bits/stdc++.h>
using namespace std;
const int N = 5010;

struct point
{
	int first, dp[N], pre, visited;
};

struct edge
{
	int to, next, time;
};

int e = 0, n, m, T;
point points[N];
edge edges[N];
vector <int> v;

void addedge(int u, int v, int t)
{
	edges[++e].next = points[u].first;
	edges[e].to = v;
	edges[e].time = t;
	points[u].first = e;
}

void dfs(int i)
{
	points[i].visited = true;
	for (int j = points[i].first; j; j = edges[j].next)
	{
		if (!points[edges[j].to].visited)
			dfs(edges[j].to);
		for (int k = 1; k <= 5000; k++)
			if (~points[edges[j].to].dp[k - 1] && points[edges[j].to].dp[k - 1] + edges[j].time <= T)
			{
				if (~points[i].dp[k])
					points[i].dp[k] = min(points[i].dp[k], points[edges[j].to].dp[k - 1] + edges[j].time);
				else
					points[i].dp[k] = points[edges[j].to].dp[k - 1] + edges[j].time;
			}
	}
}

void dfs1(int i, int length, int time)
{
	v.push_back(i);
	for (int j = points[i].first; j; j = edges[j].next)
	{		
		time += edges[j].time;
		if (~points[edges[j].to].dp[length - 1] && points[edges[j].to].dp[length - 1] + time <= T)
		{
			dfs1(edges[j].to, length - 1, time);
			break;
		}
		time -= edges[j].time;
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &T);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			points[i].dp[j] = -1;
	points[1].dp[1] = 0;
	for (int i = 0; i < m; i++)
	{
		int u, v, t;
		scanf("%d%d%d", &u, &v, &t);
		addedge(v, u, t);
	}
	dfs(n);
	int j;
	for (j = n; j >= 0; j--)
		if (~points[n].dp[j])
			break;
	dfs1(n, j, 0);
	printf("%d\n", v.size());
	for (int i = v.size() - 1; i >= 0; i--)
		printf("%d ", v[i]);
	return 0;
}