#include<cstdio>
int main() {
	long long n, k;
	scanf("%lld%lld", &n, &k);
	printf("%lld\n", (2*n+k-1)/k + (5*n+k-1)/k + (8*n+k-1)/k);
}