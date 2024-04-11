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

const int INF = 1e9 + 5;
const int N = 505;

int w[N][N], f[N][N];
int T, n, m;

signed main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		m = read();
		rep(i, 1, n) rep(j, 1, n) f[i][j] = w[i][j] = INF;
		rep(i, 1, m) {
			int u = read(), v = read(), ww = read();
			w[u][v] = w[v][u] = min(w[u][v], ww);
			f[u][v] = f[v][u] = 1;
		}
		rep(i, 1, n) f[i][i] = 0;
		rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
		long long ans = 1e18;
		rep(u, 1, n) rep(v, 1, n) {
			if (w[u][v] != INF) {
				ans = min(ans, 1ll * w[u][v] * (f[1][u] + f[v][n] + 1));
				rep(i, 1, n) ans = min(ans, 1ll * w[u][v] * (f[i][u] + f[1][i] + f[n][i] + 2));
			}
		}
		printf("%lld\n", ans);
	}
}