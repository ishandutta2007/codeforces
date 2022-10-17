#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[8020];
int v[8020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		memset(v, 0, sizeof v);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++)
		{
			int s = a[i];
			for (int j = i + 1; j < n; j++)
			{
				s += a[j];
				if (s <= n)
				{
					v[s] = 1;
				}
				else
				{
					break;
				}
			}
		}
		int z = 0;
		for (int i = 0; i < n; i++)
		{
			z += v[a[i]];
		}
		printf("%d\n", z);
	}
	return 0;
}