#include "bits/stdc++.h"
using namespace std;

pair<int, int> edge[200005];
int parent[200005];
int color[200005];
vector<int> graph[200005];
int dist[200005];

int getparent(int t)
{
	return t == parent[t] ? t : (parent[t] = getparent(parent[t]));
}

void merge(int a, int b)
{
	parent[getparent(a)] = getparent(b);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) parent[i] = i;
	for (int i = 0; i < n; i++) scanf("%d", &color[i]);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		if (color[a] == color[b]) merge(a, b);
		edge[i] = { a, b };
	}
	for (int i = 1; i < n; i++)
	{
		int pa = getparent(edge[i].first);
		int pb = getparent(edge[i].second);
		if (pa == pb) continue;
		graph[pa].push_back(pb);
		graph[pb].push_back(pa);
	}

	int start = getparent(0);

	memset(dist, -1, sizeof(dist));

	dist[start] = 0;
	queue<int> que;
	que.push(start);
	int last;

	while (que.empty() == false)
	{
		int t = que.front();
		que.pop();

		last = t;

		for (int nxt : graph[t])
		{
			if (dist[nxt] >= 0) continue;
			dist[nxt] = dist[t] + 1;
			que.push(nxt);
		}
	}

	memset(dist, -1, sizeof(dist));

	dist[last] = 0;
	que.push(last);

	while (que.empty() == false)
	{
		int t = que.front();
		que.pop();
		last = t;

		for (int nxt : graph[t])
		{
			if (dist[nxt] >= 0) continue;
			dist[nxt] = dist[t] + 1;
			que.push(nxt);
		}
	}

	printf("%d", (dist[last] + 1) / 2);
}