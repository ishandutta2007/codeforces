#include<stdio.h>
bool fg[101];
char ans[101];
bool qr(int x)
{
	if (x > 100) return false;
	printf("%d\n", x);
	fflush(stdout);
	scanf("%s", ans);
	return ans[0] == 'y';
}
int main()
{
	int c = 0;
	for (int i = 2; i <= 50; i++)
	{
		if (fg[i]) continue;
		if (qr(i))
		{
			if (c == 0)
			{
				if (qr(i*i))
				{
					printf("composite\n");
					return 0;
				}
			}
			else
			{
				printf("composite\n");
				return 0;
			}
			c=i;
		}
		for (int j = i; j <= 100; j += i) fg[j] = true;
	}
	printf("prime\n");
	return 0;
}