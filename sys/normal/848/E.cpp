#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 17 | 5, p = 998244353;
int rev[Maxn];
long long G[3][Maxn], f[3][Maxn], tmp1[Maxn], tmp2[Maxn];
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
void multi(long long x[], long long y[], int len)
{
	get_rev(len);
	NTT(x, len), NTT(y, len);
	for (int i = 0; i < len; i++)
		x[i] = x[i] * y[i] % p;
	NTT(x, len, true);
}
int lower(int x)
{
	int tmp = 1;
	for (; tmp < x; tmp <<= 1);
	return tmp;
}
void work(int lt, int rt)
{
	if (lt == rt)
	{
		(f[0][lt] += G[0][lt]) %= p;
		(f[1][lt] += G[1][lt]) %= p;
		(f[2][lt] += G[2][lt]) %= p;
		return ;
	}
	int mid = (lt + rt) >> 1, len = lower(mid + rt - 2 * lt + 2);
	work(lt, mid);
	
	memset(tmp1, 0, sizeof(long long[len])), memset(tmp2, 0, sizeof(long long[len]));
	for (int i = lt; i <= mid; i++) tmp1[i - lt] = f[0][i];
	for (int i = 0; i <= rt - lt; i++) tmp2[i] = G[0][i];
	multi(tmp1, tmp2, len);
	for (int i = mid + 1; i <= rt; i++) (f[0][i] += tmp1[i - lt]) %= p;
	memset(tmp1, 0, sizeof(long long[len])), memset(tmp2, 0, sizeof(long long[len]));
	for (int i = lt; i <= mid; i++) tmp1[i - lt] = f[1][i];
	for (int i = 0; i <= rt - lt; i++) tmp2[i] = G[1][i];
	multi(tmp1, tmp2, len);
	for (int i = mid + 1; i <= rt; i++) (f[0][i] += tmp1[i - lt]) %= p;
	
	memset(tmp1, 0, sizeof(long long[len])), memset(tmp2, 0, sizeof(long long[len]));
	for (int i = lt; i <= mid; i++) tmp1[i - lt] = f[0][i];
	for (int i = 0; i <= rt - lt; i++) tmp2[i] = G[1][i];
	multi(tmp1, tmp2, len);
	for (int i = mid + 1; i <= rt; i++) (f[1][i] += tmp1[i - lt]) %= p;
	memset(tmp1, 0, sizeof(long long[len])), memset(tmp2, 0, sizeof(long long[len]));
	for (int i = lt; i <= mid; i++) tmp1[i - lt] = f[1][i];
	for (int i = 0; i <= rt - lt; i++) tmp2[i] = G[2][i];
	multi(tmp1, tmp2, len);
	for (int i = mid + 1; i <= rt; i++) (f[1][i] += tmp1[i - lt]) %= p;
	
	memset(tmp1, 0, sizeof(long long[len])), memset(tmp2, 0, sizeof(long long[len]));
	for (int i = lt; i <= mid; i++) tmp1[i - lt] = f[1][i];
	for (int i = 0; i <= rt - lt; i++) tmp2[i] = G[1][i];
	multi(tmp1, tmp2, len);
	for (int i = mid + 1; i <= rt; i++) (f[2][i] += tmp1[i - lt]) %= p;
	memset(tmp1, 0, sizeof(long long[len])), memset(tmp2, 0, sizeof(long long[len]));
	for (int i = lt; i <= mid; i++) tmp1[i - lt] = f[2][i];
	for (int i = 0; i <= rt - lt; i++) tmp2[i] = G[2][i];
	multi(tmp1, tmp2, len);
	for (int i = mid + 1; i <= rt; i++) (f[2][i] += tmp1[i - lt]) %= p;
	
	work(mid + 1, rt);
}
int n;
long long ans, g[Maxn];
int main()
{
	scanf("%d", &n);
	g[0] = g[2] = 1;
	for (int i = 4; i <= n; i++) g[i] = (g[i - 2] + g[i - 4]) % p;
	for (int i = 1; i <= n; i++) G[0][i] = (i - 1LL) * (i - 1) % p * g[i - 1] % p;
	for (int i = 2; i <= n; i++) G[1][i] = (i - 1LL) * (i - 1) % p * g[i - 2] % p;
	for (int i = 3; i <= n; i++) G[2][i] = (i - 1LL) * (i - 1) % p * g[i - 3] % p;
	work(1, n);
	ans = n * (G[0][n] + G[2][n]) % p;
	for (int i = 2; i <= n - 2; i++)
		(ans += (G[0][i] * f[0][n - i] + 2 * G[1][i] * f[1][n - i] + G[2][i] * f[2][n - i]) % p * i) %= p;
	printf("%lld", ans);
	return 0;
}