#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		long long z = a[n - 1], s = a[n - 1];
		for (int i = 0; i < n - 1; i++)
		{
			z -= a[i];
			s += a[i];
		}
		z = max(z, 1LL);
		if (s == 0)
		{
			z = 0;
		}
		printf("%lld\n", z);
	}
	return 0;
}