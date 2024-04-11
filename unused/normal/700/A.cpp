#include <stdio.h>

int main()
{
	int	n, l, v1, v2, k;
	scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k);
	int x = (n + k - 1) / k;
	double b = l / (v2 + 2.0 * v2 * v1 / (v2 + v1) * (x - 1));
	printf("%.9f\n", b * (1 + 2.0 * v2 / (v2 + v1) * (x - 1)));
}