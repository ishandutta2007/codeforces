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

const int N = 200200;
int n;
int dp[N][2][2];
int a[N];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i <= n; i++)
		for (int x = 0; x < 2; x++)
			for (int y = 0; y < 2; y++)
				dp[i][x][y] = N;
	dp[0][0][1] = 0;
	for (int i = 0; i < n; i++)
		for (int x = 0; x < 2; x++)
			for (int y = 0; y < 2; y++) {
				for (int z = 0; z < 2; z++) {
					int ny = y + 1;
					if (x != z) ny = 0;
					if (ny >= 2) continue;
					dp[i + 1][z][ny] = min(dp[i + 1][z][ny], dp[i][x][y] + a[i] * z);
				}
			}
	int ans = N;
	for (int x = 0; x < 2; x++)
		for (int y = 0; y < 2; y++)
			ans = min(ans, dp[n][x][y]);
	printf("%d\n", ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}