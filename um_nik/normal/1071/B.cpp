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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2020;
int n, k;
char s[N][N];
int dp[N][N];
bool good[N][N];

void solve(int m) {
	char c = 'z';
	for (int x = 0; x < n; x++) {
		int y = m - x;
		if (y < 0 || y >= n) continue;
		if (!good[x][y]) continue;
		if (x < n - 1) c = min(c, s[x + 1][y]);
		if (y < n - 1) c = min(c, s[x][y + 1]);
	}
	for (int x = 0; x < n; x++) {
		int y = m - x;
		if (y < 0 || y >= n) continue;
		if (!good[x][y]) continue;
		if (x < n - 1 && s[x + 1][y] == c) good[x + 1][y] = 1;
		if (y < n - 1 && s[x][y + 1] == c) good[x][y + 1] = 1;
	}
	printf("%c", c);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	dp[0][0] = (s[0][0] == 'a' ? 0 : 1);
	for (int i = 1; i < n; i++) {
		dp[0][i] = dp[0][i - 1];
		if (s[0][i] != 'a') dp[0][i]++;
		dp[i][0] = dp[i - 1][0];
		if (s[i][0] != 'a') dp[i][0]++;
	}
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
			if (s[i][j] != 'a') dp[i][j]++;
		}

	int m = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (dp[i][j] <= k)
				m = max(m, i + j);
		}
	if (m == -1) {
		printf("%c", s[0][0]);
		m = 0;
		good[0][0] = 1;
	}
	else {
		for (int i = 0; i <= m; i++)
			printf("a");
		for (int x = 0; x < n; x++) {
			int y = m - x;
			if (y < 0 || y >= n) continue;
			if (dp[x][y] <= k)
				good[x][y] = 1;
		}
	}
	while(m < 2 * n - 2)
		solve(m++);
	printf("\n");

	return 0;
}