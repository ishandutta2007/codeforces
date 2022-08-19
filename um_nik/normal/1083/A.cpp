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

const int N = 300300;
int n;
vector<pli> g[N];
ll dp[N];
ll ans = 0;
ll w[N];

void dfs(int v, int par) {
	dp[v] = w[v];
	for (pli e : g[v]) {
		int u = e.second;
		if (u == par) continue;
		dfs(u, v);
		ll z = dp[u] - e.first;
		ans = max(ans, z + dp[v]);
		dp[v] = max(dp[v], z + w[v]);
	}
	ans = max(ans, dp[v]);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &w[i]);
	for (int i = 1; i < n; i++) {
		int v, u;
		ll z;
		scanf("%d%d%lld", &v, &u, &z);
		v--;u--;
		g[v].push_back(mp(z, u));
		g[u].push_back(mp(z, v));
	}
	dfs(0, -1);
	printf("%lld\n", ans);

	return 0;
}