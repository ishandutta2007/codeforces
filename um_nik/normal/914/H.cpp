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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define mp make_pair

ull INF;
ull MOD;
ull add(ull x, ull y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ull sub(ull x, ull y) {
	if (x < y) x += MOD;
	return x - y;
}
ull mult(ull x, ull y) {
	return (x * y) % MOD;
}

const int N = 222;
ull C[N][N];
int d;
ull a[N];
ull b[N][N];
ull dp[N][N];

ull solve(int n) {
	for (int i = 0; i <= min(n - 1, d); i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = 0;
	dp[0][n - 1] = 1 % MOD;
	for (int i = 0; i < min(n - 1, d); i++)
		for (int x = 0; x < n; x++) {
			dp[i][x] %= MOD;
			if (dp[i][x] == 0) continue;
			for (int y = 1; y <= x; y++) {
				dp[i + 1][x - y] += dp[i][x] * ((a[y] * C[x - 1][y - 1]) % MOD) % MOD;
			}
		}
	ull res = 0;
	for (int i = 0; i <= min(n - 1, d); i++) {
		b[n][i] = dp[i][0] % MOD;
		res += dp[i][0] % MOD;
	}
	return res % MOD;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d%d%llu", &n, &d, &MOD);
	if (n == 1) {
		throw;
		printf("0\n");
		return 0;
	}
	if (n == 2) {
		ull ans = 4;
		printf("%llu\n", ans % MOD);
		return 0;
	}
	if (d == 1) {
		printf("0\n");
		return 0;
	}

	d--;
	for (int i = 0; i < N; i++)
		C[i][0] = C[i][i] = 1 % MOD;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	a[0] = 1 % MOD;
	for (int i = 1; i < n; i++)
		a[i] = solve(i);
	d++;
	a[n] = solve(n);
	
	ull ans = sub(a[n], b[n][1]);
	ans = add(ans, ans);

	for (int x = 1; x < n - 1; x++) {
		ull sum = 0;
		for (int i = 2; i <= d - 2; i++)
			sum = add(sum, b[n - x][i]);
		for (int i = 2; i <= d - 2; i++) {
			ans = add(ans, mult(sum, b[x + 1][i]));
			sum = sub(sum, b[n - x][d - i]);
		}
	}
	for (int x = 1; x <= n; x++)
		for (int y = 1; x + y <= n; y++)
			ans = add(ans, mult(sub(a[x], b[x][1]), sub(a[y], b[y][1])));


	ans *= n * (n - 1) * 2;
	ans %= MOD;
	printf("%llu\n", ans);

	return 0;
}