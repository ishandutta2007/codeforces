#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int a[300020];
int main()
{
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	long long z = 0;
	for (int i = 0; i < m; i++)
	{
		long long s = 0;
		for (int j = i; j < n; j++)
		{
			if (j % m == i)
			{
				s = max(s, 0LL) - l;
			}
			z = max(z, s += a[j]);
		}
	}
	printf("%lld\n", z);
	return 0;
}