#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
	int v, to, cap, flow;

	Edge() : v(), to(), cap(), flow() {}
	Edge(int _v, int _to, int _cap) : v(_v), to(_to), cap(_cap), flow(0) {}
};

const int INF = (int)1e9;
const int N = 250;
const int M = N * N * 2;
int a[N], b[N];
Edge ed[M];
int edSz = 0;
vector<int> g[N];
int S, T;
int n, m;
int sum;

void addEdge(int v, int u, int cap)
{
	g[v].push_back(edSz);
	ed[edSz++] = Edge(v, u, cap);
	g[u].push_back(edSz);
	ed[edSz++] = Edge(u, v, 0);
	return;
}

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n; i++)
		sum += a[i];
	int sum2 = 0;
	for (int i = 0; i < n; i++)
		sum2 += b[i];
	if (sum != sum2)
	{
		printf("NO\n");
		exit(0);
	}
	S = 2 * n;
	T = 2 * n + 1;
	while(m--)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		addEdge(v, n + u, INF);
		addEdge(u, n + v, INF);
	}
	for (int v = 0; v < n; v++)
	{
		addEdge(S, v, a[v]);
		addEdge(n + v, T, b[v]);
		addEdge(v, n + v, INF);
	}
	n = 2 * n + 2;
	return;
}

int dist[N];
int q[N];
int topQ;
bool bfs()
{
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[S] = 0;
	q[0] = S;
	topQ = 1;
	for (int k = 0; k < topQ; k++)
	{
		int v = q[k];
		for (int id : g[v])
		{
			Edge e = ed[id];
			if (e.flow == e.cap) continue;
			int to = e.to;
			if (dist[to] <= dist[v] + 1)
				continue;
			dist[to] = dist[v] + 1;
			q[topQ++] = to;
		}
	}
	return dist[T] != INF;
}

int idx[N];
int dfs(int v, int flow)
{
	if (v == T || flow == 0) return flow;
	int res = 0;
	for (int &i = idx[v]; i < (int)g[v].size(); i++)
	{
		int id = g[v][i];
		Edge e = ed[id];
		int to = e.to;
		if (dist[v] + 1 != dist[to]) continue;
		int df = dfs(to, min(flow, e.cap - e.flow));
		ed[id].flow += df;
		ed[id ^ 1].flow -= df;
		flow -= df;
		res += df;
		if (flow == 0)
			return res;
	}
	return res;
}

int getFlow()
{
	int res = 0;
	while(bfs())
	{
		for (int i = 0; i < n; i++)
			idx[i] = 0;
		res += dfs(S, INF);
	}
	return res;
}

int ans[N][N];
int main()
{
//	freopen("input.txt", "r", stdin);

	read();
	if (sum != getFlow())
	{
		printf("NO\n");
		return 0;
	}
	n = (n - 2) / 2;
	for (int i = 0; i < edSz; i++)
	{
		int v = ed[i].v;
		int u = ed[i].to;
		if (v >= n || u >= 2 * n || u < n) continue;
		u -= n;
		ans[v][u] = ed[i].flow;
	}
	printf("YES\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}

	return 0;
}