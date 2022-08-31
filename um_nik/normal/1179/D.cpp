#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Line {
	ll k, b;

	Line() : k(), b() {}
	Line (ll _k, ll _b) : k(_k), b(_b) {}

	ll getVal(ll x) {
		return k * x + b;
	}
};
struct Hull {
	vector<Line> lines;
	vector<ll> borders;

	Hull() : lines(), borders() {}

	void addLine(Line L) {
		while(!lines.empty()) {
			if (lines.back().getVal(borders.back()) >= L.getVal(borders.back())) {
				lines.pop_back();
				borders.pop_back();
			} else break;
		}
		if (lines.empty()) {
			lines.push_back(L);
			borders.push_back(0LL);
			return;
		}
		if (lines.back().k <= L.k) return;
		ll x = (L.b - lines.back().b + lines.back().k - L.k - 1) / (lines.back().k - L.k);
		lines.push_back(L);
		borders.push_back(x);
	}
	ll getMinVal(ll x) {
		int pos = upper_bound(borders.begin(), borders.end(), x) - borders.begin();
		if (pos == 0) throw;
		pos--;
		return lines[pos].getVal(x);
	}
};

const int N = 500500;
int n;
vector<int> g[N];
int sz[N];
ll dp[N];
ll ANS;

ll sqr(ll x) {
	return x * x;
}

void solve(vector<pll> a) {
	/*
	for (pll t : a)
		eprintf("(%lld %lld) ", t.first, t.second);
	eprintf("\n");
	*/
	int m = (int)a.size();
	for (int i = 0; i < m; i++)
		a[i].second -= a[i].first * (2 * n - a[i].first);
	Hull H = Hull();
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for (pll t : a) {
		if (!H.lines.empty()) {
			ANS = min(ANS, sqr(n) + t.second + H.getMinVal(t.first));
		}
		H.addLine(Line(2 * t.first, t.second));
	}
}

void dfs(int v) {
	sz[v] = 1;
	dp[v] = (ll)n * n;
	vector<pll> a;
	for (int u : g[v]) {
		if (sz[u]) continue;
		dfs(u);
		sz[v] += sz[u];
		a.push_back(mp((ll)sz[u], dp[u]));
	}
	for (pll t : a) {
		dp[v] = min(dp[v], t.second + sqr(sz[v] - t.first));
		ANS = min(ANS, t.second + sqr(n - t.first));
	}
	if (a.empty())
		dp[v] = 1;
	else
		solve(a);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	ANS = (ll)n * n;
	dfs(0);
	ll ans = (ll)n * (n - 1) / 2 + ((ll)n * n - ANS) / 2;
	printf("%lld\n", ans);

	return 0;
}