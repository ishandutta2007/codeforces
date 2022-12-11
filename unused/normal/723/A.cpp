#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int ans = -9999;
	for (int i = 0; i <= 100; i++)
	{
		if (abs(ans - a) + abs(ans - b) + abs(ans - c) >
			abs(i - a) + abs(i - b) + abs(i - c))
		{
			ans = i;
		}
	}
	printf("%d", abs(ans-a)+abs(ans-b)+abs(ans-c));
}