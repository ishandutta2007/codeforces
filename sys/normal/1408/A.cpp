#include <bits/stdc++.h>
using namespace std;

int n, T, a[105], b[105], c[105], ans[1000005];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans[0] = -0x3f3f3f3f;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &c[i]);
		for (int i = 1; i <= n; i++)
		{
			if (i == n)
			{
				if (a[i] != ans[1] && a[i] != ans[n - 1])
				{
					printf("%d\n", a[i]);
					break;
				}
				if (b[i] != ans[1] && b[i] != ans[n - 1])
				{
					printf("%d\n", b[i]);
					break;
				}
				printf("%d\n", c[i]);
			}
			else
			{
				if (a[i] != ans[i - 1])
					printf("%d ", ans[i] = a[i]);
				else if (b[i] != ans[i - 1])
					printf("%d ", ans[i] = b[i]);
			}
		}
	}
	return 0;
}