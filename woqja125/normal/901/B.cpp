#include<stdio.h>
int a[151][151];
int main() {
	int n;
	scanf("%d", &n);
	a[0][0] = 1;
	a[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) a[i][j] = a[i - 1][j - 1];
		for (int j = 0; j < i - 1; j++) a[i][j] ^= a[i - 2][j];
	}
	printf("%d\n", n);
	for (int i = 0; i <= n; i++) printf("%d ", a[n][i]);
	printf("\n%d\n", n-1);
	for (int i = 0; i < n; i++) printf("%d ", a[n-1][i]);
	return 0;
}