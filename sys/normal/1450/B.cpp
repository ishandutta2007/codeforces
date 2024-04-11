#include <bits/stdc++.h>
using namespace std;

int T, n, k, x[205], y[205];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &x[i], &y[i]);
		for (int i = 1; i <= n; i++)
		{
			bool flag = true;
			for (int j = 1; j <= n; j++)
				if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) flag = false;
			if (flag)
			{
				puts("1");
				goto END;
			}
		}
		puts("-1");
		END:;
	}
	return 0;
}