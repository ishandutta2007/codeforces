#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n;
long long a[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		long long ans = -1e18, K = 0, B = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		sort(a + 1, a + 1 + n);
		for (int i = 2; i <= n; i++)
			B += a[1] * a[i], K += a[1] + a[i];
		if (K > 0)
		{
			puts("INF");
			continue;
		}
		ans = max(ans, max(-a[1] * K, -a[2] * K) + B);
		for (int i = 2; i < n; i++)
		{
			K += a[n] - a[1], B += (a[n] - a[1]) * a[i];
			ans = max(ans, max(-a[i] * K, -a[i + 1] * K) + B);
		}
		ans = max(ans, max(-a[n - 1] * K, -a[n] * K) + B);
		if (K < 0)
		{
			puts("INF");
			continue;
		}
		printf("%lld\n", ans);
	}
	return 0;
}