#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int T, n, m, ans, f[Maxn], s[Maxn], val[Maxn];
long long a[Maxn], sum[Maxn], b[Maxn];
int lowbit(int x)
{
	return x & -x;
}
void modify(int x, int y)
{
	for (int i = x; i <= m; i += lowbit(i))
		s[i] = max(s[i], y);
}
int ask(int x)
{
	int res = -0x3f3f3f3f;
	for (int i = x; i; i -= lowbit(i))
		res = max(res, s[i]);
	return res;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d", &n);
		b[n + 1] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]), sum[i] = sum[i - 1] + a[i], b[i] = sum[i];
		sort(b + 1, b + 2 + n);
		m = unique(b + 1, b + 2 + n) - b - 1;
		for (int i = 1; i <= m; i++) s[i] = val[i] = -0x3f3f3f3f;
		modify(lower_bound(b + 1, b + 1 + m, 0) - b, 0), val[lower_bound(b + 1, b + 1 + m, 0) - b] = 0;
 		for (int i = 1; i <= n; i++)
		{
			int pos = lower_bound(b + 1, b + 1 + m, sum[i]) - b;
			f[i] = max(f[i - 1], 2 * i + ask(pos - 1));
			f[i] = max(f[i], i + val[pos]);
			val[pos] = max(val[pos], f[i] - i);
			ans = max(ans, f[i]);
			modify(pos, f[i] - 2 * i);
		}
		printf("%d\n", ans - n);
	}
	return 0;
}