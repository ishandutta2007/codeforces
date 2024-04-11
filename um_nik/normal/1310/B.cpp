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

const int INF = (int)1e8;
const int N = (1 << 18) + 9;
int dp[N][4];
int a[N];
int t[4][4][4];
int n, m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int m1 = 0; m1 < 4; m1++)
		for (int m2 = 0; m2 < 4; m2++) {
			for (int i = 0; i < 4; i++)
				t[m1][m2][i] = -INF;
			for (int r = 0; r < 8; r++) {
				int b[10];
				int res = 0;
				int m3 = 0;
				for (int i = 0; i < 8; i++)
					b[i] = 0;
				for (int i = 0; i < 2; i++)
					b[2 * i] = (m1 >> i) & 1;
				for (int i = 0; i < 2; i++) {
					b[2 * i + 1] = (m2 >> i) & 1;
				}
				if (b[0] || b[1]) res++;
				b[4] = b[(r & 1) ^ 1];
				m3 |= b[(r & 1)];
				if (b[2] || b[3]) res++;
				b[5] = b[2 + ((r >> 1) & 1)];
				if (b[4] || b[5]) res++;
				m3 |= b[4 + ((r >> 2) & 1)] << 1;
				t[m1][m2][m3] = max(t[m1][m2][m3], res);
			}
		}
/*
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			for (int z = 0; z < 4; z++)
				eprintf("t[%d][%d][%d] = %d\n", x, y, z, t[x][y][z]);
*/
	scanf("%d%d", &n, &m);
	for (int i = 0; i < (1 << n); i++)
		for (int j = 0; j < 4; j++)
			dp[i][j] = -INF;
	while(m--) {
		int x;
		scanf("%d", &x);
		x--;
		a[x / 2]++;
	}
	for (int i = 0; i < (1 << (n - 1)); i++) {
		if (a[i] == 0) {
			dp[(1 << (n - 1)) + i][0] = 0;
		} else if (a[i] == 1) {
			dp[(1 << (n - 1)) + i][1] = dp[(1 << (n - 1)) + i][2] = 1;
		} else {
			dp[(1 << (n - 1)) + i][3] = 1;
		}
	}
	for (int v = (1 << (n - 1)) - 1; v > 0; v--) {
		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 4; y++) {
				if (dp[2 * v][x] < 0 || dp[2 * v + 1][y] < 0) continue;
				for (int z = 0; z < 4; z++) {
					if (t[x][y][z] < 0) continue;
					dp[v][z] = max(dp[v][z], dp[2 * v][x] + dp[2 * v + 1][y] + t[x][y][z]);
				}
			}
	}
/*
	for (int i = (1 << n) - 1; i > 0; i--)
		for (int j = 0; j < 4; j++)
			eprintf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
*/
	int ans = -INF;
	for (int x = 0; x < 4; x++)
		ans = max(ans, dp[1][x] + min(1, x));
	printf("%d\n", ans);

	return 0;
}