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


const int N = (int)1e6 + 7;
ll A[N];
ll B[N];

ll C2(ll n) {
	ll x = mult(n + 1, n + 2);
	while(x % 2) x += MOD;
	return x / 2;
}
ll C3(ll n) {
	ll x = mult(n + 1, mult(n + 2, n + 3));
	while(x % 6) x += MOD;
	return x / 6;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	A[0] = 1;
	for (int i = 1; i < N; i++)
		A[i] = C2(A[i - 1]);

	for (int i = 1; i < N; i++)
		B[i] = C2(sub(A[i - 1], 1));
	for (int i = N - 1; i > 0; i--)
		B[i] = sub(B[i], B[i - 1]);

	int n;
	scanf("%d", &n);
	ll ans = C3(A[n - 1]);
	if (n == 1)
		ans = sub(ans, 1);
	else
		ans = sub(ans, C3(A[n - 2]));
	ans = sub(mult(ans, 2), 1);
	ll cur = 0;
	for (int i = 1; i < n; i++) {
		ans = add(ans, mult(cur, B[n - i]));
		cur = add(cur, B[i]);
	}
	printf("%lld\n", ans);
	return 0;
}