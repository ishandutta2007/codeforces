#include <bits/stdc++.h>
using namespace std;
int t, n, k;
char s[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%s", &n, &k, s);
		int c[26] = {};
		for (int i = 0; i < n; i++)
		{
			c[s[i] - 'a']++;
		}
		int s = 0;
		for (int i = 0; i < 26; i++)
		{
			s += c[i] / 2;
		}
		int z = s / k * 2;
		if ((z + 1) * k <= n)
		{
			z++;
		}
		printf("%d\n", z);
	}
	return 0;
}