#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[400020];
int s[400020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		memset(s, 0, sizeof s);
		for (int i = 0; i < n / 2; i++)
		{
			s[2] += 2;
			s[min(a[i], a[n-i-1]) + 1] -= 1;
			s[a[i] + a[n-i-1]] -= 1;
			s[a[i] + a[n-i-1]+1] += 1;
			s[max(a[i], a[n-i-1]) + m + 1] += 1;
			s[2 * m + 1] -= 2;
		}
		int z = n;
		for (int i = 2; i <= 2 * m; i++)
		{
			s[i] += s[i-1];
			z = min(z, s[i]);
		}
		printf("%d\n", z);
	}
	return 0;
}