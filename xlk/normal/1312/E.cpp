#include <bits/stdc++.h>
using namespace std;
int n, x;
int f[520][520];
int g[520];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		f[i][i] = x;
	}
	for (int i = n; i > 0; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = i; k < j; k++)
			{
				if (f[i][k] > 0 && f[k + 1][j] > 0 && f[i][k] == f[k+1][j])
				{
					f[i][j] = f[i][k] + 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		g[i] = i;
		for (int j = 1; j <= i; j++)
		{
			if (f[j][i] > 0)
			{
				g[i] = min(g[i], g[j - 1] + 1);
			}
		}
	}
	cout << g[n] << endl;
	return 0;
}