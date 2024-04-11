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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int cas; cin >> cas; while (cas--) {
		int n; cin >> n;
		vi as(n);
		for (auto &x: as) cin >> x, x--;

		vvi ok(n, vi(n, 1));
		vi cnt;
		rep(l, 0, n - 1) {
			cnt.assign(n, 0);
			int mx = 0;
			rep(r, l, n - 1) {
				int a = as[r];
				cnt[a]++;
				chmax(mx, cnt[a]);
				ok[l][r] = mx * 2 <= r - l + 1;
			}
		}	

		const int inf = 0x3f3f3f3f;
		vi dp(n, -inf);
		rep(i, 0, n - 1) {
			if (i % 2 == 0 && (i == 0 || ok[0][i - 1])) chmax(dp[i], 1);
			rep(j, 0, i - 1) if ((i - j) & 1 && as[i] == as[j] && ok[j + 1][i - 1]) chmax(dp[i], dp[j] + 1);
		}
		int ans = 0;
		rep(i, 0, n - 1) {
			if ((n - 1 - i) % 2 == 0 && (i == n - 1 || ok[i + 1][n - 1])) chmax(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}