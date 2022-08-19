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


const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}

const int N = 322;
int n, m, x;
int dp[2][N][N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &x);
	if (n > m) {
		printf("0\n");
		return 0;
	}
	x--;
	dp[0][0][0] = 1;
	for (int it = 0; it < m; it++) {
		for (int bal = 0; bal <= n; bal++)
			for (int tot = bal; tot <= n; tot++)
				dp[1][bal][tot] = 0;
		for (int bal = 0; bal <= n; bal++)
			for (int tot = bal; tot <= n; tot++) {
				if (dp[0][bal][tot] == 0) continue;
				for (int f = 0; f < 2; f++)
					for (int g = 0; g < 2; g++) {
						if (it == x && f == 0) continue;
						int nbal = bal + f - g;
						int ntot = tot + f;
						if (nbal < 0 || ntot > n) continue;
						dp[1][nbal][ntot] = add(dp[1][nbal][ntot], dp[0][bal][tot]);
					}
			}
		for (int bal = 0; bal <= n; bal++)
			for (int tot = bal; tot <= n; tot++)
				dp[0][bal][tot] = dp[1][bal][tot];
	}
	int ans = dp[0][0][n];
	for (int i = 1; i <= n; i++)
		ans = mult(ans, i);
	printf("%d\n", ans);

	return 0;
}