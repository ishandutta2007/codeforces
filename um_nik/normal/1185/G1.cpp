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

const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}

const int M = 2505;
const int N = 52;
vector<int> a[3];
int dp1[2][N / 3 + 1][N / 2 + 1][M];
int dp2[2][N][M];
int dp3[N][N][N][3];
int c[N][N][N];
int f[N];
int T;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

//	dp3[0][0][0][0] = 1;
	dp3[1][0][0][0] = 1;
	dp3[0][1][0][1] = 1;
	dp3[0][0][1][2] = 1;
	for (int x = 0; x < N - 1; x++)
		for (int y = 0; y < N - 1; y++)
			for (int z = 0; z < N - 1; z++)
				for (int lst = 0; lst < 3; lst++) {
					int w = dp3[x][y][z][lst];
					if (w == 0) continue;
					c[x][y][z] = add(c[x][y][z], w);
					if (lst != 0) {
						dp3[x + 1][y][z][0] = add(dp3[x + 1][y][z][0], w);
					}
					if (lst != 1) {
						dp3[x][y + 1][z][1] = add(dp3[x][y + 1][z][1], w);
					}
					if (lst != 2) {
						dp3[x][y][z + 1][2] = add(dp3[x][y][z + 1][2], w);
					}
				}
	c[0][0][0] = 1;

	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			for (int z = 0; z < N; z++) {
				c[x][y][z] = mult(mult(c[x][y][z], f[x]), mult(f[y], f[z]));
			}

	int n;
	scanf("%d%d", &n, &T);
	while(n--) {
		int x, y;
		scanf("%d%d", &x, &y);
		y--;
		a[y].push_back(x);
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			if ((int)a[j].size() > (int)a[j + 1].size())
				swap(a[j], a[j + 1]);

	dp1[0][0][0][0] = 1;
	n = (int)a[0].size();
	int m = (int)a[1].size();
	for (int q : a[0]) {
		for (int x = 0; x <= n; x++)
			for (int y = 0; y <= m; y++)
				for (int p = 0; p < M; p++)
					dp1[1][x][y][p] = 0;
		for (int x = 0; x <= n; x++)
			for (int y = 0; y <= m; y++)
				for (int p = 0; p < M; p++) {
					int w = dp1[0][x][y][p];
					if (w == 0) continue;
					dp1[1][x][y][p] = add(dp1[1][x][y][p], w);
					dp1[1][x + 1][y][p + q] = add(dp1[1][x + 1][y][p + q], w);
				}
		for (int x = 0; x <= n; x++)
			for (int y = 0; y <= m; y++)
				for (int p = 0; p < M; p++)
					dp1[0][x][y][p] = dp1[1][x][y][p];
	}
	for (int q : a[1]) {
		for (int x = 0; x <= n; x++)
			for (int y = 0; y <= m; y++)
				for (int p = 0; p < M; p++)
					dp1[1][x][y][p] = 0;
		for (int x = 0; x <= n; x++)
			for (int y = 0; y <= m; y++)
				for (int p = 0; p < M; p++) {
					int w = dp1[0][x][y][p];
					if (w == 0) continue;
					dp1[1][x][y][p] = add(dp1[1][x][y][p], w);
					dp1[1][x][y + 1][p + q] = add(dp1[1][x][y + 1][p + q], w);
				}
		for (int x = 0; x <= n; x++)
			for (int y = 0; y <= m; y++)
				for (int p = 0; p < M; p++)
					dp1[0][x][y][p] = dp1[1][x][y][p];
	}

	dp2[0][0][0] = 1;
	int k = (int)a[2].size();
	for (int q : a[2]) {
		for (int x = 0; x <= k; x++)
			for (int p = 0; p < M; p++)
				dp2[1][x][p] = 0;
		for (int x = 0; x <= k; x++)
			for (int p = 0; p < M; p++) {
				int w = dp2[0][x][p];
				if (w == 0) continue;
				dp2[1][x][p] = add(dp2[1][x][p], w);
				dp2[1][x + 1][p + q] = add(dp2[1][x + 1][p + q], w);
			}
		for (int x = 0; x <= k; x++)
			for (int p = 0; p < M; p++)
				dp2[0][x][p] = dp2[1][x][p];
	}

	int ans = 0;
	for (int x = 0; x <= n; x++)
		for (int y = 0; y <= m; y++)
			for (int z = 0; z <= k; z++)
				for (int q = 0; q <= T; q++) {
					int val = mult(dp1[0][x][y][T - q], dp2[0][z][q]);
					//eprintf("%d %d %d %d --- %d\n", x, y, z, q, val);
					ans = add(ans, mult(val, c[x][y][z]));
				}
	printf("%d\n", ans);

	return 0;
}