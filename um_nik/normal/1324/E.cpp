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

const int N = 2020;
int n, m, l, r;
int a[N];
int dp[N][N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &l, &r);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < m; j++)
			dp[i][j] = -N;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int x = 0; x < m; x++) {
			if (dp[i][x] < 0) continue;
			for (int y = 0; y < 2; y++) {
				int t = x + a[i] - y;
				t %= m;
				int w = dp[i][x];
				if (l <= t && t <= r) w++;
				dp[i + 1][t] = max(dp[i + 1][t], w);
			}
		}
	int ans = 0;
	for (int x = 0; x < m; x++)
		ans = max(ans, dp[n][x]);
	printf("%d\n", ans);

	return 0;
}