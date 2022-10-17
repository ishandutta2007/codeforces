#include <bits/stdc++.h>
using namespace std;
int t, n;
int w[100020];
int d[100020];
int a[100020], ac;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		long long s = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &w[i]);
			d[i] = 0;
			s += w[i];
		}
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			d[x]++;
			d[y]++;
		}
		ac = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < d[i]; j++)
			{
				a[ac++] = w[i];
			}
		}
		sort(a, a + ac, greater<int>());
		for (int i = 0; i < n - 1; i++)
		{
			printf("%lld%c", s, i < n - 2 ? ' ' : '\n');
			s += a[i];
		}
	}
	return 0;
}