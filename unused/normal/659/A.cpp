#include <stdio.h>
#include <algorithm>

int main()
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	a += b;
	int ans = ((a + 100 * n) % n);
	printf("%d\n", ans == 0 ? n : ans);
}