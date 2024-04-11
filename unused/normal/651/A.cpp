#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);

	int ans = 0;

	while (a >= 2 || b >= 2)
	{
		if (a == 0 || b == 0) break;
		if (a < b) a++, b -= 2;
		else a -= 2, b++;
		ans++;
	}
	printf("%d\n", ans);
}