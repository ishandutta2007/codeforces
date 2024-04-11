#include <bits/stdc++.h>
using namespace std;
int t, n, m, x;
int c[1000020];
int s[1000020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		memset(c, 0, sizeof c);
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			c[x]++;
		}
		for (int i = 1; i <= m; i++)
		{
			s[i] = s[i - 1] + c[i];
		}
		int f = 1;
		for (int i = 2; i <= m; i++)
		{
			if (c[i])
			{
				for (int j = 1; i * j <= m; j++)
				{
					if (!c[j] && s[min(i * j + i - 1, m)] - s[i * j - 1] > 0)
					{
						f = 0;
						goto end;
					}
				}
			}
		}
		end:
		puts(f ? "Yes" : "No");
	}
	return 0;
}