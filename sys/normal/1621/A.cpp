#include <bits/stdc++.h>
using namespace std;

int T, n, m;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		if (2 * m > n + 1)
		{
			puts("-1");
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				if (i == j && i <= 2 * m && i % 2) putchar('R');
				else putchar('.');
			puts("");
		}
	}
	return 0;
}