#include <cstdio>

int main() {
	int a[6], i;
	for(i = 0; i < 6; i++)
		scanf("%d", &a[i]);
	printf("%d\n", (a[0] + a[1] + a[5]) * (a[0] + a[1] + a[5]) - a[1] * a[1] - a[3] * a[3] - a[5] * a[5]);
}