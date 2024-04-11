#include "bits/stdc++.h"
#define rep(i, a, n) for (auto i = a; i <= (n); ++i)
#define revrep(i, a, n) for (auto i = n; i >= (a); --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
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

/**
 * Author: Yuhao Yao
 * Date: 22-09-08
 * Description: Cartesian Tree of array $as$ (of distinct values). Node with smaller depth has smaller value. Set $gr = 1$ to have top with the greatest value.
 * Time: O(N) for construction.
 * Status: Tested on https://qoj.ac/contest/695/problem/1857, https://codeforces.com/gym/103371/problem/M, https://codeforces.com/contest/1718/problem/D.
 */

template<class T>
auto CartesianTree(const vector<T> &as, int gr = 0) {
	int n = sz(as);
	vi ls(n, -1), rs(n, -1), sta;
	rep(i, 0, n - 1) {
		while (sz(sta) && ((as[i] < as[sta.back()]) ^ gr)) {
			ls[i] = sta.back();
			sta.pop_back();
		}
		if (sz(sta)) rs[sta.back()] = i;
		sta.push_back(i);
	}
	return make_tuple(sta[0], ls, rs);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int cas; cin >> cas; while (cas--) {
		int n, q; cin >> n >> q;
		vi as(n), ps(n); 
		for (auto &x: ps) cin >> x;
		for (auto &x: as) cin >> x;
		int k = count(all(as), 0);
		vi ss(k - 1);
		for (auto &x: ss) cin >> x;
		vi ds(q);
		for (auto &x: ds) cin >> x;

		auto [rt, ls, rs] = CartesianTree(ps, 1);
		vi highs(n), lows(n);
		auto dfs = [&](auto dfs, int l, int r, int mid, int hi) {
			if (l > r) return 0;
			int lo = as[mid];
			if (as[mid] != 0) chmin(hi, as[mid]);
			chmax(lo, dfs(dfs, l, mid - 1, ls[mid], hi));
			chmax(lo, dfs(dfs, mid + 1, r, rs[mid], hi));
			lows[mid] = lo;
			highs[mid] = hi;
			return lo;
		};
		const int inf = 0x3f3f3f3f;
		dfs(dfs, 0, n - 1, rt, inf);

		int ok = 1;
		int L = 0, R = inf;
		rep(i, 0, n - 1) if (lows[i] > highs[i]) ok = 0;
		if (ok) {
			vector<pii> segs;
			rep(i, 0, n - 1) if (as[i] == 0) segs.emplace_back(lows[i], highs[i]);
			sort(all(ss));
			sort(all(segs), [](pii a, pii b) { return a.first < b.first; });
			auto ptr = segs.begin();
			multiset<int> S;
			for (auto t: ss) {
				while (ptr != segs.end() && ptr->first <= t) {
					S.insert(ptr->second);
					ptr++;
				}
				auto it = S.lower_bound(t);
				if (it != S.end()) S.erase(it);
			}
			while (ptr != segs.end()) {
				S.insert(ptr->second);
				ptr++;
			}
			if (sz(S) > 1) ok = 0;
			else R = *S.begin();

			reverse(all(ss));
			sort(all(segs), [](pii a, pii b) { return a.second > b.second; });
			ptr = segs.begin();
			S.clear();
			for (auto t: ss) {
				while (ptr != segs.end() && ptr->second >= t) {
					S.insert(ptr->first);
					ptr++;
				}
				auto it = S.upper_bound(t);
				if (it != S.begin()) S.erase(prev(it));
			}
			while (ptr != segs.end()) {
				S.insert(ptr->first);
				ptr++;
			}
			if (sz(S) > 1) ok = 0;
			else L = *S.begin();
		}
		for (auto x: ds) puts(ok && L <= x && x <= R ? "YES" : "NO");
	}
	return 0;
}