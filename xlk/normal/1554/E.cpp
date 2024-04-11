#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int t, n, x, y;
vector<int> a[100020];
int c[100020];
int z[100020];
int dfs(int x, int y)
{
	int s = 1;
	for (int i: a[x])
	{
		if (i != y)
		{
			s += dfs(i, x);
		}
	}
	c[s]++;
	return s;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 1; i <= n + 10; i++)
		{
			c[i] = 0;
			a[i].clear();
			z[i] = 0;
		}
		z[1] = 1;
		for (int i = 1; i < n; i++)
		{
			z[1] = z[1] * 2 % p;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		dfs(1, 0);
		for (int i = 2; i < n; i++)
		{
			if ((n - 1) % i == 0)
			{
				int u = 0;
				int g = 0;
				for (int j = 0; j < n; j += i)
				{
					u += c[j] + c[j + 1];
					if (c[j] + c[j + 1])
					{
						g = __gcd(g, j);
					}
				}
				if (u == n && g == i)
				{
					z[i] = 1;
					z[1]--;
				}
			}
		}
		if (z[1] < 0)
		{
			z[1] += p;
		}
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", z[i], i == n ? '\n' : ' ');
		}
	}
	return 0;
}