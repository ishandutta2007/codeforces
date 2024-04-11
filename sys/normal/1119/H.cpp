#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 18 | 5;
const long long p = 998244353;
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
int n, k, tot, a[Maxn], b[Maxn], c[Maxn];
long long x, y, z, A[Maxn], B[Maxn], C[Maxn], result[Maxn];
void FWT(long long now[], int len, bool type = false)
{
	for (int i = 1; i < len; i <<= 1)
		for (int j = 0; j < len; j += (i << 1))
			for (int k = j; k < i + j; k++)
			{
				int X = now[k], Y = now[i + k];
				now[k] = (X + Y) * (type ? (p + 1) / 2 : 1) % p;
				now[i + k] = (X - Y + p) * (type ? (p + 1) / 2 : 1) % p;
			}
}
int main()
{
	scanf("%d%d%lld%lld%lld", &n, &k, &x, &y, &z);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &a[i], &b[i], &c[i]), tot ^= a[i], b[i] ^= a[i], c[i] ^= a[i];
		A[b[i]]++, B[c[i]]++, C[b[i] ^ c[i]]++;
	}
	FWT(A, 1 << k), FWT(B, 1 << k), FWT(C, 1 << k);
	long long inv4 = (3 * p + 1) / 4, inv2 = (p + 1) / 2, s1 = (x + y + z) % p, s2 = (p + x + y - z) % p, s3 = (p + x - y + z) % p, s4 = (2 * p + x - y - z) % p;
	for (int i = 0; i < (1 << k); i++)
	{
		long long c1, c2, c3, c4;
		c1 = (n + A[i] + B[i] + C[i]) * inv4 % p;
		c2 = (n + A[i] - 2 * c1 + 2 * p) * inv2 % p;
		c3 = (n + B[i] - 2 * c1 + 2 * p) * inv2 % p;
		c4 = (n + C[i] - 2 * c1 + 2 * p) * inv2 % p;
		result[i] = fast_pow(s1, c1) * fast_pow(s2, c2) % p * fast_pow(s3, c3) % p * fast_pow(s4, c4) % p;
	}
	FWT(result, 1 << k, true);
	for (int i = 0; i < (1 << k); i++)
		printf("%lld ", result[i ^ tot]);
	return 0;
}