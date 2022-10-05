#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10000005, p = 998244353;
int n, k, x[15], mini = 0x3f3f3f3f;
long long ans, P[15], dP[15], A[Maxn];
int get_inv(long long x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++)
		scanf("%d", &x[i]), mini = min(mini, x[i]);
	for (int i = 1; i <= k; i++)
		x[i] -= mini;
	for (int i = 1; i <= k; i++)
	{
		P[x[i]] = 1;
		if (x[i]) dP[x[i] - 1] = x[i];
	}
	A[0] = P[0];
	for (int i = 0; i < 5 * n; i++)
	{
		for (int j = 0; j < 10 && i - j >= 0; j++)
			(A[i + 1] += (n / 2) * A[i - j] % p * dP[j] % p) %= p;
		for (int j = 1; j < 10 && i - j + 1 >= 0; j++)
			(A[i + 1] += p - P[j] * A[i - j + 1] % p * (i - j + 1) % p) %= p;
		(A[i + 1] *= get_inv(P[0] * (i + 1) % p)) %= p;
		(ans += A[i + 1] * A[i + 1]) %= p;
	}
	printf("%lld", (ans + 1) % p);
	return 0;
}