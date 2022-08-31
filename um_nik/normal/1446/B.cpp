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

const int N = 5050;
int n, m;
int dp[N][N];
char a[N], b[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	scanf("%s %s", a, b);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1);
			if (a[i] == b[j])
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
		}
	int ans = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			ans = max(ans, dp[i][j]);
	printf("%d\n", ans);

	return 0;
}