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

const int K = 52;
ll dp[K][K];
ll rv[K];
int n;
ll pp[K][2];
ll ANS = 0;

void brute(int pos, ll x, ll q) {
	if (pos == n) {
		ANS = add(ANS, mult(x, q));
		return;
	}
	for (int i = 0; i <= pp[pos][1]; i++) {
		brute(pos + 1, x, mult(q, dp[pp[pos][1]][i]));
		x = mult(x, pp[pos][0] % MOD);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int k;
	ll X;
	scanf("%lld%d", &X, &k);

	for (int i = 1; i < K; i++)
		rv[i] = rev(i);

	for (int p = 0; p < K; p++) {
		dp[p][p] = 1;
		for (int t = 0; t < k; t++) {
			ll sum = 0;
			for (int i = K - 2; i >= 0; i--) {
				sum = add(sum, mult(dp[p][i], rv[i + 1]));
				dp[p][i] = sum;
			}
		}
	}
	for (ll x = 2; x * x <= X; x++) {
		if (X % x) continue;
		pp[n][0] = x;
		while(X % x == 0) {
			pp[n][1]++;
			X /= x;
		}
		n++;
	}
	if (X > 1) {
		pp[n][0] = X;
		pp[n][1] = 1;
		n++;
	}
	brute(0, 1, 1);
	printf("%lld\n", ANS);

	return 0;
}