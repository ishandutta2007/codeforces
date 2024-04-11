#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005, p = 998244353, inv6 = 166374059;
int n;
long long ans, f[Maxn], f2[Maxn], sum[Maxn];
int main()
{
	scanf("%d", &n);
	f[0] = sum[0] = 1, f[1] = 2, sum[1] = 3, f2[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		f2[i] = (f[i - 1] * sum[i - 2] + f[i - 1] * (f[i - 1] + 1) / 2) % p;
		f[i] = (f[i - 1] + f2[i]) % p;
		sum[i] = (sum[i - 1] + f[i]) % p;
	}
	ans = 2 * (f[n] + f[n - 1] * (f[n - 1] + 1) % p * (f[n - 1] + 2) % p * inv6 % p + f[n - 1] * (f[n - 1] + 1) / 2 % p * sum[n - 2] + f[n - 1] * (sum[n - 2] * (sum[n - 2] + 1) / 2 % p)) - 1;
	for (int i = 1; i <= n - 1; i++)
		(ans += (f[i] - 1) * f2[n - i - 1]) %= p;
	printf("%lld", ans);
	return 0;
}