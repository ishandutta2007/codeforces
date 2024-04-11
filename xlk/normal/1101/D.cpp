#include <bits/stdc++.h>
using namespace std;
int n, ans;
vector<int> a[200020];
map<int, int> f[200020];
void dfs(int x, int y)
{
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			for (pair<int, int> j: f[x])
			{
				ans = max(ans, j.second + f[i][j.first]);
				f[x][j.first] = max(j.second, f[i][j.first] + 1);
			}
		}
	}
}
int main()
{
	int x, y;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		for (int j = 2; j * j <= x; j++)
		{
			if (x % j == 0)
			{
				f[i][j] = 1;
				ans = 1;
				while (x % j == 0)
				{
					x /= j;
				}
			}
		}
		if (x > 1)
		{
			f[i][x] = 1;
			ans = 1;
		}
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}