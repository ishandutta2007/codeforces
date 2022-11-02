#include<cstdio>
int main() {
	int n; scanf("%d", &n);
	if( n % 2 == 0 ) puts("NO");
	else {
		puts("YES");
		for(int i=2;i<=2*n;i+=2) {
			printf("%d ", i - ((i/2) & 1));
		}
		for(int i=2;i<=2*n;i+=2) {
			printf("%d ", i - ((i/2) & 1 ^ 1));
		}
	}
}