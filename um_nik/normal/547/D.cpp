#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const int N = 200100;
const int V = 2 * N;
vector<pii> g[V];
int deg[V];
bool ans[N];
int n, nn;
bool usedEdge[V];

void dfs(int v)
{
	while((int)g[v].size() > 0)
	{
		pii e = g[v].back();
		g[v].pop_back();
		int eid = e.Y;
		if (usedEdge[eid]) continue;
		usedEdge[eid] = true;
		if (eid < n)
			ans[eid] = v >= N;
		dfs(e.X);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int v = x;
		int u = N + y;
		g[v].push_back(mp(u, i));
		g[u].push_back(mp(v, i));
		deg[v]++;
		deg[u]++;
	}
	nn = n;
	int lst = -1;
	for (int v = 0; v < V; v++)
	{
		if (deg[v] % 2 == 0) continue;
		if (lst == -1)
		{
			lst = v;
			continue;
		}
		int u = lst;
		g[v].push_back(mp(u, nn));
		g[u].push_back(mp(v, nn));
		nn++;
		lst = -1;
	}
	if (lst != -1) throw;

	for (int v = 0; v < V; v++)
	{
		if ((int)g[v].size() == 0) continue;
		dfs(v);
	}
	for (int i = 0; i < n; i++)
		printf("%c", (ans[i] ? 'r' : 'b'));
	printf("\n");

	return 0;
}