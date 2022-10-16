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
template<class A> string to_string(const A &v) {
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
template<class H, class... T> void debug_out(const H& h, const T&... t) {
	cerr << " " << to_string(h);
	debug_out(t...);
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
 * Date: 22-10-04
 * Description: Compute the Vertex-BiConnected Components of a graph $G = (V, E)$ (not necessarily connected). 
 *  Multiple edges and self loops are allowed.
 *  $id[i]$ records the index of bcc the edge $i$ is in.
 *  $top[u]$ records the second highest vertex (which is unique) in the bcc which vertex $u$ is in.
 * Time: O(|V| + |E|).
 * Status: tested on https://codeforces.com/gym/102900/problem/K, https://www.luogu.com.cn/problem/P4630, https://codeforces.com/contest/487/problem/E.
 */

struct VertexBCC {
	int n, bcc;
	vi id, top, fa;
	vector<pii> bf; // edges of the block-forest.
	VertexBCC(int n, const vector<pii> &es): n(n), bcc(0), id(sz(es)), top(n), fa(n, -1) {
		vvi g(n);
		rep(ind, 0, sz(es) - 1) {
			auto [x, y] = es[ind];
			g[x].push_back(ind);
			g[y].push_back(ind);
		}

		int cnt = 0;
		vi dfn(n, -1), low(n), mark(sz(es)), vsta, esta;
		auto dfs = [&](auto dfs, int now) -> void {
			low[now] = dfn[now] = cnt++;
			vsta.push_back(now);
			for (auto ind: g[now]) if (mark[ind] == 0) {
				mark[ind] = 1;
				esta.push_back(ind);
				auto [x, y] = es[ind];
				int v = now ^ x ^ y;
				if (dfn[v] == -1) {
					dfs(dfs, v);
					fa[v] = now;
					low[now] = min(low[now], low[v]);
					if (low[v] >= dfn[now]) {
						bf.emplace_back(n + bcc, now);
						while (1) {
							int z = vsta.back();
							vsta.pop_back();
							top[z] = v;
							bf.emplace_back(n + bcc, z);
							if (z == v) break;
						}
						while (1) {
							int z = esta.back();
							esta.pop_back();
							id[z] = bcc;
							if (z == ind) break;
						}
						bcc++;
					}
				} else low[now] = min(low[now], dfn[v]);
			}
		};
		rep(i, 0, n - 1) if (dfn[i] == -1) {
			dfs(dfs, i);
			top[i] = i;
		}
	}
	bool SameBcc(int x, int y) {
		if (x == fa[top[y]] || y == fa[top[x]]) return 1;
		else return top[x] == top[y];
	}
	vector<pii> getBlockForest() { return bf; }
};

/**
 * Author: Yuhao Yao
 * Date: 22-10-08
 * Description: Heavy Light Decomposition for a tree $T$ (can be modified easily for forest).
 * Usage: $g$ should be the adjacent list of the tree $T$. $rt$ for specifying the root of the tree $T$ (default 0).
 *  $chainApply(u, v, func, val)$ and $chainAsk(u, v, func)$ are used for apply / query on the simple path from $u$ to $v$ on tree $T$. $func$ is the function you want to use to apply / query on a interval. (Say rangeApply / rangeAsk of Segment tree.)
 * Time: O(|T|) for building. O(\log N) for lca. O(\log |T| \cdot A) for chainApply / chainAsk, where $A$ is the running time of $func$ in chainApply / chainAsk.
 * Status: tested on https://codeforces.com/contest/487/problem/E.
 */

struct HLD {
	int n;
	vi fa, hson, dfn, dep, top;
	HLD(vvi &g, int rt = 0): n(sz(g)), fa(n, -1), hson(n, -1), dfn(n), dep(n, 0), top(n) {
		vi siz(n);
		auto dfs = [&](auto &dfs, int now) -> void {
			siz[now] = 1;
			int mx = 0;
			for (auto v: g[now]) if (v != fa[now]) {
				dep[v] = dep[now] + 1;
				fa[v] = now;
				dfs(dfs, v);
				siz[now] += siz[v];
				if (mx < siz[v]) {
					mx = siz[v];
					hson[now] = v;
				}
			}
		};
		dfs(dfs, rt);

		int cnt = 0;
		auto getdfn = [&](auto &dfs, int now, int sp) {
			top[now] = sp;
			dfn[now] = cnt++;
			if (hson[now] == -1) return;
			dfs(dfs, hson[now], sp);
			for (auto v: g[now]) {
				if(v != hson[now] && v != fa[now]) dfs(dfs, v, v);
			}
		};
		getdfn(getdfn, rt, rt);
	}

	int lca(int u, int v) {
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) swap(u, v);
			u = fa[top[u]];
		}
		if (dep[u] < dep[v]) return u;
		else return v;
	}

	template<class... T>
	void chainApply(int u, int v, const function<void(int, int, T...)> &func, const T&... val) {
		int f1 = top[u], f2 = top[v];
		while (f1 != f2) {
			if (dep[f1] < dep[f2]) swap(f1, f2), swap(u, v);
			func(dfn[f1], dfn[u], val...);
			u = fa[f1]; f1 = top[u];
		}
		if (dep[u] < dep[v]) swap(u, v);
		func(dfn[v], dfn[u], val...); // change here if you want the info on edges.
	}

	template<class T>
	T chainAsk(int u, int v, const function<T(int, int)> &func) {
		int f1 = top[u], f2 = top[v];
		T ans{};
		while (f1 != f2) {
			if (dep[f1] < dep[f2]) swap(f1, f2), swap(u, v);
			ans = ans + func(dfn[f1], dfn[u]);
			u = fa[f1]; f1 = top[u];
		}
		if (dep[u] < dep[v]) swap(u, v);
		ans = ans + func(dfn[v], dfn[u]); // change here if you want the info on edges.
		return ans;
	}
};

