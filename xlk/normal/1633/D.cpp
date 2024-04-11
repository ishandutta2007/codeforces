#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int g[1020];
int b[1020];
int c[1020];
int f[12020];
int main()
{
	for (int i = 1; i < 1010; i++)
	{
		g[i] = i - 1;
	}
	int z = 0;
	for (int i = 1; i < 1010; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i + i / j < 1010)
			{
				g[i + i / j] = min(g[i + i / j], g[i] + 1);
			}
		}
		z = max(z, g[i]);
	}
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> k;
		k = min(k, 12 * n);
		for (int i = 0; i <= k; i++)
		{
			f[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> c[i];
			for (int j = k; j >= g[b[i]]; j--)
			{
				f[j] = max(f[j], f[j - g[b[i]]] + c[i]);
			}
		}
		cout << f[k] << endl;
	}
	return 0;
}