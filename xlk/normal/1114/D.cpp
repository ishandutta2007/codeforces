#include <bits/stdc++.h>
using namespace std;
int n;
int a[5020];
int f[5020][5020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	n = unique(a + 1, a + 1 + n) - a - 1;
	for (int i = n; i > 0; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i] == a[j])
			{
				f[i][j] = f[i + 1][j - 1] + 1;
			}
			else
			{
				f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}