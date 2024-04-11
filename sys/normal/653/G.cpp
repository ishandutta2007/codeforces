#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005, p = 1e9 + 7;
int n, a[Maxn], b[Maxn];
long long ans, fac[Maxn], inv[Maxn], pool[Maxn], *sum = pool + 1;
vector <int> Ve[Maxn];
long long get_inv(int x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
long long C(int x, int y)
{
	return fac[x] * inv[y] % p * inv[x - y] % p;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		int maxi = sqrt(a[i]);
		for (int j = 2; j <= maxi; j++)
		{
			int c = 0;
			while (a[i] % j == 0)
			{
				c++;
				a[i] /= j;
			}
			if (c) Ve[j].push_back(c);
		}
		if (a[i] != 1)
			Ve[a[i]].push_back(1);
	}
	fac[0] = 1;
	for (int i = 1; i < n; i++)
		fac[i] = fac[i - 1] * i % p;
	inv[n - 1] = get_inv(fac[n - 1]);
	for (int i = n - 2; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % p;
	for (int i = 0; i < n; i++)
		sum[i] = (sum[i - 1] + C(n - 1, i)) % p;
	for (int i = 2; i <= 300000; i++)
	{
		sort(Ve[i].begin(), Ve[i].end());
		for (int j = 0; j < (int) Ve[i].size(); j++)
		{
			int rk = n - Ve[i].size() + j + 1;
			(ans += Ve[i][j] * (sum[rk - 2] - sum[n - 1] + sum[rk - 1] + p)) %= p;
		}
	}
	printf("%lld", ans);
	return 0;
}