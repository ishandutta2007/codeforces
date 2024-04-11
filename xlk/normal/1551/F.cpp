#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t, n, m, x, y, md;
vector<int> a[120];
int c[120];
int f[120][120][120];
void dfs(int x, int y, int d)
{
	c[d]++;
	md = max(md, d);
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x, d + 1);
		}
	}
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}
		for (int i = 1; i < n; i++)
		{
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		if (m == 2)
		{
			cout << n * (n - 1) / 2 << endl;
			continue;
		}
		int z = 0;
		for (int i = 1; i <= n; i++)
		{
			memset(f, 0, sizeof f);
			for (int k = 1; k <= n; k++)
			{
				f[k][0][0] = 1;
			}
			for (int j = 0; j < a[i].size(); j++)
			{
				memset(c, 0, sizeof c);
				md = 0;
				dfs(a[i][j], i, 1);
				for (int k = 1; k <= n; k++)
				{
					for (int l = 0; l <= m; l++)
					{
						f[k][j + 1][l] = f[k][j][l];
						if (l > 0)
						{
							f[k][j + 1][l] = (f[k][j + 1][l] + (long long)f[k][j][l - 1] * c[k]) % p;
						}
					}
				}
			}
			for (int k = 1; k <= n; k++)
			{
				z = (z + f[k][a[i].size()][m]) % p;		
			}
		}
		cout << z << endl;
	}
	return 0;
}