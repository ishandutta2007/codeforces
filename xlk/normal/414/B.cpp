#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, z;
int f[2020][2020];
int main()
{
	scanf("%d%d", &n, &m);
	f[0][1] = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = j; k <= n; k += j)
			{
				f[i + 1][k] = (f[i + 1][k] + f[i][j]) % mod;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		z = (z + f[m][i]) % mod;
	}
	printf("%d\n", z);
	return 0;
}