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
#include <bitset>
#include <array>
#include <iomanip>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 1010;
int n;
int m;
int vis[N];
int dep[N];
vector<int> g[N];
vector<int> comp;

void dfs0(int v, int p) {
	comp.pb(v);
	for (int u : g[v]) {
		if (u == p) continue;
		dep[u] = dep[v] + 1;
		dfs0(u, v);
	}
}

void dfs1(int v, int p) {
	for (int u : g[v]) {
		if (u == p) continue;
		dep[u] = dep[v] + 1;
		dfs1(u, v);
	}
}

int main()
{
	startTime = clock();

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<pii> vec;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		comp.clear();
		dfs0(i, i);
		int mn = 1e9, who = -1;
		for (int j : comp) {
			dep[j] = 0;
			dfs1(j, j);
			int mx = 0;
			for (int p : comp) mx = max(mx, dep[p]);
			if (mx < mn) {
				mn = mx;
				who = j;
			}
		}
		vec.pb(mp(mn, who));
		for (int j : comp) vis[j] = 1;
	}
	sort(all(vec));
	vector<pii> edges;
	for (int i = 0; i + 1 < vec.size(); i++) {
		g[vec[i].se].pb(vec.back().se);
		g[vec.back().se].pb(vec[i].se);
		edges.pb(mp(vec[i].se, vec.back().se));
	}
	dep[1] = 0;
	dfs1(1, 0);
	int x = 1;
	for (int i = 2; i <= n; i++) {
		if (dep[i] > dep[x]) x = i;
	}
	dep[x] = 0;
	dfs1(x, 0);
	int d = 0;
	for (int i = 1; i <= n; i++) d = max(d, dep[i]);
	printf("%d\n", d);
	for (int i = 0; i < edges.size(); i++) {
		printf("%d %d\n", edges[i].fi, edges[i].se);
	}
	return 0;
}