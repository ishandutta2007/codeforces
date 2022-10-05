#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int main()
{
	scanf("%d%d", &n, &m);
	if (n == 1 && m == 1)
	{
		printf("0");
		return 0;
	}
	if (n == 1 || m == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				printf("%d ", i + j);
			printf("\n");
		}
	}
	else
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				printf("%d ", i * (n + j));
			printf("\n");
		}
	return 0;
}