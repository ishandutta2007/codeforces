#include<cstdio>
int c[100001];
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		c[x]++;
	}
	int w = 0;
	for (int i = 100000; i >= 1; i--) {
		if (i == 0) continue;
		if (c[i] % 2 == 1) {
			printf("Conan\n");
			return 0;
		}
	}
	printf("Agasa\n");
	return 0;
}