#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		long long z = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			z += a[i];
			a[i] -= n - i - 1;
		}
		sort(a, a + n);
		for (int i = n - m; i < n; i++)
		{
			z -= a[i];
		}
		z -= m * (m - 1LL) / 2;
		printf("%lld\n", z);
	}
	return 0;
}