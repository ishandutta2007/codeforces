#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int T, n, a[Maxn][Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);
		for (int s = 2; s <= n * 2; s += 4)
		{
			bool flag = false;
			for (int i = 1; i <= n; i++)
			{
				int j = s - i;
				if (j >= 1 && j <= n)
				{
					if (!flag) ans ^= a[i][j];
					flag ^= 1;
				}
			}
		}
		for (int i = 1; i <= n; i++)
			reverse(a[i] + 1, a[i] + 1 + n);
		for (int s = 2; s <= n * 2; s += 4)
		{
			bool flag = false;
			for (int i = 1; i <= n; i++)
			{
				int j = s - i;
				if (j >= 1 && j <= n)
				{
					if (!flag) ans ^= a[i][j];
					flag ^= 1;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}