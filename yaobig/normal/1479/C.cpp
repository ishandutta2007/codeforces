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
	int L, R; cin >> L >> R;
	int X = R - L;
	
	int n = 22;
	vector<vector<pii>> g(n);
	vi ls(n), rs(n);
	int now = 0;
	rep(i, 1, n - 2) {
		ls[i] = 1 << (i - 1);
		rs[i] = (1 << i) - 1;
		revrep(j, 0, i - 1) {
			int len = rs[j] - ls[j] + 1;
			if (now + len <= X) {
				g[j].push_back({i, now + 1 - ls[j]});
				now += len;
			}
		}
	}

	rep(i, 0, n - 2) g[i].push_back({n - 1, L});
	int m = 0;
	rep(i, 0, n - 1) m += sz(g[i]);
	puts("YES");
	printf("%d %d\n", n, m);
	rep(i, 0, n - 1) for (auto [j, w]: g[i]) printf("%d %d %d\n", i + 1, j + 1, w);
	return 0;
}