#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = (int)1e6;
const int N = 5050;
int n, m;
int dist[N];
int q[N];
int topQ;
int minCycle[N];
vector<int> g[N], rg[N];
bool used[N];
int ord[N];
int ordSz;
int col[N];
int C;
int compSz[N];
bool hasEdgeOutside[N];

void read()
{
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		rg[u].push_back(v);
	}
	return;
}

int findMinCycle(int V)
{
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[V] = 0;
	topQ = 0;
	q[topQ++] = V;
	for (int k = 0; k < topQ; k++)
	{
		int v = q[k];
		for (int u : g[v])
		{
			if (dist[u] <= dist[v] + 1) continue;
			dist[u] = dist[v] + 1;
			q[topQ++] = u;
		}
	}
	int res = INF;
	for (int u : rg[V])
		res = min(res, dist[u] + 1);
	return res;
}

void dfsOrd(int v)
{
	used[v] = 1;
	for (int u : g[v])
		if (!used[u])
			dfsOrd(u);
	ord[ordSz++] = v;
	return;
}

void dfsColor(int v)
{
	col[v] = C;
	for (int u : rg[v])
		if (col[u] == -1)
			dfsColor(u);
	return;
}

void findComps()
{
	for (int v = 0; v < n; v++)
	{
		col[v] = -1;
		if (used[v]) continue;
		dfsOrd(v);
	}
	reverse(ord, ord + ordSz);
	C = 0;
	for (int i = 0; i < n; i++)
	{
		int v = ord[i];
		if (col[v] != -1) continue;
		dfsColor(v);
		C++;
	}
	for (int v = 0; v < n; v++)
	{
		compSz[col[v]]++;
		for (int u : g[v])
			if (col[u] != col[v])
				hasEdgeOutside[col[v]] = 1;
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	for (int v = 0; v < n; v++)
		minCycle[v] = findMinCycle(v);
	findComps();
//	for (int i = 0; i < n; i++)
//		printf("%d ", col[i]);
//	printf("\n");
	int ans = n;
	for (int i = 0; i < C; i++)
	{
		if (hasEdgeOutside[i] || compSz[i] == 1) continue;
		int res = INF;
		for (int v = 0; v < n; v++)
		{
			if (col[v] != i) continue;
			res = min(res, minCycle[v]);
		}
		ans += 1 + res * 998;
	}
	printf("%d\n", ans);

	return 0;
}