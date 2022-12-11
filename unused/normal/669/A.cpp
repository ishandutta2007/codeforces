#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", n / 3 * 2 + !!(n % 3) );
}