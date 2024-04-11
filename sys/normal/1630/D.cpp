#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int T, n, m, g, ct, a[Maxn], mini[Maxn];
bool tag[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		long long ans = 0, tmp1 = 0, tmp2 = 0;
		scanf("%d%d", &n, &m);
		memset(mini, 0x3f, sizeof(int[n + 1]));
		memset(tag, 0, sizeof(bool[n + 1]));
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), ans += abs(a[i]);
		g = 0;
		for (int i = 1; i <= m; i++)
		{
			int x;
			scanf("%d", &x);
			g = __gcd(g, x);
		}
		for (int i = 1; i <= n; i++)
			tag[i % g] ^= (a[i] < 0), mini[i % g] = min(mini[i % g], (int) abs(a[i]));
		for (int i = 0; i < g; i++)
			if (tag[i]) tmp1 += mini[i];
			else tmp2 += mini[i];
		printf("%lld\n", ans - 2 * min(tmp1, tmp2));
	}
	return 0;
}