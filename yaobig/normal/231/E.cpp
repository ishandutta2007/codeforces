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
 * Date: 22-08-14
 * Description: Modular integer with $mod \le 2^{30} - 1$. Note that there are several advantages to use this code:
	1. You do not need to keep writing \% $mod$;
	2. It is good to use this struct when doing Gaussian Elimination / Fast Walsh-Hadamard Transform;
	3. Sometimes the input number is greater than $mod$ and this code handles it.
 * Usage: $mod$ should be a global variable (either const int or int) and should satisfy $mod \le 2^{30} - 1$.
  Do not write things like Mint{1 / 3}.pow(10) since 1 / 3 simply equals 0.
  Do not write things like Mint{a * b} where $a$ and $b$ are int since you might first have integer overflow.
 * Status: tested on https://ac.nowcoder.com/acm/contest/33191/F.
 */

template<const int &mod> struct Z {
	/// start-hash
	int x;
	Z(ll a = 0): x(a % mod) { if (x < 0) x += mod; }
	explicit operator int() const { return x; }

	Z& operator +=(Z b) { x += b.x; if (x >= mod) x -= mod; return *this; }
	Z& operator -=(Z b) { x -= b.x; if (x < 0) x += mod; return *this; }
	Z& operator *=(Z b) { x = 1ll * x * b.x % mod; return *this; }
	friend Z operator +(Z a, Z b) { return a += b; }
	friend Z operator -(Z a, Z b) { return a -= b; }
	friend Z operator *(Z a, Z b) { return a *= b; }
	/// end-hash

	// the followings are needed for ntt and polynomial operations.
	/// start-hash
	Z pow(ll k) const {
		Z res = 1, a = *this;
		for (; k; k >>= 1, a = a * a) if (k & 1) res = res * a;
		return res;
	}
	Z& operator /=(Z b) {
		assert(b.x != 0);
		*this = *this * b.pow(mod - 2);
		return *this;
	}
	friend Z operator /(Z a, Z b) { return a /= b; }

	static int getMod() { return mod; } // ntt need this.
	/// end-hash

	friend string to_string(Z a) { return to_string(a.x); } // just for debug.
};
const int mod = 1e9 + 7;
using Mint = Z<mod>;

/**
 * Author: Yuhao Yao
 * Date: 22-10-04
 * Description: Compute the Edge-BiConnected Components of a graph $G = (V, E)$. ($G$ can be disconnected.) Multiple edges and self loops are allowed. Return the size of BCCs and the index of the component each vertex belongs to.
 * Time: O(|V| + |E|).
 * Status: tested on https://codeforces.com/contest/732/problem/F, https://codeforces.com/contest/231/problem/E, https://www.luogu.com.cn/problem/P8436.
 */

auto EdgeBCC(int n, const vector<pii> &es) {
	vi dfn(n, -1), low(n), id(n), mark(sz(es), 0), sta;
	int cnt = 0, bcc = 0;
	vvi g(n);
	rep(ind, 0, sz(es) - 1) {
		auto [x, y] = es[ind];
		g[x].push_back(ind);
		g[y].push_back(ind);
	}

	auto dfs = [&](auto dfs, int now) -> void {
		low[now] = dfn[now] = cnt++;
		sta.push_back(now);
		for (auto ind: g[now]) if (mark[ind] == 0) {
			mark[ind] = 1;
			auto [x, y] = es[ind];
			int v = now ^ x ^ y;
			if (dfn[v] == -1) {
				dfs(dfs, v);
				low[now] = min(low[now], low[v]);
			} else low[now] = min(low[now], dfn[v]);
		}
		if (low[now] == dfn[now]) {
			while (sta.back() != now) {
				id[sta.back()] = bcc;
				sta.pop_back();
			}
			id[now] = bcc;
			sta.pop_back();
			bcc++;
		}
	};
	rep(i, 0, n - 1) if (dfn[i] == -1) dfs(dfs, i);
	return make_tuple(bcc, id);
}

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
	vector<pii> es(m);
	for (auto &[x, y]: es) {
		cin >> x >> y;
		x--, y--;
	}
	auto [bcc, ids] = EdgeBCC(n, es);
	vvi g(bcc);
	for (auto [x, y]: es) if (ids[x] != ids[y]) {
		g[ids[x]].push_back(ids[y]);
		g[ids[y]].push_back(ids[x]);
	}
	BinaryLifting bl(g);
	vi siz(bcc, 0);
	for (auto id: ids) siz[id]++;
	vi ps(bcc, 0);
	auto dfs = [&](auto dfs, int now, int fa) -> void {
		ps[now] = (fa == -1 ? 0 : ps[fa]) + (siz[now] > 1);
		for (auto v: g[now]) if (v != fa) dfs(dfs, v, now);
	};
	dfs(dfs, 0, -1);
	int k; cin >> k; while (k--) {
		int x, y; cin >> x >> y;
		x--, y--;
		x = ids[x];
		y = ids[y];
		int g = bl.lca(x, y);
		int parg = bl.anc[g][0];
		int cnt = ps[x] + ps[y] - ps[g] - (parg == -1 ? 0 : ps[parg]);
		printf("%d\n", (int) Mint{2}.pow(cnt));
	}
	return 0;
}