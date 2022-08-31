#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const ll INF = (ll)1e18;
const int N = 303;
ll c[N][N];
ll dp[N][N];
int n, m, k;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			c[i][j] = INF;
	while(m--) {
		int l, r;
		ll w;
		scanf("%d%d%lld", &l, &r, &w);
		l--;
		c[l][r] = min(c[l][r], w);
	}
	for (int len = n; len > 0; len--) {
		for (int l = 0; l + len <= n; l++) {
			int r = l + len;
			c[l + 1][r] = min(c[l + 1][r], c[l][r]);
			c[l][r - 1] = min(c[l][r - 1], c[l][r]);
		}
	}

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = INF;
	dp[0][0] = 0;

	for (int i = 0; i < n; i++) {
		for (int x = 0; x <= n; x++) {
			dp[i + 1][x] = min(dp[i + 1][x], dp[i][x]);
			for (int j = i + 1; j <= n; j++)
				dp[j][x + j - i] = min(dp[j][x + j - i], dp[i][x] + c[i][j]);
		}
	}
	ll ans = INF;
	for (int i = k; i <= n; i++)
		ans = min(ans, dp[n][i]);
	if (ans == INF)
		printf("-1\n");
	else
		printf("%lld\n", ans);

	return 0;
}