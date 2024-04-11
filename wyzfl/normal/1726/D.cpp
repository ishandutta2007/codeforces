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

vector<pii> adj[N];
int dep[N], fa[N], faid[N], u[N], v[N], seq[N], ans[N];
int T, n, m, len;

void dfs1(int u) {
	for (auto v: adj[u]) {
		if (!dep[v.first]) {
			dep[v.first] = dep[u] + 1;
			fa[v.first] = u;
			faid[v.first] = v.second;
			dfs1(v.first);
		} else if (dep[v.first] <= dep[u] - 2) {
			seq[++len] = v.second;
		}
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		m = read();
		for (int i = 1; i <= n; i++) adj[i].clear(), dep[i] = 0;
		for (int i = 1; i <= m; i++) ans[i] = 0;
		for (int i = 1; i <= m; i++) {
			int u = read(), v = read();
			::u[i] = u;
			::v[i] = v;
			adj[u].emplace_back(v, i);
			adj[v].emplace_back(u, i);
		}
		len = 0;
		dep[1] = 1;
		dfs1(1);
		int cando = 1;
		if (len == 3) {
			vector<int> tmp;
			for (int i = 1; i <= 3; i++) tmp.push_back(u[seq[i]]), tmp.push_back(v[seq[i]]);
			sort(tmp.begin(), tmp.end());
			if (tmp[0] == tmp[1] && tmp[2] == tmp[3] && tmp[4] == tmp[5]) cando = 0;
		}
		if (cando) {
			for (int i = 1; i <= len; i++) ans[seq[i]] = 1;
		} else {
			if (dep[u[seq[1]]] < dep[v[seq[1]]]) swap(u[seq[1]], v[seq[1]]);
			seq[1] = faid[u[seq[1]]];
			for (int i = 1; i <= len; i++) ans[seq[i]] = 1;
		}
		for (int i = 1; i <= m; i++) putchar(ans[i] + '0');
		putchar('\n');
	}
}