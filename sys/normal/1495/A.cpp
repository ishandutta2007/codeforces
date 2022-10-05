#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n, ct1, ct2, a[Maxn], b[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ct1 = ct2 = 0;
		double ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (!x) b[++ct2] = abs(y);
			else a[++ct1] = abs(x);
		}
		sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
		for (int i = 1; i <= n; i++)
			ans += sqrt(a[i] * (long long) a[i] + b[i] * (long long) b[i]);
		printf("%.10lf\n", ans);
	}
	return 0;
}