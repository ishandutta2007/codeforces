#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n;
int f[1020][1020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = f[i-1][0] + i % 2;
		for (int j = 1; j <= i; j++)
		{
			f[i][j] = (f[i][j-1] + f[i-1][j] + (i+j)%2) % mod;
		}
	}
	printf("%d\n", f[n][n]);
	return 0;
}