#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define int long long
int n, K, N, a, b, mn = 1e18, mx = -1;
void calc (int x, int y) {
	int d = (y - x + K) % K; if (!d) d = K;
	for (int i = d; i <= N; i += K) {
		int cur = __gcd(i, N);
		mn = min(mn, cur); mx = max(mx, cur);
	}
}

signed main () {
	n = read(), K = read(), a = read(), b = read();
	N = n * K;
	calc(a, b); calc(a, (K - b) % K); calc((K - a) % K, b); calc((K - a) % K, (K - b) % K);
	printf("%lld %lld\n", N / mx, N / mn);
	return 0;
}