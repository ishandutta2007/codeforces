#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, p, l, r, ct, cnt, phi, sum[15][Maxn], res[15];
long long ans, fac[Maxn], inv[Maxn];
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
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= 100000; i++)
	{
		int tmp = i;
		for (int j = 1; j <= ct; j++)
		{
			while (tmp % res[j] == 0) sum[j][i]++, tmp /= res[j];
			sum[j][i] += sum[j][i - 1];
		}
		fac[i] = fac[i - 1] * tmp % p;
		inv[i] = fast_pow(fac[i], phi - 1);
	}
}
long long C(int x, int y)
{
	if (x < y || y < 0) return 0;
	long long ans = fac[x] * inv[y] % p * inv[x - y] % p;
	for (int i = 1; i <= ct; i++)
		(ans *= fast_pow(res[i], sum[i][x] - sum[i][y] - sum[i][x - y])) %= p;
	return ans;
}
int main()
{
	scanf("%d%d%d%d", &n, &p, &l, &r);
	int tmp = p, maxi = sqrt(p);
	phi = p;
	init();
	for (int i = 2; i <= maxi; i++)
		if (tmp % i == 0)
		{
			ct++;
			phi = phi / i * (i - 1);
			res[ct] = i;
			while (tmp % i == 0) tmp /= i;
		}
	if (tmp != 1) res[++ct] = tmp, phi = phi / tmp * (tmp - 1);
	init();
	for (int i = 0; i <= n; i++)
		(ans += C(n, i) * (C(n - i, (n - i - l) >> 1) - C(n - i, (n - i - r - 1) >> 1) + p) % p) %= p;
	printf("%lld", ans);
	return 0;
}