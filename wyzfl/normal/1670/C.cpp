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

const int N = 1e5 + 5;

int a[N], b[N], c[N], pa[N], pb[N], vis[N];
int T, n, ans;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) a[i] = read(), pa[a[i]] = i;
		for (int i = 1; i <= n; i++) b[i] = read(), pb[b[i]] = i;
		for (int i = 1; i <= n; i++) c[i] = read();
		for (int i = 1; i <= n; i++) vis[i] = 0;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == b[i] || vis[i]) continue;
			int tmp = i, cando = 1;
			while (!vis[tmp]) {
				vis[tmp] = 1;
				if (c[tmp]) cando = 0;
				tmp = pb[a[tmp]];
			}
			ans += cando;
		}
		printf("%d\n", fpow(2, ans));
	}
}