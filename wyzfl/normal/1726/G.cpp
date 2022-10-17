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

const int N = 6e5 + 5;

int fac[N], inv[N], a[N], b[N], cnt[N][2], s[N];
int n, maxn, tot, ans;

inline int C(int n, int m) {
	if (n < m || m < 0) return 0;
	return mul(fac[n], mul(inv[m], inv[n - m]));
}

void solve1() {
	int sum = 0, res = 1;
	for (int i = 1; i <= maxn; i++) {
		if (cnt[i][1] >= 2) return;
		if (cnt[i][0]) {
			++tot;
			++s[i];
			--s[i + sum + 1];
			res = mul(res, fac[cnt[i][0]]);
		}
		sum += cnt[i][0] + cnt[i][1];
		if (cnt[i][1]) {
			++tot;
			++s[i + (n - sum)];
			--s[i + n];
		}
	}
	for (int i = 1; i <= maxn + n; i++) {
		s[i] += s[i - 1];
		if (i > maxn && s[i] == tot) {
			ans = add(ans, res);
		}
	}
}

void solve2() {
	int sum = 0, res = 1;
	for (int i = 1; i < maxn; i++) {
		if (cnt[i][1] >= 2) return;
		if (cnt[i][0]) {
			if (i + sum < maxn) return;
			res = mul(res, fac[cnt[i][0]]);
		}
		sum += cnt[i][0] + cnt[i][1];
		if (cnt[i][1]) {
			if (maxn < i + (n - sum) || i + n - 1 < maxn) return;
		}
	}
	res = mul(res, fac[cnt[maxn][0]]);
	res = mul(res, C(n, cnt[maxn][1]));
	ans = add(ans, mul(fac[cnt[maxn][1]], res));
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
	inv[n] = fpow(fac[n], P - 2);
	for (int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
	for (int i = 1; i <= n; i++) a[i] = read(), maxn = max(maxn, a[i]);
	for (int i = 1; i <= n; i++) b[i] = read(), ++cnt[a[i]][b[i]];
	solve1();
	solve2();
	printf("%d\n", ans);
}