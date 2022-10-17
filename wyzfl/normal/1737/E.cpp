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

const int P = 1e9 + 7;

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

const int N = 1e6 + 5;

int ans[N], pw[N];
int T, n;

signed main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	pw[0] = 1;
	rep(i, 1, 1000000) pw[i] = mul(pw[i - 1], (P + 1) / 2);
	T = read();
	while (T--) {
		n = read();
		int sum = 0;
		per(i, n, 1) {
			if (i * 2 <= n) sum = add(sum, ans[i * 2]);
			if (i * 2 + 1 <= n) sum = add(sum, ans[i * 2 + 1]);
			ans[i] = sub(pw[(i + 1) / 2 - (i == n)], mul(sum, pw[(i + 1) / 2]));
		}
		rep(i, 1, n) printf("%d\n", ans[i]);
	}
}