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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair

const int B = 1000;
const ll INF = (ll)1e16;
const ll C = (ll)1e5 + 3;
const int N = 100010;
int n;
vector<int> g[N];
ll dp[N];

struct Line {
	ll k, b;

	Line() : k(), b() {}
	Line(ll _k, ll _b) : k(_k), b(_b) {}

	ll getVal(const ll &x) const {
		return k * x + b;
	}

	ll startDom(const Line &L) const {
		if (k <= L.k) throw;
		ll x = (L.b - b) / (k - L.k);
		while(getVal(x) < L.getVal(x)) x++;
		while(getVal(x) >= L.getVal(x)) x--;
		x++;
		return x;
	}

	void print() {
		printf("(%lld x + %lld) ", k, b);
	}
};

struct Hull {
	vector<Line> lines;
	vector<ll> stDom;

	Hull() : lines(), stDom() {}
	Hull(vector<pll> a) {
		lines.clear();
		stDom.clear();
		if (a.empty()) return;
		sort(a.begin(), a.end());
		for (pll t : a) {
			Line L = Line(t.first, t.second);
			while(!lines.empty() && L.getVal(stDom.back()) >= lines.back().getVal(stDom.back())) {
				lines.pop_back();
				stDom.pop_back();
			}
			if (lines.empty()) {
				lines.push_back(L);
				stDom.push_back(-C);
				continue;
			}
			if (L.getVal(C) < lines.back().getVal(C)) continue;
			stDom.push_back(L.startDom(lines.back()));
			lines.push_back(L);
		}
	}

	ll getVal(ll x) {
		int pos = upper_bound(stDom.begin(), stDom.end(), x) - stDom.begin() - 1;
		return lines[pos].getVal(x);
	}

	void print() {
		printf("Hull\n");
		for (int i = 0; i < (int)lines.size(); i++) {
			lines[i].print();
			printf(" %lld\n", stDom[i]);
		}
	}
};

int id[N];
Hull hull[N];
int m;
vector<pll> ones[N];
vector<int> hulls[N];
ll a[N], b[N];

void dfs(int v, int par) {
	int big = -1;
	id[v] = v;
	for (int u : g[v]) {
		if (u == par) continue;
		dfs(u, v);
		if (big == -1 || ones[id[big]].size() < ones[id[u]].size())
			big = u;
	}
	if (big == -1) {
		dp[v] = 0;
		ones[v].push_back(mp(b[v], dp[v]));
		return;
	}
	int ID = id[v] = id[big];
	for (int u : g[v]) {
		if (u == big || u == par) continue;
		for (int x : hulls[id[u]])
			hulls[ID].push_back(x);
		for (pll x : ones[id[u]])
			ones[ID].push_back(x);
	}
	if (ones[ID].size() >= B) {
		hulls[ID].push_back(m);
		hull[m++] = Hull(ones[ID]);
		ones[ID].clear();
	}
	dp[v] = -INF;
//	printf("v = %d\n", v);
	for (int t : hulls[ID]) {
//		hull[t].print();
		dp[v] = max(dp[v], hull[t].getVal(a[v]));
	}
	for (pll t : ones[ID])
		dp[v] = max(dp[v], a[v] * t.first + t.second);
	ones[ID].push_back(mp(b[v], dp[v]));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		a[i] *= -1;
	}
	for (int i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
	for (int i = 0; i < n; i++)
		printf("%lld ", -dp[i]);
	printf("\n");

	return 0;
}