#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005, p = 1e9 + 7;
int m, cnt, prim[Maxn];
bool vis[Maxn];
long long ans, mu[Maxn];
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
void init(void)
{
	mu[1] = 1;
	for (int i = 2; i <= m; i++)
	{
		if (!vis[i]) prim[++cnt] = i, mu[i] = -1;
		for (int j = 1; j <= cnt && i * prim[j] <= m; j++)
		{
			vis[i * prim[j]] = true;
			if (i % prim[j] == 0) break;
			mu[i * prim[j]] = -mu[i];
		}
	}
}
int main()
{
	scanf("%d", &m);
	init();
	for (int i = 2; i <= m; i++)
		(ans += (p + mu[i]) * (m / i) % p * fast_pow(m - (m / i), p - 2) % p) %= p;
	printf("%lld", (p + 1 - ans) % p);
	return 0;
}