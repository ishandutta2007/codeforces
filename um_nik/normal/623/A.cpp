#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 555;
int n;
bool g[N][N];
char ans[N];
bool used[N];
int deg[N];
int a[N];
int sz;

void read()
{
	int m;
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v][u] = g[u][v] = 1;
		deg[v]++;
		deg[u]++;
	}
	return;
}

bool dfs(int v)
{
//	printf("v = %d\n", v);
	used[v] = 1;
	sz++;
	for (int u = 0; u < n; u++)
	{
		if (!g[v][u]) continue;
		if (used[u]) continue;
		a[u] = a[v];
		dfs(u);
	}
	return true;
}

void solve()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		a[i] = -1;
		if (deg[i] == n - 1)
		{
			cnt++;
			used[i] = 1;
			for (int j = 0; j < n; j++)
				g[i][j] = g[j][i] = 0;
		}
	}
	for (int i = 0; i < n; i++)
		deg[i] -= cnt;
	int C = 0;
	bool ok = true;
	for (int i = 0; ok && i < n; i++)
	{
		if (used[i]) continue;
		a[i] = C;
		sz = 0;
		dfs(i);
		for (int j = 0; j < n; j++)
			if (a[j] == C && deg[j] != sz - 1)
				ok = false;
		C++;
	}
//	printf("%d\n", C);
	if (!ok || C > 2)
	{
		printf("No\n");
		return;
	}
	printf("Yes\n");
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
			printf("a");
		else if (a[i] == 1)
			printf("c");
		else
			printf("b");
	}
	printf("\n");
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	solve();

	return 0;
}