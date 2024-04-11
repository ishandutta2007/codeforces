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

const int MOD = (int)1e9 + 7;
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

const int N = 62;
const int K = 12;
int dp[(1 << K) + 5][N];
int C[N][N];
int a[N];
int b[N];
int d[N];
bool used[N];
int n, m;

int solve(int k) {
	for (int mask = 0; mask < (1 << m); mask++)
		for (int i = 0; i <= k; i++)
			dp[mask][i] = 0;
	for (int i = 0; i < k; i++) {
		dp[d[i]][1] = add(dp[d[i]][1], 1);
	}
	for (int p = 1; p < k; p++) {
		for (int mask = 0; mask < (1 << m); mask++) {
			if (dp[mask][p] == 0) continue;
			int cnt = 0;
			for (int i = 0; i < k; i++) {
				int z = mask & d[i];
				if (z == 0) continue;
				if (z == d[i]) {
					cnt++;
					continue;
				}
				dp[mask | d[i]][p + 1] = add(dp[mask | d[i]][p + 1], dp[mask][p]);
			}
			if (cnt < p) throw;
			dp[mask][p + 1] = add(dp[mask][p + 1], mult(cnt - p, dp[mask][p]));
		}
	}
	int res = 0;
	for (int mask = 0; mask < (1 << m); mask++)
		res = add(res, dp[mask][k]);
	return res;
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

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
//	for (int i = 0; i < n; i++)
//		eprintf("%d ", a[i]);
//	eprintf("\n");
	for (int i = 0; i < n; i++) {
		bool ok = true;
		for (int j = 0; j < i; j++)
			if (a[i] % a[j] == 0)
				ok = false;
		if (!ok) continue;
		int cnt = 0;
		for (int j = i + 1; j < n; j++)
			if (a[j] % a[i] == 0)
				cnt++;
		if (cnt < 2) continue;
		for (int j = i + 1; j < n; j++)
			if (a[j] % a[i] == 0)
				b[j] |= 1 << m;
		m++;
	}
	if (m > K) throw;

//	for (int i = 0; i < n; i++)
//		eprintf("%d ", b[i]);
//	eprintf("\n");

	int ans = 1;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		if (b[i] == 0) continue;
		int mask = b[i];
		bool ch = true;
		while(ch) {
			ch = false;
			for (int j = 0; j < n; j++) {
				if (used[j]) continue;
				int z = mask & b[j];
				if (z == 0) continue;
				if (z == b[j]) continue;
				mask |= b[j];
				ch = true;
			}
		}
		int k = 0;
		for (int j = 0; j < n; j++) {
			if (used[j]) continue;
			if (b[j] == 0) continue;
			if (mask & b[j]) {
				d[k++] = b[j];
				used[j] = 1;
			}
		}
		ans = mult(ans, C[sum + k - 1][k - 1]);
		ans = mult(ans, solve(k));
		sum += k - 1;
	}
	printf("%d\n", ans);

	return 0;
}