#include<stdio.h>
const long long MOD = 1000000007;
long long get(long long x, long long y, long long k, long long c) {
	if (x == 0 || y == 0) return 0;
	if (k <= 0) return 0;
	if(x < y) x^=y^=x^=y;

	long long re = 0, b, m;
	for(b=1; b*2<=x; b*=2);
	m = b>k?k:b;

	if(y <= b) {
		re = m*(m+1)/2 %MOD * y %MOD;
		re = (re + m*y%MOD*c%MOD)%MOD;
		re = (re + get(x-b, y, k-b, c+b)) % MOD;
		return re;
	}
	else {
		re = m*(m+1)/2 %MOD * b %MOD;
		re = (re + m*b%MOD*c%MOD)%MOD;
		re = (re + get(x-b, b, k-b, c+b)) % MOD;
		re = (re + get(b, y-b, k-b, c+b)) % MOD;
		re = (re + get(x-b, y-b, k, c)) % MOD;
		return re;
	}

}
int main() {
	int T, a, b, c, d, k;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		printf("%lld\n", (get(c, d, k, 0) + get(a - 1, b - 1, k, 0) + MOD - get(a-1, d, k, 0) + MOD - get(c, b-1, k, 0))%MOD);
	};
	return 0;
}