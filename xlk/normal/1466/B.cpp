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
		for (int i = 0; i < n; i++)
		{
			if (i > 0 && a[i] <= a[i - 1])
			{
				a[i]++;
			}
		}
		sort(a, a + n);
		n = unique(a, a + n) - a;
		printf("%d\n", n);
	}
	return 0;
}