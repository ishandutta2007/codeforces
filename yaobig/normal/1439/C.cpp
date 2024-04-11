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
using db = double;

template<class T, T INF = numeric_limits<T>::max()> struct Segtree {
	#define ls i * 2
	#define rs i * 2 + 1

	const int n, N;
	vector<T> mn, mx, sum, tag;
	Segtree(const vector<T> &init): n(sz(init)), N(4 << __lg(n)), mn(N), mx(N), sum(N), tag(N) {
		assert(n > 0); 
		function<void(int, int, int)> build = [&](int i, int l, int r) {
			if (l == r) {
				mn[i] = mx[i] = sum[i] = init[l];
			} else {
				int mid = (l + r) >> 1;
				build(ls, l, mid);
				build(rs, mid + 1, r);
				pull(i);
			}
		};
		build(1, 0, n - 1);
	}
	void pull(int i) {
		mx[i] = max(mx[ls], mx[rs]);
		mn[i] = min(mn[ls], mn[rs]);
		sum[i] = sum[ls] + sum[rs];
	}

	void apply(int i, int l, int r, T x) {
		tag[i] = x;
		mn[i] = x;
		mx[i] = x;
		sum[i] = x * (r - l + 1);
	}

	void push(int i, int l, int r) {
		if (tag[i]) {
			int mid = (l + r) >> 1;
			apply(ls, l, mid, tag[i]);
			apply(rs, mid + 1, r, tag[i]);
			tag[i] = 0;
		}
	}

	void Upd(int ql, int qr, T x) {
		auto dfs = [&](auto dfs, int i, int l, int r) -> void {
			if (qr < l || r < ql || mn[i] > x) return;
			if (ql <= l && r <= qr && mx[i] <= x) {
				apply(i, l, r, x);
				return;
			}
			push(i, l, r);
			int mid = (l + r) >> 1;
			dfs(dfs, ls, l, mid);
			dfs(dfs, rs, mid + 1, r);
			pull(i);
		};
		dfs(dfs, 1, 0, n - 1);
	}
	int cnt = 0;
	auto Ask(int ql, int qr, T y) {
		auto dfs = [&](auto dfs, int i, int l, int r) -> int {
			cnt++;
			if (r < ql || qr < l || y < mn[i]) return 0;
			if (ql <= l && l <= qr && y >= sum[i]) {
				y -= sum[i];
				return r - l + 1;
			}
			push(i, l, r);
			int mid = (l + r) >> 1;
			return dfs(dfs, ls, l, mid) + dfs(dfs, rs, mid + 1, r);
		};
		return dfs(dfs, 1, 0, n - 1);
	}

	#undef ls
	#undef rs
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, q; cin >> n >> q;
	vector<ll> as(n);
	for (auto &x: as) cin >> x;
	Segtree<ll> segt(as);
	while (q--) {
		int op, x, y; cin >> op >> x >> y;
		x--;
		if (op == 1) segt.Upd(0, x, y);
		else printf("%d\n", segt.Ask(x, n - 1, y));
	}
	if (segt.cnt > 1.5e8) assert(0);
	return 0;
}