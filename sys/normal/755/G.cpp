#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 16 | 5, p = 998244353;
int n, k, rev[Maxn];
void get_rev(int len)
{
	for (int i = 0; i < len; i++)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (len >> 1));
}
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
void NTT(long long now[], int len, bool type = false)
{
	for (int i = 0; i < len; i++)
		if (i < rev[i]) swap(now[i], now[rev[i]]);
	for (int i = 1; i < len; i <<= 1)
	{
		long long w = fast_pow(type ? 332748118 : 3, (p - 1) / (i << 1));
		for (int j = 0; j < len; j += (i << 1))
		{
			long long l = 1;
			for (int k = j; k < i + j; k++, l = l * w % p)
			{
				long long x = now[i + k] * l % p, y = now[k];
				now[k] = (x + y) % p;
				now[i + k] = (y - x + p) % p;
			}
		}
	}
	if (type)
	{
		long long inv = fast_pow(len, p - 2);
		for (int i = 0; i < len; i++)
			now[i] = now[i] * inv % p;
	}
}
void fast_pow(long long now1[], int y, int len)
{
	get_rev(len << 1);
	static long long now2[Maxn], now3[Maxn], tmp1[Maxn], tmp2[Maxn], tmp3[Maxn];
	now1[0] = 1;
	for (int j = 30; j >= 0; j--)
	{
		memcpy(tmp1, now1, sizeof(long long[len]));
		memcpy(tmp2, now2, sizeof(long long[len]));
		memcpy(tmp3, now3, sizeof(long long[len]));
		for (int i = len; i < (len << 1); i++)
			tmp1[i] = tmp2[i] = tmp3[i] = 0;
		NTT(tmp1, len << 1), NTT(tmp2, len << 1), NTT(tmp3, len << 1);
		long long w = fast_pow(3, (p - 1) / (len << 1)), l = 1;
		for (int i = 0; i < (len << 1); i++)
		{
			now1[i] = (tmp1[i] * tmp1[i] + tmp2[i] * tmp2[i] % p * l) % p;
			now2[i] = (tmp1[i] * tmp2[i] + tmp2[i] * tmp3[i] % p * l) % p;
			now3[i] = (tmp2[i] * tmp2[i] + tmp3[i] * tmp3[i] % p * l) % p;
			(l *= w) %= p;
		}
		NTT(now1, len << 1, true), NTT(now2, len << 1, true), NTT(now3, len << 1, true);
		for (int i = len; i < (len << 1); i++)
			now1[i] = now2[i] = now3[i] = 0;
		if ((y >> j) & 1)
		{
			for (int i = 0; i < len; i++)
				swap(now2[i], now3[i]), swap(now1[i], now2[i]);
			for (int i = 0; i < len; i++)
			{
				now1[i] = 0;
				if (i) (now1[i] += now2[i - 1] + now3[i - 1]) %= p;
				(now1[i] += now2[i]) %= p;
			}
		}
	}
}
int lower(int x)
{
	int tmp = 1;
	for (; tmp < x; tmp <<= 1);
	return tmp;
}
long long ans[Maxn];
int main()
{
	scanf("%d%d", &n, &k);
	fast_pow(ans, n, lower(k + 1));
	if (n == 1)
	{
		for (int i = 1; i <= k; i++)
			printf("%d ", i == 1);
		return 0;
	}
	for (int i = 1; i <= k; i++)
		printf("%lld ", ans[i]);
	return 0;
}