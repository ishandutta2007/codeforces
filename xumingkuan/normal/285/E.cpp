#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1010, MOD = 1000000007;
int fac[MAXN], facrev[MAXN];
int n, k, f[2][MAXN][2][2];//f[i&1][j][p0][p1]: first i positions and first min(i+1,n) numbers, (chosen) j perfect positions,
//p0 = if number i is at position i-1,  p1 = if number i+1 is at position i,  number of choices of permutations
inline int getf(int j)
{
	return (long long)(f[n & 1][j][0][0] + f[n & 1][j][1][0]) * fac[n - j] % MOD;
}
inline int C(int n, int m)
{
	return (long long)fac[n] * facrev[m] % MOD * facrev[n - m] % MOD;
}
int quickmul(int a, int b)
{
	int ret = 1;
	for(; b; b >>= 1, a = (long long)a * a % MOD)
		if(b & 1)
			ret = (long long)ret * a % MOD;
	return ret;
}
int main()
{
	scanf("%d%d", &n, &k);
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		fac[i] = (long long)fac[i - 1] * i % MOD;
	facrev[n] = quickmul(fac[n], MOD - 2);
	for(int i = n; i >= 1; i--)
		facrev[i - 1] = (long long)facrev[i] * i % MOD;
	memset(f, 0, sizeof(f));
	f[0][0][1][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= i; j++)
			for(int p0 = 0; p0 <= 1; p0++)
			{
				f[i & 1][j][p0][0] = ((unsigned)f[~i & 1][j - 1][0][p0] + f[~i & 1][j][0][p0] + f[~i & 1][j][1][p0]) % MOD;
				f[i & 1][j][p0][1] = (f[~i & 1][j - 1][0][p0] + f[~i & 1][j - 1][1][p0]) % MOD;
			}
	long long ans = 0;
	for(int i = k; i <= n; i++)
		ans += ((k - i) & 1 ? -1 : 1) * (long long)getf(i) * C(i, k) % MOD;
	if((ans %= MOD) < 0)
		ans += MOD;
	printf("%d\n", (int)ans);
	return 0;
}