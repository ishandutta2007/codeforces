#include <stdio.h>

int main()
{
	int n, h, d;
	scanf("%d%d%d", &n, &d, &h);

	if (h > d || d > 2 * h)
	{
		printf("-1\n");
		return 0;
	}

	if (n >= 3 && d <= 1)
	{
		printf("-1\n");
		return 0;
	}

	for (int i = 1; i <= h; i++)
	{
		printf("%d %d\n", i, i + 1);
	}

	int prev = 1;
	for (int i = h + 2, j = 0; j < d - h; j++, i++)
	{
		printf("%d %d\n", prev, i);
		prev = i;
	}

	for (int i = d + 2; i <= n; i++)
	{
		printf("%d %d\n", h == d ? 2 : 1, i);
	}
}