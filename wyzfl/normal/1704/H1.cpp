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

struct FastMod {
	typedef unsigned long long ULL;
	typedef __uint128_t LLL;
	ULL b, m;
	void init(ULL b) { this->b = b, m = ULL((LLL(1) << 64) / b); }
	ULL operator()(ULL a) {
		ULL q = (ULL)((LLL(m) * a) >> 64);
		ULL r = a - q * b;
		return r >= b ? r - b : r;
	}
} M;

int md;

int add(int x, int y) {
	if (x + y >= md) return x + y - md;
	return x + y;
}

int sub(int x, int y) {
	if (x < y) return x - y + md;
	return x - y;
}

int mul(int x, int y) { return M(1ull * x * y); }

int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1;
		x = mul(x, x);
	}
	return ans;
}

const int N = 5005;

typedef vector<int> poly;

poly operator*(poly a, poly b) {
	poly ans(a.size() + b.size() - 1, 0);
	rep(i, 0, (int)a.size() - 1) {
		rep(j, 0, (int)b.size() - 1) {
			ans[i + j] = add(ans[i + j], mul(a[i], b[j]));
		}
	}
	return ans;
}

int dp[N], g[N], fac[N], inv[N], pw[N][N];
int n;

inline int binom(int n, int m) {
	if (n < m || m < 0) return 0;
	return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	md = read();
	M.init(md);
	fac[0] = 1;
	rep(i, 1, n) fac[i] = mul(fac[i - 1], i);
	inv[n] = fpow(fac[n], md - 2);
	per(i, n, 1) inv[i - 1] = mul(inv[i], i);
	rep(i, 1, n) {
		pw[i][0] = 1;
		rep(j, 1, n) pw[i][j] = mul(pw[i][j - 1], i);
	}
	rep(i, 2, n) {
		g[i] = mul(i, i - 1);
		rep(j, 2, i - 1) {
			g[i] = add(g[i], mul(i, mul(g[j], binom(i - 1, j))));
		}
	}
	rep(i, 2, n) g[i] = mul(g[i], n - 1);
	dp[0] = 1;
	rep(i, 2, n) {
		rep(j, 2, i) {
			dp[i] = add(dp[i], mul(binom(i - 1, j - 1), mul(dp[i - j], g[j])));
		}
	}
	printf("%d\n", dp[n]);
}