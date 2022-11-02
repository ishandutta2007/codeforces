#include<cstdio>
int function(long long x) {
	int ret = 0;
	while( x ) {
		ret += x%10;
		x /= 10;
	}
	return ret;
}
int main() {
	long long n, p = 0;
	scanf("%I64d", &n);
	while( p*10+9 <= n )
		p = p*10 + 9;
	printf("%d\n", function(p) + function(n-p));
}