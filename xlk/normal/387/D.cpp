#include <bits/stdc++.h>
using namespace std;
vector<int> a[520];
int n, m, x, y;
int in[520];
int v[520];
int l[520];
int b[520];
bool dfs(int i)
{
	for (int j: a[i])
	{
		if (!v[j])
		{
			v[j] = true;
			if (l[j] == 0 || dfs(l[j]))
			{
				l[j] = i;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		if (x == y)
		{
			b[x] = 1;
		}
		a[x].push_back(y);
		in[y]++;
	}
	int z = 1e9;
	for (int i = 1; i <= n; i++)
	{
		int t = m + 3 * n - 2 - 2 * (in[i] + a[i].size() - b[i]);
		memset(l, 0, sizeof l);
		for (int j = 1; j <= n; j++)
		{
			memset(v, 0, sizeof v);
			v[i] = true;
			if (j != i && dfs(j))
			{
				t -= 2;
			}
		}
		z = min(z, t);
	}
	printf("%d\n", z);
	return 0;
}