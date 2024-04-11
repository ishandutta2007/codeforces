#include <bits/stdc++.h>
using namespace std;
int t, n, k, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &k);
		int c[32] = {};
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			for (int j = 0; j < 31; j++)
			{
				if (x >> j & 1)
				{
					c[j]++;
				}
			}
		}
		int z = 0;
		for (int i = 30; i >= 0; i--)
		{
			if (k >= n - c[i])
			{
				k -= n - c[i];
				z |= 1 << i;
			}
		}
		printf("%d\n", z);
	}
	return 0;
}