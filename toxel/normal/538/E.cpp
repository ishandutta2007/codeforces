#include<bits/stdc++.h>
using namespace std;
const int N = 200020;

struct point
{
	int first, maxi, mini, size;
};

struct edge
{
	int next, to;
};

int e = 0, n;
point points[N];
edge edges[N];

void addedge(int u, int v)
{
	edges[++e].next = points[u].first;
	edges[e].to = v;
	points[u].first = e;
}

void dfs(int i)
{
	if (points[i].first == 0)
	{
		points[i].size = points[i].maxi = points[i].mini = 1;
		return;
	}
	points[i].maxi = 1000000000;
	for (int j = points[i].first; j; j = edges[j].next)
	{
		int x = edges[j].to;
		dfs(x);
		points[i].size += points[x].size;
		points[i].mini += points[x].maxi - 1;
		points[i].maxi = min(points[i].maxi, points[x].size - points[x].mini);
	}
	points[i].maxi = points[i].size - points[i].maxi;
	points[i].mini += 1;
}

void dfs1(int i)
{
	if (points[i].first == 0)
		return;
	points[i].mini = 1000000000;
	points[i].maxi = 0;
	for (int j = points[i].first; j; j = edges[j].next)
	{
		int x = edges[j].to;
		dfs1(x);
		points[i].mini = min(points[i].mini, points[x].maxi);
		points[i].maxi += points[x].mini;
	}
}

int main()
{
	scanf("%d", &n);
	if (n == 1)
		return printf("1 1\n"), 0;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dfs(1);
	printf("%d ", points[1].maxi);
	dfs1(1);
	printf("%d\n", points[1].maxi);
	return 0;
}