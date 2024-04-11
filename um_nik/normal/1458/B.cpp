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

const int N = 102;
const int C = (int)1e4 + 5;
int n;
int a[N], b[N];
int dp[N][C];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i], &b[i]);
	for (int i = 0; i <= n; i++)
		for (int x = 0; x < C; x++)
			dp[i][x] = -1;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j >= 0; j--)
			for (int x = 0; x < C; x++) {
				if (dp[j][x] == -1) continue;
				dp[j + 1][x + a[i]] = max(dp[j + 1][x + a[i]], dp[j][x] + b[i]);
			}
	}
	int S = 0;
	for (int i = 0; i < n; i++)
		S += b[i];
	for (int k = 1; k <= n; k++) {
		double ans = 0;
		for (int x = 0; x < C; x++) {
			if (dp[k][x] == -1) continue;
			ans = max(ans, min((double)x, (double)(S + dp[k][x]) / 2));
		}
		printf("%.13lf ", ans);
	}
	printf("\n");

	return 0;
}