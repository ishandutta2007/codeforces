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

const int N = 200200;
int n, m;
int ANS[N];
int g[N];
vector<int> G[N];
int deg[N];
int q[N];
int topQ;
int id[N];
vector<int> a[N];
vector<pli> Q[N];
vector<pii> b[N];
vector<int> pref[N];

void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &g[i]);
		g[i]--;
		deg[g[i]]++;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		ll x;
		int v;
		scanf("%lld%d", &x, &v);
		v--;
		Q[v].push_back(mp(x, i));
	}
}

void solveTree(int v) {
	int big = -1;
	for (int u : G[v]) {
		if (big == -1 || (int)a[id[u]].size() > (int)a[id[big]].size())
			big = u;
	}
	if (big == -1) {
		id[v] = v;
	} else {
		id[v] = id[big];
	}
	int sz = (int)a[id[v]].size();
	for (int u : G[v]) {
		if (u == big) continue;
		int z = id[u];
		reverse(a[z].begin(), a[z].end());
		for (int i = 0; i < (int)a[z].size(); i++)
			a[id[v]][sz - 1 - i] += a[z][i];
	}
	a[id[v]].push_back(1);
	for (pli t : Q[v]) {
		ll x = t.first;
		if (x <= sz)
			ANS[t.second] = a[id[v]][sz - x];
	}
	int u = g[v];
	G[u].push_back(v);
	deg[u]--;
	if (deg[u] == 0) q[topQ++] = u;
}

void solveCycle(vector<int> cycle) {
	reverse(cycle.begin(), cycle.end());
	int k = (int)cycle.size();
	for (int i = 0; i < k; i++) {
		b[i].clear();
		pref[i].clear();
	}
	for (int t = 0; t < k; t++) {
		int v = cycle[t];
		int big = -1;
		for (int u : G[v]) {
			if (big == -1 || (int)a[id[u]].size() > (int)a[id[big]].size())
				big = u;
		}
		if (big == -1) {
			id[v] = v;
		} else {
			id[v] = id[big];
		}
		int sz = (int)a[id[v]].size();
		for (int u : G[v]) {
			if (u == big) continue;
			int z = id[u];
			reverse(a[z].begin(), a[z].end());
			for (int i = 0; i < (int)a[z].size(); i++)
				a[id[v]][sz - 1 - i] += a[z][i];
		}
		a[id[v]].push_back(1);
		reverse(a[id[v]].begin(), a[id[v]].end());
		for (int i = 0; i <= sz; i++) {
			int p = (t + i) % k;
			b[p].push_back(mp(i, a[id[v]][i]));
		}
	}
	for (int i = 0; i < k; i++) {
		sort(b[i].begin(), b[i].end());
		pref[i].push_back(0);
		for (pii t : b[i])
			pref[i].push_back(pref[i].back() + t.second);
	}
	for (int t = 0; t < k; t++) {
		int v = cycle[t];
		for (pli z : Q[v]) {
			ll x = z.first;
			int xx;
			if (x > (ll)1e7) {
				xx = x - ((x - (ll)1e7) / k) * k;
			} else {
				xx = x;
			}
			int p = (xx + t) % k;
			int pos = lower_bound(b[p].begin(), b[p].end(), mp(xx, N)) - b[p].begin();
			ANS[z.second] = pref[p][pos];
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	for (int v = 0; v < n; v++)
		if (deg[v] == 0)
			q[topQ++] = v;
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		solveTree(v);
	}
	for (int v = 0; v < n; v++) {
		if (deg[v] == 0) continue;
		vector<int> all;
		int u = v;
		do {
			all.push_back(u);
			u = g[u];
		} while(u != v);
		solveCycle(all);
		for (int u : all) deg[u] = 0;
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", ANS[i]);

	return 0;
}