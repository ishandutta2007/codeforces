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


const int N = 500500;
const int K = 60;
ll p2[K];
ll a[N];
int b[K];
int n;

void solve() {
	for (int i = 0; i < K; i++)
		b[i] = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		for (int k = 0; k < K; k++)
			if ((a[i] >> k) & 1)
				b[k]++;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll L = 0, R = 0;
		for (int k = 0; k < K; k++) {
			if ((a[i] >> k) & 1) {
				L = add(L, mult(b[k], p2[k]));
				R = add(R, mult(n, p2[k]));
			} else {
				R = add(R, mult(b[k], p2[k]));
			}
		}
		ans = add(ans, mult(L, R));
	}
	printf("%lld\n", ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	p2[0] = 1;
	for (int k = 1; k < K; k++)
		p2[k] = add(p2[k - 1], p2[k - 1]);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}