#include <bits/stdc++.h>
using namespace std;

int T, n;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		printf("2\n");
		for (int i = 1; i <= n; i++)
			if (i & 1)
			{
				int x = i;
				while (x <= n)
					printf("%d ", x), x <<= 1;
			}
		puts("");
	}
	return 0;
}