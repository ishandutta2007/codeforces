#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 14 | 5, p = 1e9 + 7;
int n, a[17];
long long ans, G[17][17], sum[17][Maxn], f[Maxn];
long long get_inv(int x)
{
	return x <= 1 ? 1 : (p - p / x) * get_inv(p % x) % p;
}
long long calc(int A, int B)
{
	long long result = 1;
	for (int i = 0; i < n; i++)
		if (A & (1 << i)) (result *= sum[i][B]) %= p;
	return result;
}
int main()
{
	scanf("%d", &n);
	int maxi = (1 << n) - 1;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			G[i][j] = a[i] * get_inv(a[i] + a[j]) % p;
	for (int S = 0; S <= maxi; S++)
		for (int i = 0; i < n; i++)
		{
			sum[i][S] = 1;
			for (int j = 0; j < n; j++)
				if (S & (1 << j)) (sum[i][S] *= G[i][j]) %= p;
		}
	for (int S = 1; S <= maxi; S++)
	{
		f[S] = 1;
		for (int T = S; T; T = (T - 1) & S)
			if (T != S)
				(f[S] += p - calc(T, S ^ T) * f[T] % p) %= p;
		(ans += f[S] * calc(S, maxi ^ S) % p * __builtin_popcount(S) % p) %= p;
	}
	printf("%lld", ans);
	return 0;
}