#include<stdio.h>
int main()
{
	int n, b, a, ans = 0;
	scanf("%d", &n);
	b = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		if (a == 0)
		{
			b = 0;
			ans++;
		}
		else if (a == 1)
		{
			if (b == 0 || b == 2 || b == 3) b = 1;
			else
			{
				ans++; b = 0;
			}
		}
		else if (a == 2)
		{
			if (b == 0 || b == 1 || b == 3) b = 2;
			else
			{
				ans++; b = 0;
			}
		}
		else
		{
			if (b == 0 || b == 3) b = 3;
			else b = 3 - b;
		}
	}
	printf("%d", ans);
	return 0;
}