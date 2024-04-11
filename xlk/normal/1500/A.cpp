#include <bits/stdc++.h>
using namespace std;
int n;
int a[200020];
int x[5000020];
int y[5000020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i < j; i++)
		{
			int s = a[i] + a[j];
			if (y[s] > 0 && x[s] != i && y[s] != i && y[s] != j)
			{
				puts("YES");
				printf("%d %d %d %d\n", x[s], y[s], i, j);
				return 0;
			}
			else
			{
				x[s] = i;
				y[s] = j;
			}
		}
	}
	puts("NO");
	return 0;
}