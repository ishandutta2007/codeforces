#include <cstdio>

int x1, x2, y1, y2, z1, z2, k = 0;

int main()
{
	scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
	if (x1 != x2)
		k++;
	k += (y1 != y2) + (z1 != z2);
	if (k == 3)
		puts("NO");
	else puts("YES");
}