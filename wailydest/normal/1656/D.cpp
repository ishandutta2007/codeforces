#include <cstdio>

int t;
long long n;

bool good(long long k) {
	return k > 1 && k <= 2000000000 && n >= k * (k + 1) / 2 && n % k == k * (k + 1) / 2 % k;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		if (n & 1) printf("2\n");
		else {
			long long p = 1, n_ = n;
			while (n_ & 1 ^ 1) {
				p <<= 1;
				n_ >>= 1;
			}
			p <<= 1;
			long long ans = -1;
			if (good(p)) ans = p;
			else if (good(n_)) ans = n_;
			printf("%lld\n", ans);
		}
	}
	return 0;
}