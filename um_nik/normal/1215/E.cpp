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

const ll INF = (ll)1e18;
const int K = 20;
const int M = (1 << K) + 5;
vector<int> a[K];
ll t[K][K];
ll dp[M];
ll b[K][M];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		x--;
		a[x].push_back(i);
	}
	for (int c1 = 0; c1 < K; c1++)
		for (int c2 = 0; c2 < K; c2++) {
			if (c1 == c2) continue;
			int p = 0;
			ll val = 0;
			for (int x : a[c1]) {
				while(p < (int)a[c2].size() && a[c2][p] < x) p++;
				val += p;
			}
			t[c1][c2] = val;
		}
	for (int c = 0; c < K; c++) {
		for (int mask = 1; mask < (1 << K); mask++) {
			int p = 0;
			while(((mask >> p) & 1) == 0) p++;
			b[c][mask] = b[c][mask ^ (1 << p)] + t[p][c];
		}
	}
	for (int mask = 0; mask < (1 << K); mask++)
		dp[mask] = INF;
	dp[0] = 0;
	for (int mask = 0; mask < (1 << K); mask++)
		for (int c = 0; c < K; c++) {
			if ((mask >> c) & 1) continue;
			dp[mask | (1 << c)] = min(dp[mask | (1 << c)], dp[mask] + b[c][mask]);
		}
	printf("%lld\n", dp[(1 << K) - 1]);

	return 0;
}