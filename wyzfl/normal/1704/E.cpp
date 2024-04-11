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

vector<pii> seg[N];
vector<int> adj[N];
queue<int> q;
int a[N], deg[N], dp[N][N], sum[N];
int T, n, m, ans;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		m = read();
		int flag = 1;
		rep(i, 1, n) {
			a[i] = read();
			sum[i] = a[i];
			if (a[i]) flag = 0;
			for (int j = 1; j <= n + 1; j++) dp[i][j] = 0;
			for (int j = 1; j <= min(n + 1, a[i]); j++) dp[i][j] = 1;
		}
		rep(i, 1, n) adj[i].clear(), deg[i] = 0;
		rep(i, 1, m) {
			int u = read(), v = read();
			adj[u].push_back(v);
			++deg[v];
		}
		if (flag) {
			printf("0\n");
			continue;
		}
		rep(i, 1, n) {
			if (!deg[i]) {
				q.push(i);
			}
		}
		int t = 0;
		rep(i, 1, n) {
			int u = q.front();
			q.pop();
			for (auto v: adj[u]) {
				sum[v] = add(sum[v], sum[u]);
				int val = 0;
				for (int j = 1; j <= n + 1; j++) {
					val += dp[u][j - 1] + dp[v][j];
					if (val > 0) {
						--val;
						dp[v][j] = 1;
					} else {
						dp[v][j] = 0;
					}
				}
				--deg[v];
				if (!deg[v]) q.push(v);
			}
			if (i == n) t = u;
		}
		if (!dp[t][n + 1]) {
			for (int i = n + 1; i >= 1; i--) {
				if (dp[t][i]) {
					printf("%d\n", i);
					break;
				}
			}
			continue;
		}
		int ans = sum[t];
		for (int i = 1; i <= n + 1; i++) {
			if (!dp[t][i]) {
				ans = add(ans, 1);
			}
		}
		printf("%d\n", ans);
	}
}