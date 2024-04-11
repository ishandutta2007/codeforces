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


int MOD = 998244353;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}

const int K = 505;
const int N = K * K;
const int Z = N / 2;
int n;
int dp[2][N];
int f[K];
int C[K][K];
int A[K][K + K];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &MOD);
	if (MOD == 1) {
		printf("0\n");
		return 0;
	}
	f[0] = 1;
	for (int i = 1; i < K; i++)
		f[i] = mult(f[i - 1], i);
	for (int i = 0; i < K; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i < K; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);

	dp[0][Z] = 1;
	int S = 0;
	for (int it = 0; it < n; it++) {
		S += it;
		for (int x = 0; x < N; x++) {
			if (x > 0) dp[0][x] = add(dp[0][x], dp[0][x - 1]);
			dp[1][x] = 0;
		}
		for (int x = Z - S; x <= Z + S; x++) {
			dp[1][x] = sub(dp[0][x], dp[0][x - it - 1]);
		}
		for (int x = 0; x < N; x++)
			dp[0][x] = dp[1][x];
		for (int x = 0; x < N; x++) {
			if (x > 0) dp[0][x] = add(dp[0][x], dp[0][x - 1]);
			dp[1][x] = 0;
		}
		for (int x = Z - S; x <= Z + S; x++) {
			dp[1][x] = sub(dp[0][x + it], dp[0][x - 1]);
		}
		for (int x = 0; x < N; x++)
			dp[0][x] = dp[1][x];
		int cur = 0;
		for (int i = N - 1; i > Z - K; i--) {
			if (i - Z < K) A[it + 1][i - Z + K] = cur;
			cur = add(cur, dp[0][i]);
		}
	}
	/*
	for (int i = 1; i <= 4; i++) {
		for (int x = -10; x <= 10; x++)
			eprintf("%d ", A[i][K + x]);
		eprintf("\n");
	}
	*/
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int d = 1; d < n; d++) {
			int cur = 0;
			for (int t = 0; t <= i && t < d; t++) {
				cur = add(cur, mult(A[n - i - 1][K + d - t], mult(C[d - 1][t], C[n - d - 1][i - t])));
			}
			//eprintf("i = %d, d = %d, cur = %d\n", i, d, cur);
			cur = mult(cur, n - d);
			cur = mult(cur, f[i]);
			ans = add(ans, cur);
		}
	}
	printf("%d\n", ans);

	return 0;
}