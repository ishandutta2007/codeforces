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

const int INF = (int)1e9;
const int S = 16777;
const int N = 6;
int p5[N + 1];
int dp[2][N][S];
int n, m;
int c[N][N];
int a[N], b[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	p5[0] = 1;
	for (int i = 1; i <= N; i++)
		p5[i] = p5[i - 1] * 5;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &c[i][j]);

	for (int i = 0; i < 5; i++)
		for (int mask = 0; mask < p5[n]; mask++)
			dp[0][i][mask] = INF;
	dp[0][0][0] = 0;

	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			for (int i = 0; i < 5; i++)
				for (int mask = 0; mask < p5[n]; mask++)
					dp[1][i][mask] = INF;
			for (int i = 0; i <= b[x]; i++)
				for (int mask = 0; mask < p5[n]; mask++) {
					if (dp[0][i][mask] == INF) continue;
					dp[1][i][mask] = min(dp[1][i][mask], dp[0][i][mask]);
					int w = dp[0][i][mask] + c[y][x];
					for (int f = 1; i + f <= b[x]; f++) {
						int of = (mask / p5[y]) % 5;
						if (of + f > a[y]) continue;
						int nmask = mask + p5[y] * f;
						dp[1][i + f][nmask] = min(dp[1][i + f][nmask], w);
					}
				}
			for (int i = 0; i < 5; i++)
				for (int mask = 0; mask < p5[n]; mask++)
					dp[0][i][mask] = dp[1][i][mask];
		}
		for (int i = 0; i < 5; i++)
			for (int mask = 0; mask < p5[n]; mask++)
				dp[1][i][mask] = INF;
		for (int i = 0; i <= b[x]; i++)
			for (int mask = 0; mask < p5[n]; mask++)
				dp[1][0][mask] = min(dp[1][0][mask], dp[0][i][mask]);
		for (int i = 0; i < 5; i++)
			for (int mask = 0; mask < p5[n]; mask++)
				dp[0][i][mask] = dp[1][i][mask];
	}
	int W = 0;
	for (int i = 0; i < n; i++)
		W += a[i];
	int ans = INF;
	for (int mask = 0; mask < p5[n]; mask++) {
		int cur = 0;
		int cm = mask;
		for (int i = 0; i < n; i++) {
			cur += cm % 5;
			cm /= 5;
		}
		if (cur < W) continue;
		ans = min(ans, dp[0][0][mask]);
	}
	if (ans == INF) ans = -1;
	printf("%d\n", ans);

	return 0;
}