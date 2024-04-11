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
ll mult(ll x, ll y) {
	return ((x % MOD) * (y % MOD)) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}

const int N = 200200;
int n;
ll k;
ll ans[N];
vector<int> d[N];
ll c[N];
ll dp[N];
ll mu[N];
ll prefMu[N];

void precalc() {
	for (int x = 1; x < N; x++)
		for (int y = x; y < N; y += x)
			d[y].push_back(x);
	/*
	mu[1] = 1;
	for (int x = 1; x < N; x++)
		for (int y = 2 * x; y < N; y += x)
			mu[y] -= mu[x];
	for (int i = 1; i < N; i++)
		prefMu[i] = prefMu[i - 1] + mu[i];
	*/
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	precalc();

	scanf("%d%lld", &n, &k);

	for (int s = n + 1; s < 2 * n - 1; s++) {
		int l = s - n, r = n - 1;
		for (int x : d[s]) {
			c[x] = (r / x) - (l / x);
		}
		for (int i = (int)d[s].size() - 1; i >= 0; i--) {
			int x = d[s][i];
			for (int y : d[x])
				if (y != x)
					c[y] -= c[x];
		}
		for (int g : d[s]) {
			if (s - g >= n)
				ans[s - n] += c[g];
		}
	}
	
//	for (int i = 1; i < n; i++)
//		eprintf("%lld ", ans[i]);
//	eprintf("\n");

//	return 0;

	for (int m = 2; m <= n; m++) {
		dp[m] = (ll)m * (m - 1) / 2;
		ll b = (ll)sqrt(m);
		while(b * b < m) b++;
		for (int i = 2; i <= b; i++)
			dp[m] -= dp[m / i];
		for (int i = b; i >= 1; i--) {
			ll z = m / i;
			if (z > b) {
				dp[m] -= (z - b) * dp[i];
				b = z;
			}
		}
	}

	for (int g = 1; g < n; g++) {
		ans[g] += dp[(n - 1) / g + 1];
	}

//	for (int i = 1; i < n; i++)
//		eprintf("%lld ", ans[i]);
//	eprintf("\n");

	ll res = 0;
	for (int i = 1; i < n; i++) {
		ans[i] %= MOD;
		res = add(res, mult(ans[i], bin_pow(k, i)));
	}
	res = mult(res, rev(bin_pow(k, n)));
	printf("%lld\n", res);

	return 0;
}