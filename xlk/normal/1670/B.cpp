#include <bits/stdc++.h>
using namespace std;
int t, n, m;
char s[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%s", &n, s);
		int v[256] = {};
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			char c;
			scanf(" %c", &c);
			v[c] = 1;
		}
		int z = 0, c = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[s[i]])
			{
				z = max(z, c);
				c = 1;
			}
			else
			{
				c++;
			}
		}
		printf("%d\n", z);
	}
	return 0;
}