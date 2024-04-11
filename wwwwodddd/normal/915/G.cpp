#include <iostream>
#include <cstdio>
using namespace std;
long long z[2000020];
int n, k, p = 1000000007;
long long pw(long long x, long long y) {
	long long re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}
int v[2000020];
int main() {
	cin >> n >> k;
	for (int i = 2; i <= k; i++) {
		if (v[i] > 0) {
			continue;
		}
		for (int j = i; j <= k; j += i) {
			v[j] = i;
		}
	}
	z[1] = 1;
	for (int i = 2; i <= k; i++) {
		if (v[i] == i) {
			z[i] = pw(i, n);
		} else {
			z[i] = z[v[i]] * z[i / v[i]] % p;
		}
	}
	for (int i = k; i > 0; i--) {
		z[i] = (z[i] + p - z[i - 1]) % p;
	}
	// 

	for (int i = 1; i <= k; i++) {
		for (int j = i + i; j <= k; j += i) {
			z[j] = (z[j] + p - z[i]) % p;
		}
	}
	for (int i = 1; i <= k; i++) {
		z[i] = (z[i] + z[i - 1]) % p;
	}
	long long __ = 0;
	for (int i = 1; i <= k; i++) {
		__ += (z[i] ^ i);
		__ %= p;
	}
	printf("%lld\n", __);
}