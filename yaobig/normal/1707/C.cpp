#include "bits/stdc++.h"
#define rep(i, a, n) for (auto i = a; i <= (n); ++i)
#define revrep(i, a, n) for (auto i = n; i >= (a); --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;

template<class A, class B> string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string) s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template<class A> string to_string(A v) {
	bool first = 1;
	string res = "{";
	for (const auto &x: v) {
		if (!first) res += ", ";
		first = 0;
		res += to_string(x);
	}
	res += "}";
	return res;
}
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

void debug_out() { cerr << endl; }
template<class Head, class... Tail> void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}
#ifndef ONLINE_JUDGE
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
	#define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

/**
 * Author: Yuhao Yao
 * Date: 22-09-08
 * Description: Disjoint set union. $merge$ merges components which $x$ and $y$ are in respectively and returns $1$ if $x$ and $y$ are in different components.
 * Time: amortized O(\alpha(M, N)) where $M$ is the number of operations. Almost constant in competitive programming.
 */

struct DSU {
	vi fa, siz;

	DSU(int n): fa(n), siz(n, 1) { iota(all(fa), 0); }

	int getcomp(int x) { return fa[x] == x ? x : fa[x] = getcomp(fa[x]); }

	// return 1 if x and y are in different component and merge.
	bool merge(int x, int y) {
		int fx = getcomp(x), fy = getcomp(y);
		if (fx == fy) return 0;
		if (siz[fx] < siz[fy]) swap(fx, fy);
		fa[fy] = fx;
		siz[fx] += siz[fy];
		return 1;
	}
};

/**
 * Author: Yuhao Yao
 * Date: 22-09-13
 * Description: Compute the sparse table for binary lifting of a tree $T$.
 * Time: O(|V|\log |V|) for precalculation and O(\log |V|) for each $lca$ query.
 * Status: tested on https://codeforces.com/contest/231/problem/E.
 */

struct BinaryLifting {
	int n;
	vi dep;
	vector<vi> anc;
	BinaryLifting(const vector<vi> &g, int rt = 0): n(sz(g)), dep(n) {
		assert(n > 0);
		anc.assign(n, vi(__lg(n) + 1));
		auto dfs = [&](auto dfs, int now, int fa) -> void {
			dep[now] = fa == -1 ? 0 : dep[fa] + 1;
			anc[now][0] = fa;
			rep(i, 1, __lg(n)) {
				anc[now][i] = anc[now][i - 1] == -1 ? -1 : anc[anc[now][i - 1]][i - 1];
			}
			for (auto v: g[now]) if (v != fa) dfs(dfs, v, now);
		};
		dfs(dfs, rt, -1);
	}
	int swim(int x, int h) {
		for (int i = 0; h && x != -1; h >>= 1, i++) {
			if (h & 1) x = anc[x][i];
		}
		return x;
	}
	int lca(int x, int y) {
		if (dep[x] < dep[y]) swap(x, y);
		x = swim(x, dep[x] - dep[y]);
		if (x == y) return x;
		for (int i = __lg(n); i >= 0; --i) {
			if (anc[x][i] != anc[y][i]) {
				x = anc[x][i];
				y = anc[y][i];
			}
		}
		return anc[x][0];
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m; cin >> n >> m;

	vvi g(n);
	DSU dsu(n);
	vector<pii> bad;
	rep(i, 1, m) {
		int u, v; cin >> u >> v;
		u--, v--;
		if (dsu.merge(u, v)) {
			g[u].push_back(v);
			g[v].push_back(u);
		} else bad.push_back({u, v});
	}
	BinaryLifting bl(g);
	vi cnt(n);
	auto &dep = bl.dep;
	for (auto [x, y]: bad) {
		if (dep[x] > dep[y]) swap(x, y);
		int g = bl.lca(x, y);
		if (x == g) {
			int h = dep[y] - dep[x];
			int u = bl.swim(y, h - 1);
			cnt[u]++;
			cnt[y]--;
		} else {
			cnt[0]++;
			cnt[x]--;
			cnt[y]--;
		}
	}
	auto dfs = [&](auto dfs, int now, int fa) -> void {
		if (fa != -1) cnt[now] += cnt[fa];
		for (auto v: g[now]) if (v != fa) dfs(dfs, v, now);
	};
	dfs(dfs, 0, -1);
	rep(i, 0, n - 1) putchar(cnt[i] == 0 ? '1' : '0');
	puts("");

	return 0;
}