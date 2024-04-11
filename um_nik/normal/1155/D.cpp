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
const int N = 300300;
ll dp[N][3][3];
ll a[N];
int n;
ll X;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &X);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 3; j++)
			for (int h = 0; h < 3; h++)
				dp[i][j][h] = -INF;
	dp[0][0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 3; j++)
			for (int h = 0; h < 3; h++) {
				if (dp[i][j][h] == -INF) continue;
				if (j < 2) dp[i][j + 1][h] = max(dp[i][j + 1][h], dp[i][j][h]);
				if (h < 2) dp[i][j][h + 1] = max(dp[i][j][h + 1], dp[i][j][h]);
				if (i < n) {
					ll w = dp[i][j][h];
					if (j == 1) {
						if (h == 1)
							w += a[i] * X;
						else
							w += a[i];
					}
					dp[i + 1][j][h] = max(dp[i + 1][j][h], w);
				}
			}
	}
	printf("%lld\n", dp[n][2][2]);

	return 0;
}