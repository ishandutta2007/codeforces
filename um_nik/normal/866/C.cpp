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

const int N = 52;
const int M = 5005;
const double INF = 5e9;
const int IT = 70;
double dp[N][M];
int a[N], b[N];
double p[N];
int n, R;

bool solve(double B) {
	for (int i = 0; i < M; i++) {
		if (i <= R)
			dp[n][i] = 0;
		else
			dp[n][i] = B;
	}
	for (int i = n - 1; i >= 0; i--)
		for (int x = 0; x <= i * 100; x++) {
			dp[i][x] = B;
			dp[i][x] = min(dp[i][x], p[i] * (a[i] + dp[i + 1][x + a[i]]) + (1 - p[i]) * (b[i] + dp[i + 1][x + b[i]]));
		}
	return dp[0][0] < B;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &R);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%lf", &a[i], &b[i], &p[i]);
		p[i] /= 100;
	}
	double l = 1, r = INF;
	for (int it = 0; it < IT; it++) {
		double x = sqrt(l * r);
		if (solve(x))
			r = x;
		else
			l = x;
	}
	printf("%.15lf\n", sqrt(l * r));

	return 0;
}