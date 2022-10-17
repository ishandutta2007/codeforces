#include <bits/stdc++.h>
using namespace std;
int t, n, q;
long long s[1020][1020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &q);
		memset(s, 0, sizeof s);
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			s[x][y] += x * y;
		}
		for (int i = 1; i <= 1000; i++)
		{
			for (int j = 1; j <= 1000; j++)
			{
				s[i][j] += s[i][j - 1];
			}
		}
		for (int i = 1; i <= 1000; i++)
		{
			for (int j = 1; j <= 1000; j++)
			{
				s[i][j] += s[i - 1][j];
			}
		}
		for (int i = 0; i < q; i++)
		{
			int xa, ya, xb, yb;
			scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
			xb--;
			yb--;
			printf("%lld\n", s[xb][yb] - s[xb][ya] - s[xa][yb] + s[xa][ya]);
		}
	}
	return 0;
}