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


const ll MOD = 998244353;
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

const int N = 2070;
int C[N][N];

int solve(int n, int m) {
	int ans = 0;
	for (int x = 1; x < n; x++) {
		int cur = 0;
		for (int y = 1; y < m; y++) {
			ans = add(ans, mult(cur, mult(C[x - 1][y], C[x][m - y - 1])));
			cur = add(cur, mult(C[n - x][y - 1], C[n - x - 1][m - y]));
		}
	}
	return mult(ans, 2);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < N; i++)
		C[i][0] = C[0][i] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++)
			C[i][j] = add(C[i - 1][j], C[i][j - 1]);

	int n, m;
	scanf("%d%d", &n, &m);
	if (n == 1 || m == 1) {
		printf("0\n");
		return 0;
	}
	int ans = 0;
	for (int x = 1; x < n; x++)
		for (int y = 1; y < m; y++) {
			ans = add(ans, mult(mult(C[x - 1][y], C[n - x][y - 1]), mult(C[n - x - 1][m - y], C[x][m - y - 1])));
			ans = add(ans, mult(mult(C[x][y - 1], C[n - x - 1][y]), mult(C[n - x][m - y - 1], C[x - 1][m - y])));
		}
	ans = add(ans, solve(n, m));
	ans = add(ans, solve(m, n));
	printf("%d\n", ans);

	return 0;
}