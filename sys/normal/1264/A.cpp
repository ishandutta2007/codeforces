#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
int T, n, a[Maxn], gold, silver;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		gold = silver = 0;
		for (int i = 2; i <= n; i++)
			if (a[i] != a[i - 1])
			{
				gold = i - 1;
				break;
			}
		if (!gold)
		{
			printf("0 0 0\n");
			goto END;
		}
		for (int i = gold + 1; i <= n; i++)
			if (a[i] != a[i - 1] && i - gold - 1 > gold)
			{
				silver = i - gold - 1;
				break;
			}
		for (int i = n / 2 + 1; i > silver; i--)
			if (a[i] != a[i - 1] && i - silver - gold - 1 > gold)
			{
				printf("%d %d %d\n", gold, silver, i - 1 - silver - gold);
				goto END;
			}
		printf("0 0 0\n");
		END:;
	}
	return 0;
}