#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005, p = 1e9 + 7;
int n, k;
long long ans, S[Maxn][Maxn];
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
int main()
{
	scanf("%d%d", &n, &k);
	S[0][0] = 1;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= i; j++)
			S[i][j] = (S[i - 1][j - 1] + S[i - 1][j] * j) % p;
	long long now = fast_pow(2, n);
	for (int i = 1; i <= k; i++)
	{
		(now *= (n - i + 1) * fast_pow(2, p - 2) % p) %= p;
		(ans += S[k][i] * now) %= p;
	}
	printf("%lld", ans);
	return 0;
}