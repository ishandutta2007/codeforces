#include<cstdio>
int c[1000001];
int main() {
	int n, x, m = -100000000;
	scanf("%d", &n);
	for (int i = 0; i*i <= 1000000; i++) c[i*i] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (x >= 0 && c[x]) continue;
		if (m < x) m = x;
	}
	printf("%d\n", m);
	return 0;
}