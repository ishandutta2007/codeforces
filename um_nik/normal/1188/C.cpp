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

const int MOD = 998244353;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}

const int N = 1010;
int n, k, m;
int a[N];
int dp[N][N];
int ANS;

int solve(int d) {
	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = 0;
	for (int i = 1; i <= n; i++)
		dp[1][i] = i;
	for (int t = 1; t < k; t++) {
		int p = 0;
		for (int i = 0; i < n; i++) {
			while(a[i] - a[p] >= d) p++;
			dp[t + 1][i + 1] = add(dp[t + 1][i], dp[t][p]);
		}
	}
	return dp[k][n];
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	m = a[n - 1] - a[0];
	for (int d = 1; d * (k - 1) <= m; d++)
		ANS = add(ANS, solve(d));
	printf("%d\n", ANS);

	return 0;
}