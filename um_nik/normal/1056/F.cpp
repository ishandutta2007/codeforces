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

const double INF = 1e20;
const int N = 102;
const int M = 1010;
const int K = 10;
int n;
double C, T;
const double Y = 1. / 0.9;
pii a[N];
double dp[N][M];

void read() {
	scanf("%d", &n);
	scanf("%lf%lf", &C, &T);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].first, &a[i].second);
	sort(a, a + n);
}

int solve() {
	read();
	dp[0][0] = 0;
	for (int it = 1; it <= n; it++) {
		for (int j = 0; j <= it * K; j++)
			dp[it][j] = INF;
		for (int i = it - 1; i >= 0; i--)
			for (int j = 0; j <= i * K; j++) {
				if (dp[i][j] >= INF / 2) continue;
				dp[i + 1][j + a[it - 1].second] = min(dp[i + 1][j + a[it - 1].second], dp[i][j] * Y + a[it - 1].first);
			}
	}
	for (int x = n * K; x >= 0; x--)
		for (int p = 0; p <= n; p++) {
			if (p * K < x || dp[p][x] >= INF / 2) continue;
			double X = dp[p][x] * Y;
			double t = X;
			if (C * X >= 1)
				t = 2 * sqrt(X / C) - 1. / C;
			t += p * 10;
			if (t <= T)
				return x;
		}
	throw;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) printf("%d\n", solve());

	return 0;
}