#include <bits/stdc++.h>
using namespace std;
int t, n;
int p[5020];
int s[5020][5020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &p[i]);
		}
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				s[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (p[i] < p[j])
				{
					s[i][j] = 1;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			}
		}
		long long z = 0;
		for (int k = 1; k <= n; k++)
		{
			for (int l = k + 1; l <= n; l++)
			{
				if (p[k] > p[l])
				{
					// i < k && k < j < l
					z += s[k - 1][l - 1] - s[k - 1][k];
				}
			}
		}
		printf("%lld\n", z);
	}
	return 0;
}