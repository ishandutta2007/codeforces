#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int f[100020];
int d[100020];
char s[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		memset(d, 0, sizeof d);
		scanf("%d", &n);
		for (int i = 2; i <= n; i++)
		{
			scanf("%d", &f[i]);
		}
		scanf("%s", s + 1);
		int z = 0;
		for (int i = n; i > 0; i--)
		{
			if (s[i] == 'B')
			{
				d[i]++;
			}
			else
			{
				d[i]--;
			}
			if (d[i] == 0)
			{
				z++;
			}
			d[f[i]] += d[i];
		}
		printf("%d\n", z);
	}
	return 0;
}