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
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using db = double;

template<int &mod> struct Z { /// start-hash
	int x;
	Z(ll a = 0): x(a % mod) { if (x < 0) x += mod; }

	static int norm(int x) { return x < 0 ? x + mod : x >= mod ? x - mod : x; }
	friend Z operator +(Z a, Z b) { a.x = norm(a.x + b.x); return a; }
	friend Z operator -(Z a, Z b) { a.x = norm(a.x - b.x); return a; }
	friend Z operator *(Z a, Z b) { a.x = 1ll * a.x * b.x % mod; return a; }
	/// end-hash

	Z& operator +=(Z b) { x = norm(x + b.x); return *this; }
	Z& operator -=(Z b) { x = norm(x - b.x); return *this; }

	static Z power(Z a, ll k) { /// start-hash
		Z res = 1;
		for (; k; k >>= 1, a = a * a) if (k & 1) res = res * a;
		return res;
	}
	friend Z operator /(Z a, Z b) { return a * power(b, mod - 2); }
	/// end-hash

	friend string to_string(Z a) { return to_string(a.x); }
};

int mod;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m; cin >> n >> m >> mod;
	using Mint = Z<mod>;
	const int maxn = 500;
	
	vector<vector<Mint>> binom(maxn + 1, vector<Mint>(maxn + 1));
	rep(i, 0, maxn) {
		binom[i][0] = 1;
		rep(j, 1, i) binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
	}

	vector<Mint> cnt(m + 1), sum(m + 1);
	cnt[0] = 1;
	sum[0] = 0;
	rep(i, 1, m) rep(j, 0, i - 1) {
		cnt[i] += binom[i - 1][j] * cnt[j] * cnt[i - 1 - j] * (i + 1);
		sum[i] += binom[i - 1][j] * (cnt[j] * cnt[i - 1 - j] * (binom[j + 1][2] + binom[i - j][2])
									+ (sum[j] * cnt[i - 1 - j] + cnt[j] * sum[i - 1 - j]) * (i + 1));
	}
	vector<vector<Mint>> f(n + 1, vector<Mint>(n + 1)), g(f);
	f[0][0] = 1;
	g[0][0] = 0;
	rep(i, 1, n) {
		rep(j, 0, i - 1) {
			rep(k, 0, j) {
				f[i][j] += binom[j][k] * f[i - 1 - k][j - k] * cnt[k];
				g[i][j] += binom[j][k] * (f[i - 1 - k][j - k] * sum[k] + g[i - 1 - k][j - k] * cnt[k]);
			}
		}
		f[i][i] = cnt[i];
		g[i][i] = sum[i];
	}
	printf("%d\n", g[n][m].x);
	return 0;
}