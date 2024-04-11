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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 202;
int a[N], b[N], c[N];
int dp[N][N][N];
int n, m, k;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	sort(b, b + m);
	for (int i = 0; i < k; i++)
		scanf("%d", &c[i]);
	sort(c, c + k);

	for (int i = n; i >= 0; i--)
		for (int j = m; j >= 0; j--)
			for (int h = k; h >= 0; h--) {
				if (i > 0 && j > 0)
					dp[i - 1][j - 1][h] = max(dp[i - 1][j - 1][h], dp[i][j][h] + a[i - 1] * b[j - 1]);
				if (i > 0 && h > 0)
					dp[i - 1][j][h - 1] = max(dp[i - 1][j][h - 1], dp[i][j][h] + a[i - 1] * c[h - 1]);
				if (j > 0 && h > 0)
					dp[i][j - 1][h - 1] = max(dp[i][j - 1][h - 1], dp[i][j][h] + b[j - 1] * c[h - 1]);
			}
	int ans = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int h = 0; h <= k; h++)
				ans = max(ans, dp[i][j][h]);
	printf("%d\n", ans);

	return 0;
}