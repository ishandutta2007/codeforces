#include <cstdio>

int t;
long long l, r;

long long calc(long long x, int s) {
	int l = 0, r = 1000000005;
	while (l < r) {
		int m = l + r >> 1;
		if ((long long)m * m + m * s > x) r = m;
		else l = m + 1;
	}
	return r - 1;
}

long long f(long long x) {
	return calc(x, 0) + calc(x, 1) + calc(x, 2);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", f(r) - f(l - 1));
	}
	return 0;
}