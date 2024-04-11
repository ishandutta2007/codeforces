#include <bits/stdc++.h>
using namespace std;

const int p1 = 998244353, p2 = 469762049, Maxn = 1 << 17 | 5;
int maxn, maxa, mod, rev[Maxn];
int tot, l[Maxn];
const long long lcm = p1 * (long long) p2;
void get_rev(int len)
{
	for (int i = 0; i < len; i++)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (len >> 1));
}
long long fast_pow(long long x, long long y, int p)
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
void NTT(int now[], int len, int p, bool type = false)
{
	l[0] = 1;
	int inv3 = fast_pow(3, p - 2, p);
	for (int i = 0; i < len; i++)
		if (i < rev[i]) swap(now[i], now[rev[i]]);
	for (int i = 1; i < len; i <<= 1)
	{
		long long w = fast_pow(type ? inv3 : 3, (p - 1) / (i << 1), p);
		for (int j = 1; j < i; j++)
			l[j] = l[j - 1] * w % p;
		for (int j = 0; j < len; j += (i << 1))
			for (int k = j; k < i + j; k++)
			{
				int x = now[i + k] * (long long) l[k - j] % p, y = now[k];
				now[k] = (x + y) % p;
				now[i + k] = (y - x + p) % p;
			}
	}
	if (type)
	{
		long long inv = fast_pow(len, p - 2, p);
		for (int i = 0; i < len; i++)
			now[i] = now[i] * inv % p;
	}
}
void multi(int x[], int y[], int result[], int len, int p)
{
	NTT(x, len, p), NTT(y, len, p);
	for (int i = 0; i < len; i++)
		result[i] = x[i] * (long long) y[i] % p;
	NTT(result, len, p, true);
}
long long mul(long long x, long long y)
{
	return ((unsigned long long) x * y - (long long) (x / (long double) lcm * y) * lcm + lcm) % lcm;
}
void multi(int x[], int y[], int result[], int len)
{
	get_rev(len);
	static int tmp1[Maxn], tmp2[Maxn], tmpx[Maxn], tmpy[Maxn];
	for (int i = 0; i < len; i++)
		tmpx[i] = x[i], tmpy[i] = y[i];
	multi(tmpx, tmpy, tmp1, len, p1);
	for (int i = 0; i < len; i++)
		tmpx[i] = x[i], tmpy[i] = y[i];
	multi(tmpx, tmpy, tmp2, len, p2);
	long long P1 = fast_pow(p2, p1 - 2, p1), P2 = fast_pow(p1, p2 - 2, p2);
	for (int i = 0; i < len; i++)
		result[i] = (mul(mul(tmp1[i], p2), P1) + mul(mul(tmp2[i], p1), P2)) % lcm % mod;
}
void poly_pow(int y, int len)
{
	int now = 0;
	static int ans[2][Maxn];
	memset(ans[0], 0, sizeof(int[len << 1]));
	memset(ans[1], 0, sizeof(int[len << 1]));
	static int tmp[Maxn], result[2][Maxn];
	for (int j = 30; j >= 0; j--)
	{
		cerr << j << endl;
		memset(tmp, 0, sizeof(int[len << 1]));
		for (int i = 0; i < len; i++)
			tmp[i] = (ans[0][i] + ans[1][i]) % mod;
		tmp[0]++;
		for (int p = 0; p <= 1; p++)
			multi(tmp, ans[(now & 1) ^ p], result[p], len << 1);
		for (int p = 0; p <= 1; p++)
			for (int i = 0; i < len; i++)
				(ans[p][i] += result[p][i]) %= mod;
		now <<= 1;
		if (y & (1 << j))
		{
			for (int i = len - 1; i; i--)
				(ans[1][i] += ans[0][i - 1] + ans[1][i - 1]) %= mod;
			ans[1][1]++; 
			now++;
		}
		if (now != y)
			for (int i = 1; i <= maxn; i += 2)
				(tot += ans[1][i]) %= mod;
	}
}
int lower(int x)
{
	int tmp = 1;
	for (; tmp < x; tmp <<= 1);
	return tmp;
}
int main()
{
	scanf("%d%d%d", &maxn, &maxa, &mod);
	poly_pow(maxa, lower(maxn + 1));
	printf("%d", tot);
	return 0;
}