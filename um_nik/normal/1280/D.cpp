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

const ll INF = (ll)1e16;
const int N = 3030;
int n, m;
ll a[N];
vector<int> g[N];
pll dp[N][N];
pll inner[N][N];
int sz[N];

pll merge(pll x, pll y) {
	return mp(x.first + y.first, x.second + y.second);
}

void normalize(int v) {
	for (int i = min(m, sz[v]); i > 0; i--) {
		pll z = dp[v][i - 1];
		z.first += (ll)(z.second > 0);
		z.second = 0;
		dp[v][i] = max(dp[v][i], z);
	}
}

void dfs(int v) {
	sz[v] = 1;
	dp[v][0] = mp(0LL, a[v]);
	dp[v][1] = mp(-INF, -INF);
	for (int u : g[v]) {
		if (sz[u]) continue;
		dfs(u);
		normalize(u);
		for (int i = 0; i <= m && i <= sz[v] + sz[u]; i++)
			inner[v][i] = mp(-INF, -INF);
		for (int i = 0; i <= m && i < sz[v]; i++)
			for (int j = 0; i + j <= m && j <= sz[u]; j++) {
				if (dp[v][i].first < 0 || dp[u][j].first < 0) continue;
				inner[v][i + j] = max(inner[v][i + j], merge(dp[v][i], dp[u][j]));
			}
		sz[v] += sz[u];
		for (int i = 0; i <= m && i <= sz[v]; i++)
			dp[v][i] = inner[v][i];
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		a[i] = x - a[i];
	}
	for (int i = 0; i < n; i++)
		g[i].clear();
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 0; i < n; i++)
		sz[i] = 0;
	dfs(0);
	ll ans = dp[0][m - 1].first + (ll)(dp[0][m - 1].second > 0);
	printf("%lld\n", ans);
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