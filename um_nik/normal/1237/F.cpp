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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;
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

const int N = 3636;
int f[N];
int C[N][N];
int dp[N][N];
int A[2][N], B[2][N];
bool u1[N], u2[N];
int n, m, k;
int sumA = 0, sumB = 0;

void addA(int len) {
	for (int i = 0; i <= sumA + len; i++)
		A[1][i] = 0;
	for (int x = 0; x <= sumA; x++)
		for (int y = 0; y <= len; y++)
			A[1][x + y] = add(A[1][x + y], mult(A[0][x], dp[len][y]));
	sumA += len;
	for (int i = 0; i <= sumA; i++)
		A[0][i] = A[1][i];
}

void addB(int len) {
	for (int i = 0; i <= sumB + len; i++)
		B[1][i] = 0;
	for (int x = 0; x <= sumB; x++)
		for (int y = 0; y <= len; y++)
			B[1][x + y] = add(B[1][x + y], mult(B[0][x], dp[len][y]));
	sumB += len;
	for (int i = 0; i <= sumB; i++)
		B[0][i] = B[1][i];
}

int getA(int x, int y) {
	if (2 * x + y > sumA) return 0;
	return mult(A[0][x], C[sumA - 2 * x][y]);
}
int getB(int x, int y) {
	if (2 * x + y > sumB) return 0;
	return mult(B[0][x], C[sumB - 2 * x][y]);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < N; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);

	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);

	dp[0][0] = 1;
	for (int i = 0; i < N - 3; i++)
		for (int j = 0; j <= i; j++) {
			dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
			dp[i + 2][j + 1] = add(dp[i + 2][j + 1], dp[i][j]);
		}

	scanf("%d%d%d", &n, &m, &k);
	k *= 2;
	u1[0] = u1[n + 1] = u2[0] = u2[m + 1] = 1;
	while(k--) {
		int x, y;
		scanf("%d%d", &x, &y);
		u1[x] = 1;
		u2[y] = 1;
	}
	A[0][0] = 1;
	B[0][0] = 1;
	int lst = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (!u1[i]) {
			continue;
		}
		int len = i - lst - 1;
		if (len > 0) addA(len);
		lst = i;
	}
	lst = 0;
	for (int i = 1; i <= m + 1; i++) {
		if (!u2[i]) {
			continue;
		}
		int len = i - lst - 1;
		if (len > 0) addB(len);
		lst = i;
	}

	int ans = 0;
	for (int x = 0; 2 * x <= sumA; x++)
		for (int y = 0; 2 * y <= sumB; y++) {
			ans = add(ans, mult(mult(f[x], f[y]), mult(getA(x, y), getB(y, x))));
		}
	printf("%d\n", ans);

	return 0;
}