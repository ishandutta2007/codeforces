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

const int N = (int)1e9 + 2;
//const int N = 1;

ll div2down(ll c) {
	if (c >= 0) return c / 2;
	return (c - 1) / 2;
}

ll solve5(ll Y, ll c) {
	if (Y < 0) return 0;
	ll ans = mult(mult(2, Y), mult(Y + 1, 2 * Y + 1));
	while(ans % 3 != 0) ans += MOD;
	ans /= 3;
	ans = sub(0, ans);
	ans = add(ans, mult(mult(Y, Y + 1), c - 1));
	ans = add(ans, mult(Y + 1, mult(c - div2down(c), 1 - div2down(c))));
	ans %= MOD;
	if (ans < 0) ans += MOD;
	return ans;
}

ll solve4(ll X, ll Y, ll c) {
	if (X <= 0) return 0;
//	eprintf("solve4 %lld %lld %lld\n", X, Y, c);
	ll ans = 0;
	while(-4 * Y + c > 0) {
		ans += mult(X, X - 1) - mult(4, mult(Y, X)) + mult(X, c);
		Y++;
	}
//	eprintf("after while %lld %lld\n", Y, ans);
	if (2 * (X - 1) - 4 * Y + c <= 0) return ans;
	ll maxY = (2 * (X - 1) + c - 1) / 4;
	assert(maxY >= Y);
	ans += mult(mult(X, X - 1), maxY - Y + 1);
	ans -= mult(sub(mult(maxY, maxY + 1), mult(Y, Y - 1)), mult(2, X));
	ans += mult(c, mult(X, maxY - Y + 1));
	ans -= sub(solve5(maxY, c), solve5(Y - 1, c));
	ans %= MOD;
	if (ans < 0) ans += MOD;
	return ans;
}

ll solve3(ll X, ll Y, ll c) {
	if (2 * X - 4 * Y + c > 0) {
		return sub(solve4(N, Y, c), solve4(X, Y, c));
	} else {
		return solve4(N, Y, c);
	}
}

int solve2(int X, int Y, int rx, int ry) {
//	eprintf("solve2 %d %d %d %d\n", X, Y, rx, ry);
	int c1 = (rx + 1) / 2;
	if ((c1 ^ rx ^ ry) & 1) c1++;
	int c2 = (ry + 1) / 2;
	if ((c2 ^ rx ^ ry) & 1) c2++;
	int c3 = (rx + ry + 2) / 3;
	if ((c3 ^ rx ^ ry) & 1) c3++;
//	eprintf("%d %d %d\n", c1, c2, c3);
	int ans = 0;
	ans = add(ans, mult(mult(2, N - Y), sub(mult(N, N - 1), mult(X, X - 1))));
	ans = add(ans, mult(mult(2, N - X), sub(mult(N, N - 1), mult(Y, Y - 1))));
	ans = add(ans, mult(c3, mult(N - X, N - Y)));
//	eprintf("before solve3 - %d\n", ans);
	ans = add(ans, solve3(X, Y, c1 - c3));
//	eprintf("after first solve3 - %d\n", ans);
	ans = add(ans, solve3(Y, X, c2 - c3));
//	eprintf("in solve2 - %d\n", ans);
	return ans;
}

/*
int solve(int X, int Y) {
	int ans = 0;
	for (int rx = 0; rx < 12; rx++)
		for (int ry = 0; ry < 12; ry++) {
			ans = add(ans, solve2((X - rx + 11) / 12, (Y - ry + 11) / 12, rx, ry));
		}
	return ans;
}
*/

int solve(int x, int y, int n, int m, int rx, int ry) {
//	if (rx != 2 || ry != 7) return 0;
	int ans = 0;
	x = (x - rx + 11) / 12;
	y = (y - ry + 11) / 12;
	n = (n - rx + 11) / 12;
	m = (m - ry + 11) / 12;
	ans = add(ans, solve2(x, y, rx, ry));
	ans = add(ans, solve2(n, m, rx, ry));
	ans = sub(ans, solve2(x, m, rx, ry));
	ans = sub(ans, solve2(n, y, rx, ry));
	return ans;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
//	t = 1;
	while(t--) {
		int x, y, n, m;
		scanf("%d%d%d%d", &x, &y, &n, &m);
		x--;y--;
		int ans = 0;
		for (int rx = 0; rx < 12; rx++)
			for (int ry = 0; ry < 12; ry++) {
				int cur = solve(x, y, n, m, rx, ry);
				ans = add(ans, cur);
//				eprintf("rx = %d, ry = %d, cur = %d\n", rx, ry, cur);
			}
		if (x == 2 && y == 2) ans = add(ans, 2);
		printf("%d\n", ans);
	}

	return 0;
}