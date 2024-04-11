#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = 300300;
int n;
vector<int> g[N];
int sz[N];
int c[N];
int q;
int par[N];

void dfs(int v, int p)
{
	par[v] = p;
	sz[v] = 1;
	int big = -1;
	for (int u : g[v])
	{
		if (p == u) continue;
		dfs(u, v);
		sz[v] += sz[u];
		if (big == -1 || sz[u] > sz[big])
			big = u;
	}
	if (big == -1)
	{
		c[v] = v;
		return;
	}
	if (sz[v] >= 2 * sz[big])
	{
		c[v] = v;
		return;
	}
	big = c[big];
	while(2 * sz[big] < sz[v])
		big = par[big];
	c[v] = big;
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		g[i].push_back(x);
		g[x].push_back(i);
	}
	dfs(1, -1);
	while(q--)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", c[x]);
	}

	return 0;
}