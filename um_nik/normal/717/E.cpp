#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = 200100;
int n;
vector<int> g[N];
vector<int> sons[N];
bool a[N];
bool allGood[N];
bool used[N];
int par[N];

void dfs1(int v)
{
	used[v] = 1;
	allGood[v] = a[v];
	for (int u : g[v])
	{
		if (used[u]) continue;
		sons[v].push_back(u);
		par[u] = v;
		dfs1(u);
		allGood[v] &= allGood[u];
	}
	return;
}

void dfs2(int v)
{
	for (int u : sons[v])
	{
		if (allGood[u]) continue;
		printf("%d ", u + 1);
		a[u] ^= 1;
		dfs2(u);
		a[v] ^= 1;
		printf("%d ", v + 1);
	}
	if (a[v]) return;
	if (par[v] != -1)
	{
		printf("%d %d ", par[v] + 1, v + 1);
		a[v] ^= 1;
		a[par[v]] ^= 1;
	}
	else
	{
		int u = sons[v][0];
		printf("%d %d %d ", u + 1, v + 1, u + 1);
		a[v] ^= 1;
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if (x == 1)
			a[i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	par[0] = -1;
	dfs1(0);
	printf("1 ");
	if (allGood[0]) return 0;
	dfs2(0);

	return 0;
}