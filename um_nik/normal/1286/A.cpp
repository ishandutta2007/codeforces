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

const int N = 111;
int dp[N][N][N][2];
int a[N];
int B, C;
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	B = n / 2, C = (n + 1) / 2;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) {
			a[i] = -1;
		} else {
			a[i] &= 1;
			if (a[i] == 0)
				B--;
			else
				C--;
		}
	}
	for (int i = 0; i <= n; i++)
		for (int x = 0; x <= B; x++)
			for (int y = 0; y <= C; y++)
				dp[i][x][y][0] = dp[i][x][y][1] = N;
	dp[0][B][C][0] = dp[0][B][C][1] = 0;
	for (int i = 0; i < n; i++) {
		for (int x = 0; x <= B; x++)
			for (int y = 0; y <= C; y++)
				for (int g = 0; g < 2; g++) {
					if (dp[i][x][y][g] == N) continue;
					for (int f = 0; f < 2; f++) {
						if (a[i] != -1 && a[i] != f) continue;
						int nx = x, ny = y;
						if (a[i] == -1) {
							if (f == 0)
								nx--;
							else
								ny--;
						}
						if (nx < 0 || ny < 0) continue;
						int w = dp[i][x][y][g];
						if (g != f) w++;
						dp[i + 1][nx][ny][f] = min(dp[i + 1][nx][ny][f], w);
					}
			}
	}
	printf("%d\n", min(dp[n][0][0][0], dp[n][0][0][1]));

	return 0;
}