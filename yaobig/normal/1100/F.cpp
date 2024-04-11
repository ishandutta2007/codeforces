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

template<int LG, class T = bitset<LG>, class Z = int> struct LB {
	/// start-hash
	#define revrep(i, a, n) for (auto i = n; i >= (a); --i)
	vector<T> a;
	vector<Z> w;

	T& operator [](int i) const { return (T&)a[i]; }
	LB(): a(LG), w(LG) {}
	
	// insert x. return 1 if the base is expanded.
	int insert(T x, Z val = 0) {
		revrep(i, 0, LG - 1) if (x[i]) {
			if (a[i] == 0) {
				a[i] = x;
				w[i] = val;
				return 1;
			} else if (val > w[i]) {
				swap(a[i], x);
				swap(w[i], val);
			}
			x ^= a[i];
		}
		return 0;
	} /// end-hash

	// min value we can get if we add vectors from linear base (with weight at least $val$) to $x$.
	T ask_max(T x, Z val = 0) { /// start-hash
		revrep(i, 0, LG - 1) {
			if (x[i] == 0 && w[i] >= val) x ^= a[i]; // change x[i] to x[i] == 0 to ask maximum value we can get.
		}
		return x;
	} /// end-hash
};
using Base = LB<20>;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vi cs(n);
	for (auto &x: cs) cin >> x;

	struct node { int l, qid; };
	vector<vector<node>> qpool(n);

	int Q; cin >> Q; 
	vi ans(Q);
	rep(qid, 0, Q - 1) {
		int l, r; cin >> l >> r;
		l--, r--;
		qpool[r].push_back({l, qid});
	}
	Base A;
	rep(r, 0, n - 1) {
		A.insert(cs[r], r);
		for (auto [l, qid]: qpool[r]) ans[qid] = A.ask_max(0, l).to_ullong();
	}
	for (auto &x: ans) printf("%d\n", x);
	return 0;
}