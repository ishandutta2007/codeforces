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

const int N = 5e5 + 5;

vector<pii> adj[N];
int ans1[N], ans2[N];
int T, p, n, tot;

void dfs1(int u, int fa, int dep) {
	for (auto v: adj[u]) {
		if (v.first == fa) continue;
		++tot;
		if (!dep) {
			ans1[v.first] = tot;
			ans2[v.second] = tot + (1 << p);
		} else {
			ans1[v.first] = tot + (1 << p);
			ans2[v.second] = tot;
		}
		dfs1(v.first, u, dep ^ 1);
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		p = read();
		n = 1 << p;
		for (int i = 1; i <= n; i++) adj[i].clear();
		for (int i = 1; i < n; i++) {
			int u = read(), v = read();
			adj[u].emplace_back(v, i);
			adj[v].emplace_back(u, i);
		}
		ans1[1] = 1 << p;
		tot = 0;
		dfs1(1, 0, 0);
		printf("1\n");
		for (int i = 1; i <= n; i++) printf("%d%c", ans1[i], i == n ? '\n' : ' ');
		for (int i = 1; i <= n - 1; i++) printf("%d%c", ans2[i], i == n - 1 ? '\n' : ' ');
	}
}