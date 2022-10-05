#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 1 << 19 | 5;
const long long p1 = 469762049, p2 = 998244353, p3 = 1004535809;
int k, p, rev[Maxn];
long long n, l[Maxn], fac[Maxn], inv[Maxn];
void get_rev(int len)
{
	for (int i = 0; i < len; i++)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (len >> 1));
}
long long fast_pow(long long x, long long y, long long mod = p)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % mod;
		now = now * now % mod;
		y >>= 1;
	}
	return ans;
}
void NTT(long long now[], int len, int mod, bool type = false)
{
	l[0] = 1;
	long long inv3 = fast_pow(3, mod - 2, mod);
	for (int i = 0; i < len; i++)
		if (i < rev[i]) swap(now[i], now[rev[i]]);
	for (int i = 1; i < len; i <<= 1)
	{
		long long w = fast_pow(type ? inv3 : 3, (mod - 1) / (i << 1), mod);
		for (int j = 1; j < i; j++)
			l[j] = l[j - 1] * w % mod;
		for (int j = 0; j < len; j += (i << 1))
		{
			for (int k = j; k < i + j; k++)
			{
				long long x = now[i + k] * l[k - j] % mod, y = now[k];
				now[k] = (x + y) % mod;
				now[i + k] = (y - x + mod) % mod;
			}
		}
	}
	if (type)
	{
		long long inv = fast_pow(len, mod - 2, mod);
		for (int i = 0; i < len; i++)
			now[i] = now[i] * inv % mod;
	}
}
void multi(long long x[], long long y[], int len, int mod)
{
	get_rev(len);
	NTT(x, len, mod), NTT(y, len, mod);
	for (int i = 0; i < len; i++)
		x[i] = x[i] * y[i] % mod;
	NTT(x, len, mod, true), NTT(y, len, mod, true);
}
void multi(long long x[], long long y[], int len)
{
	static long long tmp[Maxn], tmp1[Maxn], tmp2[Maxn], tmp3[Maxn];
	for (int i = 0; i < len; i++)
		tmp1[i] = x[i] % p1, tmp2[i] = x[i] % p2, tmp3[i] = x[i] % p3;
	for (int i = 0; i < len; i++)
		tmp[i] = y[i] % p1;
	multi(tmp1, tmp, len, p1);
	for (int i = 0; i < len; i++)
		tmp[i] = y[i] % p2;
	multi(tmp2, tmp, len, p2);
	for (int i = 0; i < len; i++)
		tmp[i] = y[i] % p3;
	multi(tmp3, tmp, len, p3);
	long long inv1 = fast_pow(p1, p2 - 2, p2), inv2 = fast_pow(p1 * p2 % p3, p3 - 2, p3);
	for (int i = 0; i < len; i++)
	{
		long long k1 = (tmp2[i] - tmp1[i] + p2) * inv1 % p2;
		long long t = (tmp1[i] + k1 * p1) % (p1 * p2);
		long long k2 = (tmp3[i] - t % p3 + p3) * inv2 % p3;
		x[i] = (t + k2 * p1 % p * p2 % p) % p;
	}
}
void work(long long now[], int k, int len)
{
	long long Pow2 = 1, P2 = fast_pow(2, k);
	for (int i = 0; i < len; i++)
		now[i] = now[i] * Pow2 % p, (Pow2 *= P2) %= p;
}
void fast_pow(long long x[], int len, int y)
{
	int done = 1, tmplen = 1;
	static long long tmp[Maxn], ans[Maxn], now[Maxn];
	for (int i = 0; i < len; i++) now[i] = x[i];
	ans[0] = 1;
	while (y)
	{
		if (y & 1)
		{
			for (int i = 0; i < len; i++) tmp[i] = now[i];
			work(tmp, done, len);
			multi(ans, tmp, len << 1);
			for (int i = len; i < (len << 1); i++) ans[i] = 0;
			done += tmplen;
		}
		for (int i = 0; i < len; i++) tmp[i] = now[i];
		work(tmp, tmplen, len);
		multi(now, tmp, len << 1);
		for (int i = len; i < (len << 1); i++) now[i] = 0;
		tmplen <<= 1;
		y >>= 1;
	}
	for (int i = 0; i < len; i++) x[i] = ans[i];
}
void init(int len)
{
	fac[0] = 1;
	for (int i = 1; i <= len; i++)
		fac[i] = fac[i - 1] * i % p;
	inv[len] = fast_pow(fac[len], p - 2);
	for (int i = len - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % p;
}
int lower(int x)
{
	int tmp = 1;
	for (; tmp < x; tmp <<= 1);
	return tmp;
}
long long result, ans[Maxn];
int main()
{
	scanf("%lld%d%d", &n, &k), p = 1e9 + 7;
 
	if (n > k)
	{
		puts("0");
		return 0;
	}
	k++;
	int len = lower(k);
	init(len);
	for (int i = 1; i < k; i++)
		ans[i] = inv[i];
	fast_pow(ans, len, n);
	for (int i = n; i < k; i++)
		(result += ans[i] * fac[k - 1] % p * inv[k - 1 - i] % p * fast_pow(fast_pow(2, i), p - 2) % p) %= p;
	printf("%lld", result);
	return 0;
}