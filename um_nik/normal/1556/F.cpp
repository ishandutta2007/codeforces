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

const int N = 14;
const int M = (1 << N) + 3;
int n;
ll a[N];
ll dp[M];
ll p[N][N];
ll q[N][M];

ll solve() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			p[i][j] = mult(a[i], rev(a[i] + a[j]));
	for (int mask = 0; mask < (1 << n); mask++)
		dp[mask] = 0;
	for (int v = 0; v < n; v++) {
		for (int mask = 0; mask < (1 << n); mask++) {
			if ((mask >> v) & 1) continue;
			q[v][mask] = 1;
			for (int i = 0; i < n; i++)
				if ((mask >> i) & 1)
					q[v][mask] = mult(q[v][mask], p[i][v]);
		}
	}
	for (int mask = 1; mask < (1 << n); mask += 2) {
		dp[mask] = 1;
		int oth = ((1 << n) - 1) ^ mask;
		/*
		for (int i = 0; i < n; i++)
			if ((mask >> i) & 1)
				dp[mask] = mult(dp[mask], q[i][oth]);
		*/
		for (int smask = (mask - 1) & mask; smask > 0; smask = (smask - 1) & mask) {
			if ((smask & 1) == 0) continue;
			ll cur = dp[smask];
			oth = mask ^ smask;
			for (int i = 0; i < n; i++) {
				if ((smask >> i) & 1)
					cur = mult(cur, q[i][oth]);
			}
			dp[mask] = sub(dp[mask], cur);
		}
		//eprintf("dp[%d] = %lld\n", mask, dp[mask]);
	}
	return dp[(1 << n) - 1];
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	/*
	n = 14;
	for (int i = 0; i < n; i++)
		a[i] = i + 2;
	*/
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		swap(a[i], a[0]);
		ans = add(ans, solve());
	}
	printf("%lld\n", ans);

	return 0;
}