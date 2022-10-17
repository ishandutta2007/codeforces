#include <bits/stdc++.h>
using namespace std;
int t, n, a[320];
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
		int z = 1e9;
		for (int i = 2; i < n; i++)
		{
			z = min(z, a[i] - a[i - 2]);
		}
		printf("%d\n", z);
	}
	return 0;
}