const int inf = 0x3f3f3f3f;

struct Min {
	int x;
	Min(int a = inf): x(a) {}
	friend Min operator +(Min a, Min b) { return min(a.x, b.x); }
};
void apply(Min &a, int b) { a.x = b; }

/**
 * Author: Yuhao Yao
 * Date: 22-09-13
 * Description: Segment tree. Point apply and thus no lazy propogation.
 * Usage: Always define a global apply function for class $Info$ you use to tell segment tree how you apply modification.
 *  Combine is set as plus so if you just let T be numerical type then you have range sum in the info and as range query result. To have something different, say rangeMin, define a struct with constructer and + operation.
 * Time: O(\log N) per operation.
 * Status: tested on https://qoj.ac/contest/695/problem/1856, https://codeforces.com/contest/487/problem/E.
 */

template<class Info> struct Segtree {
	#define ls i * 2
	#define rs i * 2 + 1

	int n; 
	vector<Info> info;

	Segtree(const vector<Info> &init): n(sz(init)) {
		assert(n > 0);
		info.resize(4 << __lg(n));
		auto build = [&](auto dfs, int i, int l, int r) {
			if (l == r) {
				info[i] = init[l];
				return;
			}
			int mid = (l + r) >> 1;
			dfs(dfs, ls, l, mid);
			dfs(dfs, rs, mid + 1, r);
			pull(i);
		};
		build(build, 1, 0, n - 1);
	}
	void pull(int i) { info[i] = info[ls] + info[rs]; }
	
	template<class... T>
	void pointApply(int p, const T&... val) {
		auto dfs = [&](auto dfs, int i, int l, int r) {
			if (p < l || r < p) return;
			if (l == r) {
				::apply(info[i], val...);
				return;
			}
			int mid = (l + r) >> 1;
			dfs(dfs, ls, l, mid);
			dfs(dfs, rs, mid + 1, r);
			pull(i);
		};
		dfs(dfs, 1, 0, n - 1);
	}
	Info rangeAsk(int ql, int qr) {
		Info res{};
		auto dfs = [&](auto dfs, int i, int l, int r) {
			if (qr < l || r < ql) return;
			if (ql <= l && r <= qr) {
				res = res + info[i];
				return;
			}
			int mid = (l + r) >> 1;
			dfs(dfs, ls, l, mid);
			dfs(dfs, rs, mid + 1, r);
		};
		dfs(dfs, 1, 0, n - 1);
		return res;
	}
	#undef ls
	#undef rs
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, q; cin >> n >> m >> q;
	vi as(n);
	for (auto &x: as) cin >> x;
	vector<pii> es(m);
	for (auto &[x, y]: es) {
		cin >> x >> y;
		x--, y--;
	}
	VertexBCC bc(n, es);
	int tot = n + bc.bcc;
	auto &bf = bc.bf;
	vvi g(tot);
	for (auto [x, y]: bf) {
		g[x].push_back(y);
		g[y].push_back(x);
	}
	HLD hld(g);
	auto &dfn = hld.dfn;
	auto &fa = hld.fa;
	vector<Min> init(tot);
	vector<multiset<int>> S(tot);
	rep(i, 0, n - 1) if (fa[i] != -1) {
		auto f = fa[i];
		chmin(init[dfn[f]].x, as[i]);
		S[f].insert(as[i]);
	}
	// debug(dfn);
	// rep(i, 0, tot - 1) debug(i, init[i].x);
	Segtree<Min> seg(init);
	while (q--) {
		char op; cin >> op;
		if (op == 'C') {
			int x, v; cin >> x >> v;
			x--;
			if (fa[x] != -1) {
				int f = fa[x];
				S[f].erase(S[f].find(as[x]));
			}
			as[x] = v;
			if (fa[x] != -1) {
				int f = fa[x];
				S[f].emplace(as[x]);
				function<void(int, int, int)> func = [&](int l, int r, int x) {
					assert(l == r);
					seg.pointApply(l, x);
				};
				hld.chainApply(f, f, func, *S[f].begin());
			}
		} else {
			int u, v; cin >> u >> v;
			u--, v--;
			function<Min(int l, int r)> func = [&](int l, int r) {
				return seg.rangeAsk(l, r);
			};
			Min res = hld.chainAsk(u, v, func);
			int lca = hld.lca(u, v);
			if (lca >= n) {
				int f = fa[lca];
				res = res + Min{as[f]};
			} else res = res + Min{as[lca]};
			printf("%d\n", res.x);
		}
	}
	return 0;
}