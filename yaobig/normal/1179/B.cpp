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

	int n, m; cin >> n >> m;
	auto getvec = [&](int n) {
		vi as(n); iota(all(as), 0);
		deque<int> dq(all(as));
		vi ord;
		while (sz(dq)) {
			if (sz(dq)) ord.push_back(dq.front()), dq.pop_front();
			if (sz(dq)) ord.push_back(dq.back()), dq.pop_back();
		};
		return ord;
	};
	vi ord = getvec(m);
	vi deord(ord), tmp(ord);
	reverse(all(tmp));
	deord.insert(deord.end(), all(tmp));
	vi vec = getvec(n);
	reverse(all(vec));

	vector<pii> ans;
	while (sz(vec) >= 2) {
		int a = vec.back(); vec.pop_back();
		int b = vec.back(); vec.pop_back();
		rep(i, 0, m * 2 - 1) ans.push_back({i & 1 ? b : a, deord[i]});
	}
	if (sz(vec)) {
		int a = vec.back(); vec.pop_back();
		for (auto x: ord) ans.push_back({a, x});
	}
	for (auto [x, y]: ans) printf("%d %d\n", x + 1, y + 1);
	return 0;
}