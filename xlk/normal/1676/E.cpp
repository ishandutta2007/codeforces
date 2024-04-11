#include <bits/stdc++.h>
using namespace std;
int t, n, q, x;
int a[200020];
long long s[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		reverse(a, a + n);
		for (int i = 0; i < n; i++)
		{
			s[i + 1] = s[i] + a[i];
		}
		s[n + 1] = 2e9;
		for (int i = 0; i < q; i++)
		{
			scanf("%d", &x);
			int p = lower_bound(s, s + n + 2, x) - s;
			if (p > n)
			{
				p = -1;
			}
			printf("%d\n", p);
		}
	}
	return 0;
}