#include <bits/stdc++.h>
using namespace std;
int get(int x)
{
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
int t, c;
int a[10020];
int p[10020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		memset(p, 0, sizeof p);
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			if (p[i] == 0)
			{
				c = 0;
				a[c++] = get(i);
				while (true)
				{
					a[c] = get(i);
					if (a[c] != a[0])
					{
						c++;
					}
					else
					{
						break;
					}
				}
				for (int j = 1; j <= c; j++)
				{
					p[a[j - 1]] = a[j];
				}
			}
		}
		printf("!");
		for (int i = 1; i <= n; i++)
		{
			printf(" %d", p[i]);
		}
		printf("\n");
		fflush(stdout);
	}
	return 0;
}