#include <bits/stdc++.h>
using namespace std;
int t, n;
char s[1000020];
int f[1000020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%s", &n, s + 1);
		for (int i = n; i > 0; i--)
		{
			if (s[i] == '0')
			{
				f[i] = i;
				for (int j = i; j <= n && s[j] == '0'; j += i)
				{
					f[j] = i;
				}
			}
			else
			{
				f[i] = 0;
			}
		}
		long long z = 0;
		for (int i = 1; i <= n; i++)
		{
			z += f[i];
		}
		printf("%lld\n", z);
	}
	return 0;
}