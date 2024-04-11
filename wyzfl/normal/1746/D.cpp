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

const int N = 2e5 + 5;

vector<int> adj[N];
long long dp[N][2];
int w[N], val[N][2];
int T, n, k;

void dfs1(int u) {
	if (!adj[u].size()) return;
	int len = (int)adj[u].size();
	for (auto v: adj[u]) {
		val[v][0] = val[u][0] / len;
		val[v][1] = (val[u][1] + len - 1) / len;
		dfs1(v);
	}
}

void dfs2(int u) {
	if (!adj[u].size()) {
		dp[u][0] = 1ll * val[u][0] * w[u];
		dp[u][1] = 1ll * val[u][1] * w[u];
		return;
	}
	vector<long long> vec;
	int sum = 0;
	long long sdp = 0;
	for (auto v: adj[u]) {
		dfs2(v);
		sum += val[v][0];
		sdp += dp[v][0];
		if (val[v][0] != val[v][1]) vec.push_back(dp[v][1] - dp[v][0]);
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < val[u][0] - sum; i++) sdp += vec[i];
	dp[u][0] = sdp;
	if (val[u][0] == val[u][1])
		dp[u][1] = sdp;
	else
		dp[u][1] = sdp + vec[val[u][0] - sum];
	dp[u][0] += 1ll * val[u][0] * w[u];
	dp[u][1] += 1ll * val[u][1] * w[u];
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		k = read();
		rep(i, 1, n) adj[i].clear();
		rep(i, 2, n) {
			int fa = read();
			adj[fa].push_back(i);
		}
		rep(i, 1, n) w[i] = read();
		val[1][0] = val[1][1] = k;
		dfs1(1);
		dfs2(1);
		printf("%lld\n", dp[1][0]);
	}
}