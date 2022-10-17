#include <bits/stdc++.h>
using namespace std;
int n;
int f[520][520];
int main()
{
	cin >> n;
	cout << (n * n * n - n - 6) / 3 << endl;
	return 0;
	for (int i = n; i > 0; i--)
	{
		for (int j = i + 2; j <= n; j++)
		{
			f[i][j] = 1e9;
			for (int k = i + 1; k < j; k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k][j] + i * j * k);
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}