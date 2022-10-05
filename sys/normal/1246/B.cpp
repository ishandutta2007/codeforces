#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, k, a[Maxn], cnt[Maxn];
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now;
		now = now * now;
		y >>= 1;
	}
	return ans;
}
long long ans;
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (k == 2)
	{
		for (int i = 1; i <= n; i++)
		{
			int maxi = sqrt(a[i]);
			for (int j = 2; j <= maxi; j++)
				if (a[i] % j == 0)
					while (a[i] % j == 0 && (a[i] / j) % j == 0) a[i] /= j * j;
		}
		for (int i = 1; i <= n; i++)
			ans += cnt[a[i]], cnt[a[i]]++;
		printf("%lld\n", ans);
	}
	else
	{
		sort(a + 1, a + 1 + n);
		for (int x = 1; k * log2(x) <= log2(a[n]) + log2(a[n - 1]); x++)
		{
			long long now = fast_pow(x, k);
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i <= n; i++)
				if (now % a[i] == 0 && now / a[i] <= a[n])
					ans += cnt[now / a[i]], cnt[a[i]]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}