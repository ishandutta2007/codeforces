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

const int N = 404;
int dp[2][N][N];
int A[N][N];
int C[N];
int rr[N];

void precalc() {
	dp[0][0][0] = 1;
	for (int n = 0; n < N - 2; n++) {
		for (int k = 0; k <= n; k++)
			A[n][k] = dp[0][k][0];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dp[1][i][j] = 0;
		for (int c = 0; c <= n; c++)
			for (int c1 = 0; c1 <= n; c1++) {
				dp[1][c + 1][c1 + 1] = add(dp[1][c + 1][c1 + 1], dp[0][c][c1]);
				if (c1 > 0)
					dp[1][c][c1 - 1] = add(dp[1][c][c1 - 1], mult(c1, dp[0][c][c1]));
				dp[1][c][c1] = add(dp[1][c][c1], mult(n - c1, dp[0][c][c1]));
			}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dp[0][i][j] = dp[1][i][j];
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	precalc();

	int n, k;
	scanf("%d%d", &n, &k);

	rr[1] = 1;
	for (int x = 2; x < N; x++)
		rr[x] = sub(0, mult(rr[MOD % x], MOD / x));
	C[0] = 1;
	for (int x = 1; x < N; x++)
		C[x] = mult(C[x - 1], mult(n - x + 1, rr[x]));

	int odd = 0, even = 1;
	for (int i = 1; i <= k; i++) {
		int ans = 0;
		for (int m = 0; m <= i; m++) {
			ans = add(ans, mult(C[i + m], A[i + m][m]));
		}
		if (i & 1) {
			odd = add(odd, ans);
			printf("%d ", odd);
		} else {
			even = add(even, ans);
			printf("%d ", even);
		}
	}
	printf("\n");

	return 0;
}