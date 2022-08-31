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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

/*
x = p1^a1 * p2^a2 * ... * pk^ak
d(x) = (a1 + 1) * (a2 + 1) * ... * (ak + 1)

y = p1^a1 * p2^a2 * ... * pk^ak
x = p1^(a1+1) * p2^a2 * ... * pk^ak
w(y-x) = (a2 + 1) * (a3 + 1) * ... * (ak + 1) = d(x) - d(y)

v = p1^a1 * ... * pk^ak * q1^a1 * ... * r1^b1 * ...
u = p1^a1 * ... * pk^ak * q1^b1 * ... * r1^a1 * ...
(ai > bi)

v -> ... -> w -> ... -> u
d(v) - d(w) + d(u) - d(w) = d(v) + d(u) - 2 d(w)

v -> ... -> mid -> ... -> u
L = d(v) + d(mid) - 2 * d(g1) + d(u) + d(mid) - 2 * d(g2) >= d(v) + d(u) - 2 * d(w)
d(mid) + d(w) >= d(g1) + d(g2)
*/


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


const int N = 52;
ll p[N];
int n;
ll C[N][N];
int a[N], b[N];

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < N; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);

	ll x;
	scanf("%lld", &x);
	for (ll y = 2; y * y <= x; y++) {
		if (x % y) continue;
		p[n++] = y;
		while(x % y == 0) x /= y;
	}
	if (x > 1) p[n++] = x;
/*
	for (int i = 0; i < n; i++)
		printf("%lld ", p[i]);
	printf("\n");
*/
/*
	(a1+a2+...+ak)!/a1!/a2!/.../ak!

	a1!/0!/a1! * (a1+a2)!/a1!/a2! * (a1+a2+a3)!/(a1+a2)!/a3! * ... *
	(a1+a2+...+ak)!/(a1+a2+...+a(k-1))!/ak!
*/

	int q;
	scanf("%d", &q);
	while(q--) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		for (int i = 0; i < n; i++) {
			a[i] = b[i] = 0;
			while(x % p[i] == 0) {
				x /= p[i];
				a[i]++;
			}
			while(y % p[i] == 0) {
				y /= p[i];
				b[i]++;
			}
		}
		ll ans1 = 1, ans2 = 1;
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; i++) {
			int z = min(a[i], b[i]);
			sum1 += a[i] - z;
			sum2 += b[i] - z;
			ans1 = mult(ans1, C[sum1][a[i] - z]);
			ans2 = mult(ans2, C[sum2][b[i] - z]);
		}
		printf("%lld\n", mult(ans1, ans2));
	}

	return 0;
}