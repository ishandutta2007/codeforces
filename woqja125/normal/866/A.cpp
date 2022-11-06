#include<stdio.h>
int main() {
	int a;
	scanf("%d", &a);
	if (a != 1) printf("%d 2\n1 2\n", (a - 1) * 2);
	else printf("1 1\n1\n");
	return 0;
}