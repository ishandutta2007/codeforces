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
const int N = 5050;
int n;
const int K = 4;
ll dp[N][K];
int par[N][K];
ll a[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < K; j++)
			dp[i][j] = -INF;
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++)
		for (int k = 0; k < K; k++) {
			if (dp[i][k] == -INF) continue;
			if (k + 1 < K && dp[i][k + 1] < dp[i][k]) {
				dp[i][k + 1] = max(dp[i][k + 1], dp[i][k]);
				par[i][k + 1] = 1;
			}
			if (i == n) continue;
			ll w = dp[i][k];
			if (k & 1)
				w -= a[i];
			else
				w += a[i];
			if (dp[i + 1][k] < w) {
				dp[i + 1][k] = max(dp[i + 1][k], w);
				par[i + 1][k] = 0;
			}
		}
	vector<int> ans;
	int x = n, k = K - 1;
	while(x > 0 || k > 0) {
		int t = par[x][k];
		if (t == 1) {
			ans.push_back(x);
			k--;
		} else {
			x--;
		}
	}
	reverse(all(ans));
	for (int x : ans)
		printf("%d ", x);
	printf("\n");
	//printf("%lld\n", dp[n][K - 1]);

	return 0;
}