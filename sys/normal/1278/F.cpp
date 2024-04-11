#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005, p = 998244353;
int n, m, k;
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
long long ans, S[Maxn][Maxn];
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	S[0][0] = 1;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= i; j++)
			S[i][j] = (S[i - 1][j - 1] + S[i - 1][j] * j) % p;
	for (int i = 0; i <= k; i++)
	{
		long long tmp = fast_pow(fast_pow(m, p - 2), i);
		for (int j = n; j >= n - i + 1; j--)
			(tmp *= j) %= p;
		(ans += S[k][i] * tmp) %= p;
	}
	printf("%lld", ans);
	return 0;
}