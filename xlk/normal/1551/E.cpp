#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int a[2020];
int f[2020][2020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				f[i][j] = f[i - 1][j] + (a[i] == i - j);
				if (j > 0)
				{
					f[i][j] = max(f[i][j], f[i - 1][j - 1]);				
				}
			}
		}
		int z = -1;
		for (int j = 0; j <= n; j++)
		{
			if (f[n][j] >= k)
			{
				z = j;
				break;
			}
		}
		cout << z << endl;
	}
	return 0;
}