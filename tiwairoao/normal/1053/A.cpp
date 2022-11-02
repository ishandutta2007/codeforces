#include<cstdio>
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x%y);
}
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if( (1LL*2*n*m) % (1LL*k) == 0 ) {
		puts("YES");
		printf("%d %d\n", 0, 0);
		if( gcd(n, k) == 1 ) {
			printf("%d %d\n", n, 0);
			printf("%d %d\n", 0, 2*m/k);
		}
		else {
			printf("%d %d\n", 2*n/gcd(2*n, k), 0);
			k /= gcd(2*n, k);
			printf("%d %d\n", 0, m/k);
		}
	}
	else puts("NO");
}