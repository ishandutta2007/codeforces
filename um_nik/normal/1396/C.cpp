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

const ll INF = (ll)1e18 + 8;

const int K = 4;
const int N = (int)1e6 + 77;
ll dp[N][K];
ll d, r1, r2, r3;
ll a[N][2];
int n;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld%lld%lld%lld", &n, &r1, &r2, &r3, &d);
	for (int i = 0; i < n; i++) {
		ll k;
		scanf("%lld", &k);
		a[i][0] = k * r1 + r3;
		a[i][1] = min(k * r1 + r1, r2) + r1;
		a[i][1] = min(a[i][1], a[i][0]);
		//eprintf("%lld %lld\n", a[i][0], a[i][1]);
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < K; j++)
			dp[i][j] = INF;
	dp[0][0] = 0;
	for (int p = 0; p < n - 1; p++)
		for (int x = 0; x < K; x++) {
			ll w = dp[p][x] + (2 * max(1, x) + 1) * d + a[p][1];
			dp[p + 1][0] = min(dp[p + 1][0], w);
			if (x == 0) {
				dp[p + 1][0] = min(dp[p + 1][0], dp[p][0] + d + a[p][0]);
			}
			{
				w = dp[p][x] + a[p][1] + d;
				int nx = x + 1;
				if (nx >= K) {
					nx -= 2;
					w += 2 * d;
				}
				dp[p + 1][nx] = min(dp[p + 1][nx], w);
			}
		}
	ll ans = INF;
	for (int x = 0; x < K; x++) {
		if (x == 0) {
			ans = min(ans, dp[n - 1][0] + a[n - 1][0]);
			ans = min(ans, dp[n - 1][0] + 2 * d + a[n - 1][1]);
		} else {
			ans = min(ans, dp[n - 1][x] + d * x + a[n - 1][0]);
			ans = min(ans, dp[n - 1][x] + d * 2 * x + a[n - 1][1]);
		}
	}
	printf("%lld\n", ans);

	return 0;
}