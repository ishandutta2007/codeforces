#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int p = 1000000007;
int n, k, f[1000020], s[1000020];
int pw(int x, int y) {
	int re = 1;
	for (; y; y >>= 1) {
		if (y & 1) {
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}
int main() {
	scanf("%d%d", &n, &k);
	f[0] = 1;
	for (int i = 1; i <= k + 1; i++) {
		s[i] = (s[i - 1] + pw(i, k)) % p;
		f[i] = (long long)f[i - 1] * i % p;
	}
	if (n <= k + 1) {
		printf("%d\n", s[n]);
		return 0;
	}
	int c = 1;
	for (int i = 0; i <= k + 1; i++) {
		c = (long long)c * (n - i) % p;
	}
	int ans = 0;
	for (int i = 0; i <= k + 1; i++) {
		int t = (long long)c * pw((long long)(n - i) * f[k + 1 - i] % p * f[i] % (long long)p, p - 2) % p * s[i] % p;
		if ((k + 1 - i) % 2 == 0) {
			ans += t;
		} else {
			ans += p - t;
		}
		if (ans >= p) {
			ans -= p;
		}
	}
	printf("%d\n", ans);
	return 0;
}