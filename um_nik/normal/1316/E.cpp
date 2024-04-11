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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const ll INF = (ll)1e16;
const int N = 100100;
const int M = (1 << 7) + 7;

vector<ll> a[N];
int n, k, p;
int ppc[M];
ll dp[2][M];

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 1; i < M; i++)
		ppc[i] = ppc[i / 2] + (i & 1);

	scanf("%d%d%d", &n, &p, &k);
	for (int i = 0; i < n; i++) {
		a[i].resize(p + 1);
		scanf("%lld", &a[i][0]);
	}
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= p; j++)
			scanf("%lld", &a[i][j]);
	sort(a, a + n);
	reverse(a, a + n);

	for (int mask = 0; mask < (1 << p); mask++)
		dp[0][mask] = -INF;
	dp[0][0] = 0;

	for (int i = 0; i < n; i++) {
		for (int mask = 0; mask < (1 << p); mask++)
			dp[1][mask] = -INF;
		for (int mask = 0; mask < (1 << p); mask++) {
			for (int j = 0; j < p; j++) {
				if ((mask >> j) & 1) continue;
				dp[1][mask ^ (1 << j)] = max(dp[1][mask ^ (1 << j)], dp[0][mask] + a[i][j + 1]);
			}
			ll w = dp[0][mask];
			if (ppc[mask] + k > i) w += a[i][0];
			dp[1][mask] = max(dp[1][mask], w);
		}
		for (int mask = 0; mask < (1 << p); mask++)
			dp[0][mask] = dp[1][mask];
	}
	printf("%lld\n", dp[0][(1 << p) - 1]);

	return 0;
}