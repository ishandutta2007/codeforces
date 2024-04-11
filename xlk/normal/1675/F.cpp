#include <bits/stdc++.h>
using namespace std;
int t, n, m, u, v, x, y, z;
vector<int> a[200020];
int c[200020];
int dfs(int u, int v, int d)
{
	int s = c[u];
	for (int i : a[u])
	{
		if (i != v)
		{
			s += dfs(i, u, d + 1);
		}
	}
	if (s)
	{
		z += 2;
	}
	if (u == y)
	{
		z -= d;
	}
	return s;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			c[i] = 0;
		}
		z = -2;
		scanf("%d%d%d%d", &n, &m, &x, &y);
		c[y] = 1;
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &u);
			c[u] = 1;
		}
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs(x, 0, 0);
		printf("%d\n", z);
	}
	return 0;
}