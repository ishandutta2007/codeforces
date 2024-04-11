#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = (int)1e9;
const int N = 200200;
int n;
vector<int> g[N];
int col[N];
int dist[N];
int q[N];
int topQ;

void BFS(int v)
{
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[v] = 0;
	topQ = 0;
	q[topQ++] = v;
	for (int k = 0; k < topQ; k++)
	{
		v = q[k];
		for (int u : g[v])
		{
			if (dist[u] != INF) continue;
			dist[u] = dist[v] + (col[v] ^ col[u]);
			q[topQ++] = u;
		}
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &col[i]);
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	BFS(0);
	int v = 0;
	for (int i = 0; i < n; i++)
		if (dist[i] > dist[v])
			v = i;
	BFS(v);
	v = 0;
	for (int i = 0; i < n; i++)
		if (dist[i] > dist[v])
			v = i;
	printf("%d\n", (dist[v] + 1) / 2);

	return 0;
}