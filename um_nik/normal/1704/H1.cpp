#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ll MOD = 998244353;
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
	return modmul(x, y, MOD);
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

const int N = 5050;
ll C[N][N];
ll T[N][3];
ll F[N][3];
ll A[N][3];
ll B[N][2];
ll dp1[N][3][3];
ll dp2[N];
ll D[N];
ll E[N];
ll cur[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int k;
	scanf("%d%lld", &k, &MOD);

	for (int i = 0; i < N; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);

	F[0][0] = 1;
	for (int n = 1; n < N; n++) {
		T[n][0] = mult(n, F[n - 1][2]);
		T[n][1] = mult(n, F[n - 1][0]);
		T[n][2] = mult(n, add(F[n - 1][2], F[n - 1][0]));
		for (int m = 1; m <= n; m++) {
			cur[0] = mult(F[n - m][0], T[m][0]);
			ll X = add(F[n - m][0], F[n - m][1]), Y = add(T[m][0], T[m][1]);
			cur[1] = sub(mult(X, Y), cur[0]);
			cur[2] = add(mult(X, T[m][2]), mult(F[n - m][2], Y));
			for (int i = 0; i < 3; i++)
				F[n][i] = add(F[n][i], mult(cur[i], C[n - 1][m - 1]));
		}
	}

	//printf("after trees: time = %.5lf\n", getCurrentTime());

	for (int n = 1; n < N; n++) {
		A[n][0] = mult(n, F[n - 1][0]);
		A[n][1] = mult(n, add(F[n - 1][0], F[n - 1][1]));
		A[n][2] = mult(n, F[n - 1][2]);

		B[n][0] = A[n][0];
		B[n][1] = add(A[n][1], A[n][2]);
	}

	for (int x = 1; x < N; x++)
		for (int y = 1; x + y < N; y++)
			for (int f = 0; f < 2; f++)
				for (int g = 0; g < 2; g++) {
					if (f + g == 0) continue;
					dp1[x + y][f][g] = add(dp1[x + y][f][g], mult(mult(B[x][f], B[y][g]), C[x + y - 1][y]));
				}

	for (int n = 1; n < N; n++)
		for (int m = 1; m <= n; m++)
			for (int h = 0; h < 2; h++) {
				ll X = mult(B[m][h], C[n - 1][m]);
				for (int f = 0; f < 2; f++) {
					ll Y = dp1[n - m][f][1];
					if (h != 0) Y = add(Y, dp1[n - m][f][0]);
					dp1[n][f][h] = add(dp1[n][f][h], mult(X, Y));
				}
			}
/*
	for (int n = 1; n < N; n++)
		for (int m = 1; m <= n; m++)
			for (int f = 0; f < 2; f++)
				for (int g = 0; g < 2; g++)
					for (int h = 0; h < 2; h++) {
						if (g + h == 0) continue;
						dp1[n][f][h] = add(dp1[n][f][h], mult(mult(dp1[n - m][f][g], B[m][h]), C[n - 1][m]));
					}
*/
	//printf("after dp1: time = %.5lf\n", getCurrentTime());

	for (int x = 1; x < N; x++)
		for (int y = 1; x + y < N; y++)
			dp2[x + y] = add(dp2[x + y], mult(mult(A[x][1], A[y][1]), C[x + y - 1][y]));
	for (int n = 1; n < N; n++)
		for (int m = 1; m <= n; m++)
			dp2[n] = add(dp2[n], mult(mult(dp2[n - m], A[m][1]), C[n - 1][m]));

	for (int n = 1; n < N; n++) {
		for (int x = 0; x < 2; x++)
			for (int y = 0; y < 2; y++) {
				if (x + y == 0) continue;
				D[n] = add(D[n], dp1[n][x][y]);
			}
		D[n] = sub(D[n], dp2[n]);
	}

	E[0] = 1;
	for (int n = 1; n < N; n++)
		for (int m = 1; m <= n; m++)
			E[n] = add(E[n], mult(mult(E[n - m], D[m]), C[n - 1][m - 1]));

	printf("%lld\n", E[k]);

	return 0;
}