#include <bits/stdc++.h>
using namespace std;
int t, n, z, zi;
int a[200020];
int c[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		memset(c, 0, sizeof c);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			c[a[i]]++;
		}
		int z = n + 1, zi = -1;
		for (int i = 0; i < n; i++)
		{
			if (c[a[i]] == 1)
			{
				if (z > a[i])
				{
					z = a[i];
					zi = i + 1;
				}
			}
		}
		printf("%d\n", zi);
	}
	return 0;
}