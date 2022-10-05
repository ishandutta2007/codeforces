#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 20 | 5, p = 998244353;
int n, a, b, rev[Maxn];
long long fac[Maxn], finv[Maxn];
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
void multi(long long a[], long long b[], int len)
{
	get_rev(len);
	NTT(a, len), NTT(b, len);
	for (int i = 0; i < len; i++)
		a[i] = a[i] * b[i] % p;
	NTT(a, len, true), NTT(b, len, true);
}
long long * ans[4 * Maxn];
void work(int root, int lt, int rt)
{
	if (lt == rt)
	{
		ans[root] = new long long[4];
		memset(ans[root], 0, sizeof(long long[4]));
		if (lt <= n - 1) ans[root][0] = lt - 1, ans[root][1] = 1;
		else ans[root][0] = 1;
		return ;
	}
	int mid = (lt + rt) >> 1;
	work(root << 1, lt, mid), work(root << 1 | 1, mid + 1, rt);
	ans[root] = new long long[(rt - lt + 1) << 2];
	memset(ans[root], 0, sizeof(long long[(rt - lt + 1) << 2]));
	memcpy(ans[root], ans[root << 1], sizeof(long long[rt - lt + 1]));
	multi(ans[root], ans[root << 1 | 1], (rt - lt + 1) << 1);
}
void init(void)
{
	fac[0] = 1;
	for (int i = 1; i <= a + b - 2; i++)
		fac[i] = fac[i - 1] * i % p;
	finv[a + b - 2] = fast_pow(fac[a + b - 2], p - 2);
	for (int i = a + b - 3; i >= 0; i--)
		finv[i] = finv[i + 1] * (i + 1) % p;
}
long long C(int x, int y)
{
	return fac[x] * finv[y] % p * finv[x - y] % p;
}
int lower(int x)
{
	int tmp = 1;
	for (; tmp < x; tmp <<= 1);
	return tmp;
}
int main()
{
	scanf("%d%d%d", &n, &a, &b);
	init();
	work(1, 1, lower(n - 1));
	printf("%lld\n", ans[1][a + b - 2] * C(a + b - 2, a - 1) % p);
	return 0;
}