#include <bits/stdc++.h>
using namespace std;
int t, n, m, x;
int a[400020];
long long s[400020], sm;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			s[i] = s[i - 1] + a[i];
		}
		sm = s[n];
		for (int i = n + 1; i <= 2 * n; i++)
		{
			a[i] = a[i - n];
			s[i] = s[i - 1] + a[i];
		}
		for (int i = 1; i <= 2 * n; i++)
		{
			s[i] = max(s[i], s[i - 1]);
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &x);
			if (x <= s[n])
			{
				printf("%lld ", (long long)(lower_bound(s, s + n + 1, x) - s - 1));
			}
			else
			{
				if (sm <= 0)
				{
					printf("-1 ");
				}
				else
				{
					long long r = (x - s[n]) / sm;
					printf("%lld ", (long long)(lower_bound(s, s + 2 * n + 1, x - r * sm) - s - 1) + r * n);
				}
			}
		}
		printf("\n");
	}
	return 0;
}