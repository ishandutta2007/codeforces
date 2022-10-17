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

set<int> vec[N];
vector<int> adj[N];
int a[N], id[N], sum[N];
int n, ans;

void dfs1(int u, int fa) {
	sum[u] ^= a[u];
	for (auto v: adj[u]) {
		if (v == fa) continue;
		sum[v] = sum[u];
		dfs1(v, u);
	}
}

void dfs2(int u, int fa) {
	int flag = 0;
	id[u] = u;
	vec[u].insert(sum[u]);
	for (auto v: adj[u]) {
		if (v == fa) continue;
		dfs2(v, u);
		if (flag) continue;
		int x = id[u], y = id[v];
		if (vec[x].size() > vec[y].size()) swap(x, y);
		for (auto it: vec[x]) {
			if (vec[y].count(it ^ a[u])) {
				flag = 1;
				break;
			}
		}
		for (auto it: vec[x]) vec[y].insert(it);
		vec[x].clear();
		id[u] = y;
	}
	if (flag) {
		vec[id[u]].clear();
		++ans;
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n - 1) {
		int u = read(), v = read();
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	printf("%d\n", ans);
}