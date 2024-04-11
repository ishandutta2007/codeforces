#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200020], s, x, y;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		s += a[i];
	}
	sort(a, a + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%lld%lld", &x, &y);
		int p = lower_bound(a, a + n, x) - a;
		long long z = 9e18;
		if (p < n) // a[p] >= x
		{
			z = min(z, max(y - (s - a[p]), 0LL));
		}
		if (p > 0) // a[p-1] < x
		{
			z = min(z, max(y - (s - a[p - 1]), 0LL) + x - a[p - 1]);
		}
		printf("%lld\n", z);
	}
	return 0;
}