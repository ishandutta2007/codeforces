#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10000005, p = 1e9 + 7;
int n, k, cnt, phi[Maxn], prim[Maxn], sum[Maxn], ct[Maxn];
long long ans;
bool vis[Maxn];
void init(void)
{
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i]) prim[++cnt] = i, phi[i] = i - 1;
		for (int j = 1; j <= cnt && i * prim[j] <= n; j++)
		{
			vis[i * prim[j]] = true;
			if (i % prim[j] == 0)
			{
				phi[i * prim[j]] = phi[i] * prim[j];
				break;
			}
			phi[i * prim[j]] = phi[i] * (prim[j] - 1);
		}
	}
}
long long get_inv(int x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
int main()
{
	scanf("%d%d", &n, &k);
	init();
	for (int i = 2; i <= n; i++)
		sum[i] = (sum[i - 1] + phi[i]) % p;
	for (int i = 1; i <= n; i++)
		ct[i] = n - i - 1;
	for (int i = 1; i < n; i++)
	{
		int l = (n - 1) / i;
		(ct[i] += sum[l + 1]) %= p;
		(ct[(l + 1) * i - n] += p - phi[l + 1]) %= p;
	}
	long long now = 1;
	for (int i = 1; i < n; i++)
	{
		now = now * k % p;
		(ans += ct[i] * now) %= p;
	}
	printf("%lld", ans * get_inv(now * k % p) % p);
	return 0;
}