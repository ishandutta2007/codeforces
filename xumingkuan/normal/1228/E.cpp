#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MOD = 1000000007;
int C[300][300];
int f[300][300]; // f[i][j]: filled i rows, j columns of 1
int n, k;
long long pk[300], pk1[300];
int main()
{
	scanf("%d%d", &n, &k);
	pk[0] = 1;
	pk1[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		pk[i] = (long long)pk[i - 1] * k % MOD;
		pk1[i] = pk1[i - 1] * (k - 1) % MOD;
	}
	for(int i = 0; i <= n; i++)
	{
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	memset(f, 0, sizeof(f));
//	f[n][n] = 1;
//	for(int i = n; i >= 1; i--)
//	{
//		for(int j = n - (i == n); j >= 1; j--)
//		{
//			if(i < n)
//			{
//				f[i][j] = (f[i][j] + f[i + 1][j] * (pk[j - 1] + MOD - 1)) % MOD;
//			}
//			if(
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int k = 0; k <= j; k++)
			{
				f[i][j] = (f[i][j] + f[i - 1][k] * (k == j ? (pk[j] - pk1[j] + MOD) * pk1[n - j] % MOD : pk[k] * C[n - k][j - k] % MOD * pk1[n - j] % MOD)) % MOD;
			}
//			printf("f[%d][%d] = %d\n", i, j, f[i][j]);
		}
	}
	printf("%d\n", f[n][n]);
	return 0;
}