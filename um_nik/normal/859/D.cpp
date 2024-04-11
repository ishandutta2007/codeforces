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

typedef long double ld;

const int N = 200;
int n, m;
ld a[N][N];
ld p[N][N];
ld q[N];
ld dp[N][N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	m = 1 << n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) {
			int x;
			scanf("%d", &x);
			a[i][j] = (ld)x / 100;
		}
	for (int i = 0; i < m; i++)
		p[m + i][i] = 1;
	for (int i = m - 1; i > 0; i--)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < m; k++) {
				p[i][j] += p[2 * i][j] * p[2 * i + 1][k] * a[j][k];
				p[i][k] += p[2 * i][j] * p[2 * i + 1][k] * a[k][j];
			}
	for (int i = 0; i < m; i++)
		q[m + i] = 0.5;
	for (int i = m - 1; i > 0; i--)
		q[i] = q[2 * i] + q[2 * i + 1];
	for (int i = m - 1; i > 0; i--)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < m; k++) {
				dp[i][j] = max(dp[i][j], dp[2 * i][j] + dp[2 * i + 1][k] + p[i][j] * q[i]);
				dp[i][k] = max(dp[i][k], dp[2 * i][j] + dp[2 * i + 1][k] + p[i][k] * q[i]);
			}
	ld ans = 0;
	for (int i = 0; i < m; i++)
		ans = max(ans, dp[1][i]);
	printf("%.13lf\n", (double)ans);

	return 0;
}