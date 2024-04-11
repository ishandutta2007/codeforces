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

const int N = 1005;

int d[N], ans[N];
int T, n, tot;

int query(int u) {
	printf("? %d\n", u);
	fflush(stdout);
	int ans = read();
	return ans;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		rep(i, 1, n) d[i] = read(), ans[i] = 0;
		tot = 0;
		while (1) {
			int u = 0;
			rep(i, 1, n) {
				if (!ans[i]) {
					if (!u || d[i] > d[u]) {
						u = i;
					}
				}
			}
			if (!u) break;
			vector<int> vec(1, u);
			int cnt = 0;
			ans[u] = ++tot;
			while (cnt < d[u]) {
				int v = query(u);
				if (ans[v]) {
					for (auto i: vec) ans[i] = ans[v];
					break;
				} else {
					ans[v] = tot;
					vec.push_back(v);
				}
				++cnt;
			}
		}
		printf("! ");
		rep(i, 1, n) printf("%d%c", ans[i], i == n ? '\n' : ' ');
		fflush(stdout);
	}
}