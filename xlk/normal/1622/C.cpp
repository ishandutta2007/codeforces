#include <bits/stdc++.h>
using namespace std;
int t, n;
long long k;
int a[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%lld", &n, &k);
		long long s = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			s += a[i];
		}
		sort(a, a + n);
		long long z = s;
		for (int i = 1; i <= n; i++)
		{
			z = min(z, max((s - k + i - 1) / i, 0LL) + i - 1);
			s -= a[n - i] - a[0];
		}
		printf("%lld\n", z);
	}
	return 0;
}