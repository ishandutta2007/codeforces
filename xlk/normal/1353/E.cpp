#include <bits/stdc++.h>
using namespace std;
int t, n, m;
char s[1000020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		scanf("%s", s);
		int all = 0;
		int ans = n;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
			{
				all++;
			}
		}
		for (int i = 0; i < m; i++)
		{
			int cnt = 0;
			int x = 0;
			int y = 0;
			int z = 0;
			for (int j = i; j < n; j += m)
			{
				if (s[j] == '1')
				{
					cnt++;
					x++;
					z = min(z + 1, y);
				}
				else
				{
					y = min(y + 1, x);
				}
			}
			ans = min(ans, all - cnt + z);
		}
		printf("%d\n", ans);
	}
	return 0;
}