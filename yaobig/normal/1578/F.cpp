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
 * Date: 22-09-09
 * Description: For an edge set $E$ such that each vertex has an even degree, compute Euler tour for each connected component.
 *  Note that this is a non-recursive implementation, which avoids stack size issue on some OJ and also saves memory due to that.
 * Time: $O(|V| + |E|)$.
 * Status: tested on https://acm.hdu.edu.cn/showproblem.php?pid=7261, https://ac.nowcoder.com/acm/contest/4010/H.
 */

struct EulerTour {
	int n;
	vector<vi> tours;
	vi ori;

	EulerTour(int n, const vector<pii> &es, int dir): n(n), ori(sz(es)) {
		vector<vi> g(n);
		int m = 0;
		for (auto [x, y]: es) {
			g[x].push_back(m);
			if (!dir) g[y].push_back(m);
			m++;
		}

		vi path, cur(n);
		vector<pii> sta;
		auto solve = [&](int st) {
			sta.emplace_back(st, -1);
			while (sz(sta)) {
				auto [now, pre] = sta.back();
				int fin = 1;
				for (int &i = cur[now]; i < sz(g[now]); ) {
					auto ind = g[now][i++];
					if (ori[ind]) continue;
					auto [x, y] = es[ind];
					ori[ind] = x == now ? 1 : -1;
					int v = now ^ x ^ y;
					sta.emplace_back(v, ind);
					fin = 0;
					break;
				}
				if (fin) {
					if (pre != -1) path.push_back(pre);
					sta.pop_back();
				}
			}
		};

		rep(i, 0, n - 1) {
			path.clear();
			solve(i);
			if (sz(path)) {
				reverse(all(path));
				tours.push_back(path);
			}
		}
	}

	vector<vi> getTours() { return tours; }

	vi getOrient() { return ori; }
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	if (n & 1) {
		puts("-1");
		return 0;
	}
	int k = n / 2;
	vector<pii> es;
	vi acts;
	rep(i, 0, k - 1) {
		revrep(j, 0, 1) {
			int act = (i * 2 + j) % n;
			acts.push_back(act);
			int to = act % k;
			es.emplace_back(i, to);
		}
	}
	EulerTour et(k, es, 1);
	auto tours = et.getTours();
	vi ans{0};
	for (auto eid: tours[0]) ans.push_back(acts[eid]);
	rep(i, 0, sz(ans) - 1) printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);
	return 0;
}