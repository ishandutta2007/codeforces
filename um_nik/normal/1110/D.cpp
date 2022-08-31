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

const int N = (int)1e6 + 77;
int a[N];
int dp[N][3][3];
int n, m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(n--) {
		int x;
		scanf("%d", &x);
		a[x + 1]++;
	}
	m += 10;
	
	for (int i = 0; i < m - 2; i++)
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++) {
				int p = a[i] - x - y;
				int q = a[i + 1] - y;
				int r = a[i + 2];
				for (int z = 0; z < 3; z++) {
					if (p < z || q < z || r < z) continue;
					dp[i + 1][y][z] = max(dp[i + 1][y][z], dp[i][x][y] + z + (p - z) / 3);
				}
			}
	int ans = 0;
	for (int i = 0; i <= m; i++)
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++)
				ans = max(ans, dp[i][x][y]);
	printf("%d\n", ans);

	return 0;
}