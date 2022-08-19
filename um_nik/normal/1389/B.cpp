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

const int INF = (int)1e9 + (int)1e8;
const int N = 100100;
const int K = 7;
int n, m, k;
int a[N];
int dp[N][K][2];

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= k; j++)
			for (int h = 0; h < 2; h++)
				dp[i][j][h] = -INF;
	dp[0][0][0] = a[0];
	for (int i = 0; i < m; i++)
		for (int x = 0; x <= k; x++)
			for (int f = 0; f < 2; f++) {
				if (dp[i][x][f] == -INF) continue;
				for (int g = 0; g < 2; g++) {
					if (f & g) continue;
					if (x + g > k) continue;
					int pos = i + 1 - 2 * (x + g);
					if (pos < 0 || pos >= n) continue;
					dp[i + 1][x + g][g] = max(dp[i + 1][x + g][g], dp[i][x][f] + a[pos]);
				}
			}
	int ans = -INF;
	for (int i = 0; i <= k; i++)
		for (int j = 0; j < 2; j++)
			ans = max(ans, dp[m][i][j]);
	printf("%d\n", ans);
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