#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 400200;
int n;
vector<int> g[N];
bool ans[N];
int sz[N];

void dfs(int v)
{
	sz[v] = 1;
	for (int u : g[v])
	{
		if (sz[u] != -1) continue;
		dfs(u);
		sz[v] += sz[u];
	}
	return;
}

void dfsSolve(int v, int s)
{
	ans[v] = (2 * (n - sz[v] - s)) <= n;
	for (int u : g[v])
		if (sz[u] < sz[v])
			dfsSolve(u, s);
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 0; i < n; i++)
		sz[i] = -1;
	dfs(0);
	int v = 0;
	while(true)
	{
		int w = -1;
		for (int u : g[v])
		{
			if (sz[u] > sz[v]) continue;
			if (2 * sz[u] >= n)
			{
				w = u;
				break;
			}
		}
		if (w == -1) break;
		v = w;
	}
	if (2 * sz[v] == n)
	{
		for (int i = 0; i < n; i++)
			printf("1 ");
		printf("\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
		sz[i] = -1;
	dfs(v);
	ans[v] = 1;
	int m1 = -1, m2 = -1;
	for (int u : g[v])
	{
		if (sz[u] > m1)
		{
			m2 = m1;
			m1 = sz[u];
		}
		else if (sz[u] > m2)
			m2 = sz[u];
	}
	for (int u : g[v])
	{
		if (sz[u] == m1)
			dfsSolve(u, m2);
		else
			dfsSolve(u, m1);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", (int)ans[i]);
	printf("\n");

	return 0;
}