#include <bits/stdc++.h>
using namespace std;
int t, n, m;
char s[200020];
int f[256];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%s", &n, &m, s);
		for (int i = 0; i < 256; i++)
		{
			f[i] = i;
		}
		for (int i = 0; i < n; i++)
		{
			while (F(s[i]) > 'a' && m > 0)
			{
				f[F(s[i])] = F(s[i]) - 1;
				m--;
			}
			s[i] = F(s[i]);
		}
		printf("%s\n", s);
	}
	return 0;
}