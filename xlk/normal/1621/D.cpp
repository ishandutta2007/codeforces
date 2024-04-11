#include <bits/stdc++.h>
using namespace std;
int t, n;
long long a[520][520];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		long long z = 1e9;
		long long s = 0;
		for (int i = 1; i <= 2 * n; i++)
		{
			for (int j = 1; j <= 2 * n; j++)
			{
				cin >> a[i][j];
				if (i > n && j > n)
				{
					s += a[i][j];
					a[i][j] = 0;
				}
			}
		}
		z = min(z,min(min(a[1][n+1],a[1][2*n]),min(a[n][n+1],a[n][2*n])));
		z = min(z,min(min(a[n+1][1],a[n+1][n]),min(a[2*n][1],a[2*n][n])));
		cout << z + s << endl;
	}
	return 0;
}