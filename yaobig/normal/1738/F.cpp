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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int cas; cin >> cas; while (cas--) {
		int n; cin >> n;
		vi ds(n);
		for (auto &x: ds) cin >> x;
		auto ask = [&](int x) {
			printf("? %d\n", x + 1);
			fflush(stdout);
			int y; cin >> y;
			y--;
			return y;
		};
		auto answer = [&](const vi &cs) {
			printf("!");
			for (auto x: cs) printf(" %d", x + 1);
			puts("");
			fflush(stdout);
		};
		set<pii> s;
		rep(i, 0, n - 1) s.emplace(ds[i], i);
		DSU dsu(n);
		while (sz(s)) {
			auto it = --s.end();
			auto [_, now] = *it;
			s.erase(it);
			rep(i, 0, ds[now] - 1) {
				int v = ask(now);
				dsu.merge(now, v);
				if (s.count({ds[v], v}) == 0) break;
				else s.erase({ds[v], v});
			}
		}
		vi cs(n);
		rep(i, 0, n - 1) cs[i] = dsu.getcomp(i);
		answer(cs);
	}
	return 0;
}