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

const int N = 88;
const int M = 100100;
int dp[N][M][2];
pii a[N];
int n, m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].first, &a[i].second);
	sort(a, a + n);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int f = 0; f < 2; f++)
				dp[i][j][f] = M;
	dp[0][0][1] = 0;
	for (int i = 0; i < n; i++) {
		for (int x = 0; x <= m; x++)
			dp[i + 1][x][0] = min(dp[i + 1][x][0], min(dp[i][x][0], dp[i][x][1]));
		for (int x = 0; x <= m; x++) {
			int r = a[i].first - x - 1;
			r = max(r, x - a[i].first);
			r = max(r, a[i].second);
			int y = min(m, a[i].first + r);
			dp[i + 1][y][1] = min(dp[i + 1][y][1], min(dp[i][x][0], dp[i][x][1]) + r - a[i].second);
		}
		for (int x = 1; x <= m; x++)
			dp[i + 1][x][1] = min(dp[i + 1][x][1], dp[i + 1][x - 1][1] + 1);
	}
	printf("%d\n", min(dp[n][m][0], dp[n][m][1]));

	return 0;
}