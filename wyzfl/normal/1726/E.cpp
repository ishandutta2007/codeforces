#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

const int P = 998244353;

int add(int x, int y) {
	if (x + y >= P) return x + y - P;
	return x + y;
}

int sub(int x, int y) {
	if (x < y) return x - y + P;
	return x - y;
}

int mul(int x, int y) { return 1ull * x * y % P; }

int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1;
		x = mul(x, x);
	}
	return ans;
}

const int N = 3e5 + 5;

int fac[N], fac2[N], inv[N], dp[N];
int T, n;

inline int C(int n, int m) {
	if (n < m || m < 0) return 0;
	return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	fac[0] = 1;
	for (int i = 1; i <= 300000; i++) fac[i] = mul(fac[i - 1], i);
	inv[300000] = fpow(fac[300000], P - 2);
	for (int i = 300000; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
	fac2[0] = 1;
	for (int i = 2; i <= 300000; i += 2) fac2[i] = mul(fac2[i - 2], i - 1);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= 300000; i++) {
		dp[i] = add(dp[i - 1], mul(dp[i - 2], i - 1));
	}
	T = read();
	while (T--) {
		n = read();
		int ans = 0;
		for (int i = 0; i <= n / 4; i++) {
			int coef = C(n - i * 2, i * 2);
			ans = add(ans, mul(fpow(2, i), mul(mul(coef, fac2[i * 2]), dp[n - i * 4])));
		}
		printf("%d\n", ans);
	}
}