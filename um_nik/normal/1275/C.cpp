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
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}

const int N = 5050;
ll dp[2][N];
ll n, m;
int k;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%lld%lld%d", &n, &m, &k);
	dp[0][0] = 1;
	for (int i = 0; i < k; i++) {
		for (int g = 0; g <= min((int)n, k); g++)
			dp[1][g] = 0;
		for (int g = 0; g <= min((int)n, k); g++) {
			dp[1][g] = add(dp[1][g], mult(g, dp[0][g]));
			dp[1][g + 1] = add(dp[1][g + 1], mult(n - g, dp[0][g]));
		}
		for (int g = 0; g <= min((int)n, k); g++)
			dp[0][g] = dp[1][g];
	}
	m = rev(m);
	ll p = 1;
	ll ans = 0;
	for (int i = 0; i <= min((int)n, k); i++) {
		ans = add(ans, mult(p, dp[0][i]));
		p = mult(p, m);
	}
	printf("%lld\n", ans);

	return 0;
}