#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n, tot, a[Maxn], b[Maxn];
bool f[Maxn], g[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		tot = 0;
		int ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), ans += (n - 2) * a[i] * a[i], tot += a[i];
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]), ans += (n - 2) * b[i] * b[i], tot += b[i];
		memset(f, 0, sizeof(bool[n * 100 + 1]));
		f[0] = true;
		for (int i = 1; i <= n; i++)
		{
			memcpy(g, f, sizeof(bool[n * 100 + 1]));
			memset(f, 0, sizeof(bool[n * 100 + 1]));
			for (int j = n * 100; j >= a[i]; j--)
				f[j] |= g[j - a[i]];
			for (int j = n * 100; j >= b[i]; j--)
				f[j] |= g[j - b[i]];
		}
		for (int i = tot / 2; i <= tot; i++)
			if (f[i])
			{
				ans += i * i + (tot - i) * (tot - i);
				break;
			}
		printf("%d\n", ans);
	}
	return 0;
}