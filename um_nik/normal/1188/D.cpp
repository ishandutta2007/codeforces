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

const int INF = (int)1e9;
const int N = 100100;
const int K = 60;
ll a[N];
int n;
ll b[K][N];
int dp[K][N];

int getCount(int k, ll x) {
	ll W = 1LL << (k - 1);
	if (x < W) {
		return upper_bound(b[k], b[k] + n, x + W) - upper_bound(b[k], b[k] + n, x);
	} else {
		return (upper_bound(b[k], b[k] + n, x - W) - b[k]) + 
			(b[k] + n - upper_bound(b[k], b[k] + n, x));
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int k = 1; k < K; k++) {
		ll U = (1LL << k) - 1;
		for (int i = 0; i < n; i++)
			b[k][i] = a[i] & U;
		sort(b[k], b[k] + n);
	}
	for (int k = 0; k < K; k++)
		for (int i = 0; i <= n; i++)
			dp[k][i] = INF;
	dp[0][n] = 0;
	for (int k = 1; k < K; k++) 
		for (int i = 0; i <= n; i++) {
			if (dp[k - 1][i] == INF) continue;
			if (i == 0 && b[k - 1][i] == 0) continue;
			for (ll z = 0; z < 2; z++) {
				ll x = (i == 0 ? 0 : b[k - 1][i - 1]) + (z << (k - 1));
				int p = upper_bound(b[k], b[k] + n, x) - b[k];
				dp[k][p] = min(dp[k][p], dp[k - 1][i] + getCount(k, x));
			}
		}
	printf("%d\n", dp[K - 1][n]);

	return 0;
}