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
int n;
vector<pii> g[N];
int sz[N];
ll toPar[N];

void dfs(int v) {
	sz[v] = 1;
	for (pii e : g[v]) {
		int u = e.first;
		if (sz[u]) continue;
		toPar[u] = e.second;
		dfs(u);
		sz[v] += sz[u];
	}
}

void solve() {
	scanf("%d", &n);
	n *= 2;
	for (int i = 0; i < n; i++)
		g[i].clear();
	for (int i = 1; i < n; i++) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		v--;u--;
		g[v].push_back(mp(u, w));
		g[u].push_back(mp(v, w));
	}
	for (int i = 0; i < n; i++)
		sz[i] = 0;
	dfs(0);
	ll ans1 = 0, ans2 = 0;
	for (int i = 1; i < n; i++) {
		if (sz[i] & 1) ans1 += toPar[i];
		ans2 += toPar[i] * min(sz[i], n - sz[i]);
	}
	printf("%lld %lld\n", ans1, ans2);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}