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
	ios:: sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vvi g(n);
	rep(i, 1, n - 1) {
		int x, y; cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	auto sqr = [](ll x) { return x * x; };

	ll mnans = 1ll << 60;
	vi siz(n);
	vector<ll> dp(n);
	function<void(int, int)> dfs = [&](int now, int fa) {
		siz[now] = 1;
		for (auto v: g[now]) if (v != fa) {
			dfs(v, now);
			siz[now] += siz[v];
		}
		ll best = sqr(siz[now]);
		for (auto v: g[now]) if (v != fa) {
			chmin(best, sqr(siz[now] - siz[v]) + dp[v]);
			chmin(mnans, dp[v] + sqr(n - siz[v]));
		}
		dp[now] = best;
		// hard case: two branches.
		vector<pair<ll, ll>> ps;
		for (auto v: g[now]) if (v != fa) {
			ps.push_back(pair<ll, ll>{siz[v], dp[v]});
		}
		sort(all(ps));
		vector<pair<ll, ll>> vec;
		for (auto p: ps) {
			if (sz(vec) >= 2 && vec.end()[-2].first == p.first) continue;
			vec.push_back(p);
		}
		rep(i, 0, sz(vec) - 1) rep(j, 0, i - 1) {
			auto [siz1, dp1] = vec[i];
			auto [siz2, dp2] = vec[j];
			chmin(mnans, dp1 + dp2 + sqr(n - siz1 - siz2));
		}
	};
	dfs(0, -1);
	ll ans = 1ll * n * (n - 1) - (mnans - n) / 2;
	printf("%lld\n", ans);
	return 0;
}