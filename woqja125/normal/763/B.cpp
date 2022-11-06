#include<stdio.h>

int main() {
	int n, x, y, c;
	scanf("%d", &n);
	printf("YES\n");
	for (int i=1; i<=n; i++) {
		scanf("%d%d%*d%*d", &x, &y);
		if (x%2 == 0) c = 1;
		else c=2;
		if (y%2 == 0) c+=2;
		printf("%d\n", c);
	}
	return 0;
}