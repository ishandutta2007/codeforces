#include <bits/stdc++.h>
using namespace std;
int t, n, m;
char s[60][60];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
		}
		for (int j = 0; j < m; j++)
		{
			int k = n - 1;
			for (int i = n - 1; i >= 0; i--)
			{
				if (s[i][j] == 'o')
				{
					k = i - 1;
				}
				else if (s[i][j] == '*')
				{
					swap(s[i][j], s[k][j]);
					k--;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			printf("%s\n", s[i]);
		}
	}
	return 0;
}