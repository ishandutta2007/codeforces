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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
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

const int N = 200100;
int n;
ll a[N][2];
vector<int> g[N];
ll dp[N][2];

void dfs(int v, int par) {
	for (int u : g[v]) {
		if (u == par) continue;
		dfs(u, v);
		for (int x = 0; x < 2; x++) {
			ll w = 0;
			for (int y = 0; y < 2; y++)
				w = max(w, dp[u][y] + abs(a[v][x] - a[u][y]));
			dp[v][x] += w;
		}
	}
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		g[i].clear();
		dp[i][0] = dp[i][1] = 0;
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &a[i][0], &a[i][1]);
	}
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
	printf("%lld\n", max(dp[0][0], dp[0][1]));
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}