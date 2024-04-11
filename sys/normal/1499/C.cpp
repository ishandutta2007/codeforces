#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		long long now = 0, ans = 0x3f3f3f3f3f3f3f3fLL, mini1 = 0x3f3f3f3f3f3f3f3fLL, mini2 = 0x3f3f3f3f3f3f3f3fLL;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			long long x;
			scanf("%lld", &x);
			if (i & 1) mini1 = min(mini1, x);
			else mini2 = min(mini2, x);
			now += x;
			if (i >= 2) ans = min(ans, now + mini2 * (n - i / 2) + mini1 * (n - (i - i / 2)));
		}
		printf("%lld\n", ans);
	}
	return 0;
}