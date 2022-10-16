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

template<const int &mod_> struct Z {
	/// start-hash
	static constexpr const int &mod = mod_;
	int x;
	Z(ll a = 0): x(a % mod) { if (x < 0) x += mod; }

	static int norm(int x) { return x < 0 ? x + mod : x >= mod ? x - mod : x; }
	friend Z operator +(Z a, Z b) { a.x = norm(a.x + b.x); return a; }
	friend Z operator -(Z a, Z b) { a.x = norm(a.x - b.x); return a; }
	friend Z operator *(Z a, Z b) { a.x = 1ll * a.x * b.x % mod; return a; }
	/// end-hash

	// the following are needed for fft and polynomial operations.
	/// start-hash
	Z& operator +=(Z b) { x = norm(x + b.x); return *this; }
	Z& operator -=(Z b) { x = norm(x - b.x); return *this; }
	Z& operator *=(Z b) { x = 1ll * x * b.x % mod; return *this; }

	static Z pow(Z a, ll k) {
		Z res = 1;
		for (; k; k >>= 1, a = a * a) if (k & 1) res = res * a;
		return res;
	}
	friend Z operator /(Z a, Z b) { return a * pow(b, mod - 2); }
	/// end-hash

	friend string to_string(Z a) { return to_string(a.x); } // just for debug.
};

const int mod = 1e9 + 7;
using Mint = Z<mod>;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int cas; cin >> cas; while (cas--) {
		int n; cin >> n;
		vi as(n);
		for (auto &x: as) cin >> x;

		vi pos(n);
		rep(i, 0, n - 1) pos[as[i]] = i;
		int l = pos[0], r = pos[0];
		int free = 0;
		Mint ans = 1;
		
		rep(i, 1, n - 1) {
			int p = pos[i];
			if (l <= p && p <= r) {
				ans *= free--;
			} else {
				while (p < l) l--, free++;
				while (r < p) r++, free++;
				free--;
			}
		}
		printf("%d\n", ans.x);
	}
	return 0;
}