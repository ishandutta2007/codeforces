#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[19];
long long f[1 << 19][19];
long long z;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		f[1 << i][i] = 1;
	}
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				for (int k: a[j])
				{
					if ((i & -i) == 1 << k)
					{
						z += f[i][j];
					}
					if ((i & -i) < 1 << k && ~i >> k & 1)
					{
						f[i | 1 << k][k] += f[i][j];
					}
				}
			}
		}
	}
	printf("%lld\n", (z - m) / 2);
	return 0;
}