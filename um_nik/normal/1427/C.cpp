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

const int N = 100100;
int n, m;
int a[N][3];
int dp[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &m, &n);
	m *= 4;
	n++;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
	a[0][1] = a[0][2] = 1;
	for (int i = 1; i < n; i++)
		dp[i] = -N;
	for (int i = 1; i < n; i++) {
		for (int j = max(0, i - m); j < i; j++) {
			if (a[i][0] - a[j][0] >= abs(a[i][1] - a[j][1]) + abs(a[i][2] - a[j][2]))
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	printf("%d\n", ans);

	return 0;
}