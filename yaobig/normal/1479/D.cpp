#include "bits/stdc++.h"
#define rep(i, a, n) for (auto i = a; i <= (n); ++i)
#define revrep(i, a, n) for (auto i = n; i >= (a); --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T &a, T b) { if(a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if(b < a) { a = b; return 1; } return 0; }
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
// using LL = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;


struct Hash {
	unsigned long long val;
	Hash(unsigned long long val = 0): val(val) {}
	friend Hash operator +(Hash a, Hash b) { a.val ^= b.val; return a; }
	friend bool operator ==(Hash a, Hash b) { return a.val == b.val; }
};
void apply(Hash &a, Hash b) { a = a + b; }

template<class T> class PersistSegtree {
	struct node { T info; int ls, rs; };
	int n;
	vector<node> nds;
public:
	PersistSegtree(int n, int q): n(n), nds(1) { nds.reserve(q * (__lg(n) + 2) + 1); }
private:
	int clone(int i) {
		auto tmp = nds[i];
		nds.push_back(tmp);
		return sz(nds) - 1;
	}
	void apply(int i, T val) {
		::apply(nds[i].info, val);
	}
public:
	// return new root id.
	int pointAdd(int rt, int pos, T val) {
		auto dfs = [&](auto dfs, int &i, int l, int r) {
			i = clone(i);
			apply(i, val);

			if (l == r) return;
			int mid = (l + r) >> 1;
			if (pos <= mid) dfs(dfs, nds[i].ls, l, mid);
			else dfs(dfs, nds[i].rs, mid + 1, r);
		};
		dfs(dfs, rt, 0, n - 1);
		return rt;
	}
	
	int Find(int rt1, int rt2, int rt3, int rt4, int ql, int qr) {
		auto dfs = [&](auto dfs, int x, int y, int z, int w, int l, int r) {
			if (r < ql || qr < l || (nds[x].info + nds[y].info + nds[z].info + nds[w].info) == 0) return -1;
			if (l == r) return l;
			int mid = (l + r) >> 1;
			int res = dfs(dfs, nds[x].ls, nds[y].ls, nds[z].ls, nds[w].ls, l, mid);
			if (res != -1) return res;
			else return dfs(dfs, nds[x].rs, nds[y].rs, nds[z].rs, nds[w].rs, mid + 1, r);
		};
		return dfs(dfs, rt1, rt2, rt3, rt4, 0, n - 1);
	}
};

struct HLD {
	int n;
	vi par, hson, dfn, dep, top;
	HLD(vvi &g, int rt = 0): n(sz(g)), par(n, -1), hson(n, -1), dfn(n), dep(n, 0), top(n) {
		vi siz(n);
		function<void(int, int)> dfs = [&](int now, int fa) {
			siz[now] = 1;
			int mx = 0;
			for (auto v: g[now]) if (v != fa) {
				dep[v] = dep[now] + 1;
				par[v] = now;
				dfs(v, now);
				siz[now] += siz[v];
				if (mx < siz[v]) mx = siz[v], hson[now] = v;
			}
		};
		dfs(rt, -1);

		int cnt = 0;
		function<void(int, int)> getdfn = [&](int now, int sp) {
			top[now] = sp;
			dfn[now] = cnt++;
			if (hson[now] == -1) return;
			getdfn(hson[now], sp);
			for (auto v: g[now]) if(v != hson[now] && v != par[now]) getdfn(v, v);
		};
		getdfn(rt, rt);
	}

	int lca(int u, int v) {
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) swap(u, v);
			u = par[top[u]];
		}
		return dep[u] < dep[v] ? u : v;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, q; cin >> n >> q;
	vi as(n);
	for (auto &x: as) cin >> x, x--;

	vector<Hash> hashs(n);
	mt19937_64 rng(20000902);
	for (auto &x: hashs) x = rng();

	vvi g(n);
	rep(i, 1, n - 1) {
		int x, y; cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	HLD hld(g);
	auto &dfn = hld.dfn, &par = hld.par;
	vi ord(n);
	rep(i, 0, n - 1) ord[dfn[i]] = i;
	PersistSegtree<Hash> pseg(n, n);
	vi rts(n);
	for (auto now: ord) {
		int fa = par[now];
		int val = as[now];
		rts[now] = pseg.pointAdd(fa == -1 ? 0 : rts[fa], val, hashs[val]);
	}

	while (q--) {
		int u, v, l, r; cin >> u >> v >> l >> r;
		u--, v--, l--, r--;
		int x = hld.lca(u, v);
		int res = pseg.Find(rts[u], rts[v], rts[x], par[x] == -1 ? 0 : rts[par[x]], l, r);
		printf("%d\n", res == -1 ? -1 : res + 1);
	}
	return 0;
}