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

const int N = 1e5 + 5;

long long s[N];
int fac[N], inv[N];
int T, n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	fac[0] = inv[0] = 1;
	rep(i, 1, 100000) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[i - 1], fpow(i, P - 2));
	}
	auto C = [&](int n, int m) {
		if (n < m || m < 0) return 0;
		return mul(fac[n], mul(inv[m], inv[n - m]));
	};
	T = read();
	while (T--) {
		n = read();
		rep(i, 1, n) {
			int a = read();
			s[i] = s[i - 1] + a;
		}
		int ans = 1;
		int i = 1, j = n - 1;
		while (i <= n) {
			int cnt1 = 1, cnt2 = 0;
			while (i < n - 1 && s[i + 1] == s[i]) {
				++cnt1;
				++i;
			}
			while (s[n] - s[j] < s[i] && i <= j) --j;
			if (i > j) break;
			while (s[n] - s[j] == s[i] && j >= 0) {
				++cnt2;
				--j;
			}
			int ret = 0;
			if (i > j) {
				ret = fpow(2, cnt1);
			} else {
				rep(t, 0, min(cnt1, cnt2)) ret = add(ret, mul(C(cnt1, t), C(cnt2, t)));
			}
			ans = mul(ans, ret);
			++i;
		}
		printf("%d\n", ans);
	}
}