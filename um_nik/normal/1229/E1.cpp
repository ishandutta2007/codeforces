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

const int N = 7;
const int M = (1 << N) + 1;
int ppc[M];
int idInPpc[M];
vector<int> maskForPpc[N + 1];
ll trans[N + 1][M][M];
int n;
unordered_map<ll, ll> dp[N + 1];
ll A[N][N];

void precalc() {
	for (int mask = 1; mask < (1 << n); mask++)
		ppc[mask] = ppc[mask >> 1] + (mask & 1);
	for (int mask = 0; mask < (1 << n); mask++) {
		int k = ppc[mask];
		idInPpc[mask] = (int)maskForPpc[k].size();
		maskForPpc[k].push_back(mask);
	}
	for (int k = 0; k <= n; k++)
		for (int i = 0; i < (int)maskForPpc[k].size(); i++) {
			int inM = maskForPpc[k][i];
			for (int mask = 0; mask < (1 << n); mask++) {
				ll res = 0;
				if ((mask & inM) == mask) continue;
				for (int v = 0; v < n; v++) {
					if (((mask >> v) & 1) == 0) continue;
					if ((inM >> v) & 1) continue;
					int nmask = inM | (1 << v);
					res |= 1LL << idInPpc[nmask];
				}
				trans[k][i][mask] = res;
			}
		}
}

void read() {
/*
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = rng() % 1000;
	return;
*/
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%lld", &A[i][j]);
			A[i][j] = mult(A[i][j], rev(100));
		}

}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	precalc();
	read();
	dp[0][1] = 1;
	for (int k = 0; k < n; k++)
		for (int mask = 0; mask < (1 << n); mask++) {
			ll W = 1;
			for (int i = 0; i < n; i++) {
				if ((mask >> i) & 1)
					W = mult(W, A[k][i]);
				else
					W = mult(W, sub(1, A[k][i]));
			}
			for (pll s : dp[k]) {
				ll zmask = s.first, val = s.second;
				ll nmask = 0;
				for (int i = 0; i < (int)maskForPpc[k].size(); i++) {
					if ((zmask >> i) & 1)
						nmask |= trans[k][i][mask];
				}
				if (nmask == 0) continue;
				val = mult(val, W);
				dp[k + 1][nmask] = add(dp[k + 1][nmask], val);
			}
		}
	printf("%lld\n", dp[n][1]);

	return 0;
}