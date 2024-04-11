#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[300020];
int b[300020];
long long f[300020][3];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &a[i], &b[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				f[i][j] = 1e18;
				for (int k = 0; k < 3; k++)
				{
					if (a[i] + j != a[i-1] + k)
					{
						f[i][j] = min(f[i][j], f[i-1][k] + j * b[i]);
					}
				}
			}
		}
		printf("%lld\n", min(f[n][0], min(f[n][1], f[n][2])));
	}
	return 0;
}