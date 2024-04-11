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


const int N = (int)1e6 + 7;
int a[N];
int n;
ll p;

void solve() {
	scanf("%d%lld", &n, &p);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (p == 1) {
		printf("%d\n", n & 1);
		return;
	}
	sort(a, a + n);
	ll ans1 = 1, ans2 = 1;
	for (int i = n - 2; i >= 0; i--) {
		int d = a[i + 1] - a[i];
		if (ans1 != 0) {
			while(d > 0 && ans1 < N) {
				ans1 *= p;
				ans2 = mult(ans2, p);
				d--;
			}
		}
		ans2 = mult(ans2, bin_pow(p, d));
		if (ans1 == 0) {
			ans1 = ans2 = 1;
		} else {
			ans1--;
			ans2 = sub(ans2, 1);
		}
	}
	ans2 = mult(ans2, bin_pow(p, a[0]));
	printf("%lld\n", ans2);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}