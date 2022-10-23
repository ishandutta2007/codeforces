#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005, p = 998244353;
long long get_inv(int x)
{
	return x <= 1 ? 1 : (p - p / x) * get_inv(p % x) % p;
}
int T, n, a[Maxn], sum1[Maxn], sum2[Maxn];
long long ans;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d", &n);
		sum2[n + 1] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
			sum1[i] = sum1[i - 1] + (a[i] == 1);
		for (int i = n; i >= 1; i--)
			sum2[i] = sum2[i + 1] + (a[i] == 0);
		int maxi = 0;
		for (int i = 1; i <= n; i++)
			maxi = max(maxi, min(sum1[i], sum2[i + 1]));
		for (int i = 1; i <= maxi; i++)
			(ans += n * (n - 1LL) / 2 % p * get_inv(1LL * i * i % p) % p) %= p;
		printf("%lld\n", ans);
	}
	return 0;
}