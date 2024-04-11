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

template<class T, T INF = numeric_limits<T>::max()> class Segtree {
	#define ls i * 2
	#define rs i * 2 + 1

	int n;
	vector<pair<T, int>> dat;
	vector<T> tag;
public:
	Segtree(const vector<T> &a): n(sz(a)), dat(4 << __lg(n)), tag(4 << __lg(n)) {
		assert(n > 0); 
		function<void(int, int, int)> build = [&](int i, int l, int r) {
			if (l == r) dat[i] = {a[l], l};
			else {
				int mid = (l + r) >> 1;
				build(ls, l, mid);
				build(rs, mid + 1, r);
				pull(i);
			}
		};
		build(1, 0, n - 1);
	}
private:
	void pull(int i) { dat[i] = min(dat[ls], dat[rs]); } // change here if you want maximum value / the rightist index.
	void apply(int i, T x) {
		tag[i] += x;
		dat[i].first += x;
	}
	void push(int i) {
		if (tag[i]) {
			apply(ls, tag[i]);
			apply(rs, tag[i]);
			tag[i] = 0;
		}
	}
	void add(int i, int l, int r, int ql, int qr, T x) {
		if (qr < l || r < ql) return;
		if (ql <= l && r <= qr) {
			apply(i, x);
			return;
		}
		push(i);
		int mid = (l + r) >> 1;
		add(ls, l, mid, ql, qr, x);
		add(rs, mid + 1, r, ql, qr, x);
		pull(i);
	}
	pair<T, int> ask(int i, int l, int r, int ql, int qr) {
		if (qr < l || r < ql) return make_pair(INF, -1);
		if (ql <= l && r <= qr) return dat[i];
		push(i);
		int mid = (l + r) >> 1;
		return min(ask(ls, l, mid, ql, qr), ask(rs, mid + 1, r, ql, qr)); // change here if you want maximum value / the rightist index.
	}
	int bound(int i, int l, int r, T x) {
		if (l == r) return l;
		push(i);
		int mid = (l + r) >> 1;
		if (dat[rs].first < 0) return bound(rs, mid + 1, r, x);
		else return bound(ls, l, mid, x);
	}
public:
	void rangeAdd(int ql, int qr, T x) { add(1, 0, n - 1, ql, qr, x); }
	auto rangeMin(int ql, int qr) { return ask(1, 0, n - 1, ql, qr); }
	int bound(T x) { return bound(1, 0, n - 1, x); }

	#undef ls
	#undef rs
};

int main() {
	ios:: sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vi as(n), bs(m);
	vi vec;
	for (auto &x: as) cin >> x, vec.push_back(x);
	for (auto &x: bs) cin >> x, vec.push_back(x);
	
	struct qnode { int op, id, x; };
	int Q; cin >> Q;
	vector<qnode> qs(Q);
	for (auto &[op, id, x]: qs) {
		cin >> op >> id >> x;
		id--;
		vec.push_back(x);
	}
	sort(all(vec));
	vec.erase(unique(all(vec)), vec.end());
	auto getid = [&](int x) { return lower_bound(all(vec), x) - vec.begin(); };
	for (auto &x: as) x = getid(x);
	for (auto &x: bs) x = getid(x);
	for (auto &[op, id, x]: qs) x = getid(x);

	int N = sz(vec);
	vi init(N);
	for (auto x: as) init[x]--;
	for (auto x: bs) init[x]++;
	revrep(i, 1, N - 1) init[i - 1] += init[i];

	Segtree segt(init);
	for (auto [op, id, x]: qs) {
		if (op == 1) {
			segt.rangeAdd(0, as[id], 1);
			as[id] = x;
			segt.rangeAdd(0, as[id], -1);
		} else {
			segt.rangeAdd(0, bs[id], -1);
			bs[id] = x;
			segt.rangeAdd(0, bs[id], 1);
		}
		if (segt.rangeMin(0, N - 1).first >= 0) puts("-1");
		else {
			int pos = segt.bound(0);
			printf("%d\n", vec[pos]);
		}
	}

	return 0;
}