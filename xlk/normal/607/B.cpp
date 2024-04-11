#include <bits/stdc++.h>
using namespace std;
int n;
int a[520];
int f[520][520];
int main()
{
	cin >> n;
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		f[i][i] = 1;
		f[i+1][i] = 1;
	}
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = i+1; j <= n; j++)
		{
			if (a[i] == a[j-1])
			{
				f[i][j] = f[i+1][j-1];
			}
			for (int k = i+1; k < j; k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	printf("%d\n", f[0][n]);
	return 0;
}