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

auto EdgeBCC(int n, const vector<pii> &es, int st = 0) {
	vi dfn(n, -1), low(n), id(n), mark(sz(es), 0), sta;
	int cnt = 0, bcc = 0;
	vvi g(n);
	rep(ind, 0, sz(es) - 1) {
		auto [x, y] = es[ind];
		g[x].push_back(ind);
		g[y].push_back(ind);
	}

	vi ori(sz(es));
	auto dfs = [&](auto dfs, int now) -> void {
		low[now] = dfn[now] = cnt++;
		sta.push_back(now);
		for (auto ind: g[now]) if (mark[ind] == 0) {
			mark[ind] = 1;
			auto [x, y] = es[ind];
			ori[ind] = now == x ? 1 : -1;
			int v = now ^ x ^ y;
			if (dfn[v] == -1) {
				dfs(dfs, v);
				low[now] = min(low[now], low[v]);
			} else low[now] = min(low[now], dfn[v]);
		}
		if (low[now] == dfn[now]) {
			while (sta.back() != now) {
				id[sta.back()] = bcc;
				sta.pop_back();
			}
			id[now] = bcc;
			sta.pop_back();
			bcc++;
		}
	};
	dfs(dfs, st);
	return make_tuple(bcc, id, ori);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector<pii> es(m);
	for (auto &[x, y]: es) {
		cin >> x >> y;
		x--, y--;
	}
	auto [bcc, ids, _] = EdgeBCC(n, es, 0);
	vi siz(bcc);
	for (auto id: ids) siz[id]++;
	int best = max_element(all(siz)) - siz.begin();
	int st = -1;
	rep(i, 0, n - 1) if (ids[i] == best) { st = i; break; }
	auto [_1, _2, ori] = EdgeBCC(n, es, st);
	printf("%d\n", siz[best]);
	rep(i, 0, m - 1) {
		auto [x, y] = es[i];
		if (ori[i] == -1) printf("%d %d\n", x + 1, y + 1);
		else printf("%d %d\n", y + 1, x + 1);
	}
	return 0;
}