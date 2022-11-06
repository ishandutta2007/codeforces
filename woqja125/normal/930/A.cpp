#include<cstdio>
int h[100001];
int c[100001];
int main() {
	int n, t;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &t);
		h[i] = h[t] + 1;
		c[h[i]]++;
	}
	int m = 1;
	for (int i = 1; i <= n; i++) m += c[i] % 2;
	printf("%d\n", m);
	return 0;
}