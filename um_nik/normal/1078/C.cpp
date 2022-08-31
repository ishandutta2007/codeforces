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

const ll MOD = 998244353;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

const int N = 300300;
int n;
vector<int> g[N];
ll dp[N][3];

void dfs(int v, int par) {
	ll inner[2][3];
	inner[0][0] = inner[0][1] = 0;
	inner[0][2] = 1;
	for (int u : g[v]) {
		if (u == par) continue;
		dfs(u, v);
		for (int i = 0; i < 3; i++)
			inner[1][i] = 0;

		for (int i = 0; i < 3; i++) {
			inner[1][i] = add(inner[1][i], mult(inner[0][i], add(dp[u][0], dp[u][2])));
		}
		inner[1][0] = add(inner[1][0], mult(inner[0][0], dp[u][0]));
		inner[1][0] = add(inner[1][0], mult(add(inner[0][1], inner[0][2]), add(dp[u][1], dp[u][2])));
		inner[1][1] = add(inner[1][1], mult(add(inner[0][1], inner[0][2]), dp[u][0]));

		for (int i = 0; i < 3; i++) {
			inner[0][i] = inner[1][i];
			if (inner[0][i] & 1) inner[0][i] += MOD;
			inner[0][i] /= 2;
		}
	}
	for (int i = 0; i < 3; i++)
		dp[v][i] = inner[0][i];
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
	dfs(0, -1);
	ll ans = add(dp[0][0], dp[0][2]);
	for (int i = 1; i < n; i++) {
		ans = add(ans, ans);
	}
	printf("%lld\n", ans);

	return 0;
}