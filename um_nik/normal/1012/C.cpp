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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)1e9 + 7;
const int N = 5050;
const int M = N / 2;
int a[N];
int dp[N][M][3];
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i / 2 + 5; j++)
			for (int k = 0; k < 3; k++)
				dp[i][j][k] = INF;
	dp[0][0][1] = 0;
	dp[0][1][0] = 0;
	for (int i = 1; i < n; i++) {
		int m = i / 2 + 3;
		for (int x = 0; x <= m; x++) {
			if (dp[i - 1][x][0] < INF) {
				if (a[i] < a[i - 1]) {
					dp[i][x][1] = min(dp[i][x][1], dp[i - 1][x][0]);
				} else {
					dp[i][x][2] = min(dp[i][x][2], dp[i - 1][x][0] + (a[i] - a[i - 1] + 1));
				}
			}
			if (dp[i - 1][x][1] < INF) {
				int p = a[i - 1];
				int w = dp[i - 1][x][1];
				if (a[i] > p) {
					dp[i][x + 1][0] = min(dp[i][x + 1][0], w);
				} else {
					dp[i][x + 1][0] = min(dp[i][x + 1][0], w + (p - a[i] + 1));
				}
				dp[i][x][1] = min(dp[i][x][1], w);
			}
			if (dp[i - 1][x][2] < INF) {
				int p = a[i - 2] - 1;
				int w = dp[i - 1][x][2];
				if (a[i] > p) {
					dp[i][x + 1][0] = min(dp[i][x + 1][0], w);
				} else {
					dp[i][x + 1][0] = min(dp[i][x + 1][0], w + (p - a[i] + 1));
				}
				dp[i][x][1] = min(dp[i][x][1], w);
			}
		}
	}
	for (int i = 1; i <= (n + 1) / 2; i++) {
		int res = INF;
		for (int j = 0; j < 3; j++)
			res = min(res, dp[n - 1][i][j]);
		printf("%d ", res);
	}
	printf("\n");

	return 0;
}