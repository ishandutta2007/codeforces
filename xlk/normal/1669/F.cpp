#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
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
		int l = 0, r = n - 1, d = 0, z = 0;
		while (l <= r)
		{
			if (d < 0)
			{
				d += a[l++];
			}
			else
			{
				d -= a[r--];
			}
			if (d == 0)
			{
				z = max(z, l + n - 1 - r);
			}
		}
		printf("%d\n", z);
	}
	return 0;
}