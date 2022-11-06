#include<cstdio>
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	if (n >= 30) n = 30;
	n = 1 << n;
	printf("%d\n", m%n);
	return 0;
}