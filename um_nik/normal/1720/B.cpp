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
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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

const ll INF = (ll)1e12;
const int N = 100100;
ll a[N];
int n;
ll dp[N][3][16];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i <= n; i++)
		for (int t = 0; t < 3; t++)
			for (int mask = 0; mask < 16; mask++)
				dp[i][t][mask] = -INF;
	dp[0][0][0] = 0;
	for (int p = 0; p <= n; p++) {
		for (int t = 0; t < 2; t++)
			for (int mask = 0; mask < 16; mask++)
				dp[p][t + 1][mask] = max(dp[p][t + 1][mask], dp[p][t][mask]);
		if (p == n) break;
		for (int t = 0; t < 3; t++)
			for (int mask = 0; mask < 16; mask++) {
				for (int tmax = 0; tmax < 2; tmax++)
					for (int tmin = 0; tmin < 2; tmin++) {
						ll w = dp[p][t][mask];
						int nmask = mask;
						bool ok = true;
						if (tmax) {
							w += a[p];
							int pos = 0;
							if (t == 1) pos = 2;
							if ((mask >> pos) & 1) {
								ok = false;
							} else {
								nmask |= 1 << pos;
							}
						}
						if (tmin) {
							w -= a[p];
							int pos = 1;
							if (t == 1) pos = 3;
							if ((mask >> pos) & 1) {
								ok = false;
							} else {
								nmask |= 1 << pos;
							}
						}
						if (!ok) continue;
						dp[p + 1][t][nmask] = max(dp[p + 1][t][nmask], w);
					}
			}
	}
	printf("%lld\n", dp[n][2][15]);
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