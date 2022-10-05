#include<bits/stdc++.h>
using namespace std; 
const int N = 210;

typedef struct edge
{
	int next, to;
	bool visited, ori;
};

typedef struct point
{
	int first, degree;
};

point points[N];
edge edges[N * N];
int e = 1;

void addedge(int u, int v,bool ori)
{
	edges[++e].next = points[u].first;
	points[u].first = e;
	edges[e].to = v;
	edges[e].ori = ori;
	edges[++e].next = points[v].first;
	points[v].first = e;
	edges[e].to = u;
	edges[e].ori = ori;
}

void dfs(int i)
{
	for (int j = points[i].first; j; j = edges[j].next)
		if (!edges[j].visited)
		{
			edges[j].visited = edges[j ^ 1].visited = 1;
			if (edges[j].ori)
				printf("%d %d\n", i, edges[j].to);
			dfs(edges[j].to);
		}
}

int main()
{
	int t, n, m, u, v, even;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		memset(edges, 0, sizeof(edges));
		memset(points, 0, sizeof(points));
		even = 0;
		scanf("%d%d", &n, &m);
		for (int j = 1; j <= m; j++)
		{
			scanf("%d%d", &u, &v);
			addedge(u, v, true);
			points[u].degree++;
			points[v].degree++;
		}
		for (int j = 1; j <= n; j++)
			if (!(points[j].degree & 1))
				even++;
		printf("%d\n", even);
		for (int j = 1; j <= n; j++)
			if (points[j].degree & 1)
				addedge(j, n+1, false);
		for (int j = 1; j <= n; j++)
			dfs(j);
	}
	return 0;
}