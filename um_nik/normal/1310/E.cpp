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

const int N = 2024;
ll P[N];
ll dp[2][N][N];
int C;
int k;
ll ans = 0;
int a[N];
int b[2][N];
int sz;

bool check() {
//	for (int i = 0; i < sz; i++)
//		eprintf("%d ", a[i]);
//	eprintf("\n");
	int t = 0, nt = 1;
	int s1 = 0, s2 = 0;
	for (int i = 0; i < sz; i++)
		b[t][s1++] = a[i];
	int kk = k;
	while(kk > 2) {
		kk--;
		swap(t, nt);
		s2 = s1;
		s1 = 0;
		for (int i = 1; i <= s2; i++) {
			if (s1 + b[nt][s2 - i] > 65) return false;
			for (int j = 0; j < b[nt][s2 - i]; j++)
				b[t][s1++] = i;
		}
	}
	int sum = 0, sumAll = 0;
	for (int i = 0; i < s1; i++) {
		sum += b[t][i];
		sumAll += sum;
//		eprintf("sum = %d, sumAll = %d\n", sum, sumAll);
		if (sumAll > C) return false;
	}
//	eprintf("good!\n");
	return true;
}

void brute(int p) {
//	eprintf("brute %d %d\n", mx, p);
	a[sz++] = p;
	if (!check()) {
		sz--;
		return;
	}
	sz--;
	brute(p + 1);
	for (int i = 1;; i++) {
		a[sz++] = p;
		if (!check()) {
			sz -= i;
			return;
		}
		ans++;
		brute(p + 1);
	}
}

void brute3(int p, int sum, int sumAll) {
//	eprintf("brute %d %d\n", mx, p);
	if (sumAll + sum + p > C) return;
	brute3(p + 1, sum, sumAll);
	for (int i = 1;; i++) {
		sum += p;
		sumAll += sum;
		if (sumAll > C) return;
		ans++;
		brute3(p + 1, sum, sumAll);
	}
}


int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &C, &k);

	if (k == 1) {
		P[0] = 1;
		for (int x = 1; x <= C; x++) {
			P[x] = 0;
			for (int t = 1;; t++) {
				if (t * (3 * t - 1) > 2 * x) break;
				if (t & 1)
					P[x] = add(P[x], P[x - t * (3 * t - 1) / 2]);
				else
					P[x] = sub(P[x], P[x - t * (3 * t - 1) / 2]);
				if (t * (3 * t + 1) > 2 * x) break;
				if (t & 1)
					P[x] = add(P[x], P[x - t * (3 * t + 1) / 2]);
				else
					P[x] = sub(P[x], P[x - t * (3 * t + 1) / 2]);
			}
		}
		for (int i = 1; i <= C; i++)
			ans = add(ans, P[i]);
		printf("%lld\n", ans);
		return 0;
	}

	if (k == 2) {
		dp[0][C][C] = 1;
		for (int t = 1; t <= C; t++) {
			for (int i = 0; i * t <= C; i++)
				for (int j = 0; j <= C; j++)
					dp[1][i][j] = 0;
			for (int i = C / t; i > 0; i--)
				for (int x = i * t; x <= C; x++) {
					dp[0][i - 1][x] = add(dp[0][i - 1][x], dp[0][i][x]);
					int y = x - i * t;
					dp[1][min(i, y / (t + 1))][y] = add(dp[1][min(i, y / (t + 1))][y], dp[0][i][x]);
				}
			for (int i = 0; i * t <= C; i++)
				for (int j = 0; j <= C; j++) {
					ans = add(ans, dp[1][i][j]);
					if (i > 0)
						dp[0][i][j] = dp[1][i][j];
				}
		}
		printf("%lld\n", ans);
		return 0;
	}

//	if (k == 3)
//		brute3(1, 0, 0);
//	else
	brute(1);
	printf("%lld\n", ans);

	return 0;
}