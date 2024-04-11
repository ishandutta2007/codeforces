#include <bits/stdc++.h>
using namespace std;
int n, m, z;
char a[5020];
char b[5020];
int f[5020][5020];
int main()
{
	scanf("%d%d%s%s", &n, &m, a + 1, b + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
			{
				f[i][j] = f[i - 1][j - 1] + 2;
			}
			else
			{
				f[i][j] = max(max(f[i - 1][j], f[i][j - 1]) - 1, 0);
			}
			z = max(z, f[i][j]);
		}
	}
	printf("%d\n", z);
	return 0;
}