#include <bits/stdc++.h>
using namespace std;

int T, n, k; 
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		if (n == 4 && k == 3)
		{
			puts("-1");
			continue;
		}
		else if (k == n - 1)
		{
			printf("%d %d\n1 %d\n", n - 1, n - 2, n - 3);
			for (int i = 3; 2 * i < n - 1; i++)
				printf("%d %d\n", i, n - 1 - i);
			printf("0 2\n");
			continue;
		}
		if (!k) printf("%d %d\n", 0, n - 1);
		for (int i = 1; 2 * i < n - 1; i++)
			if (i != k && n - 1 - i != k) printf("%d %d\n", i, n - 1 - i);
			else
			{
				if (i == k) printf("%d %d\n%d %d\n", 0, n - 1 - i, k, n - 1);
				else printf("%d %d\n%d %d\n", n - 1, k, i, 0);
			}
	}
	return 0;
}