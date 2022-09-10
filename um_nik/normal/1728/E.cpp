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
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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

const int N = 300300;
int n;
ll a[N];
ll pref[N];
ll T;
int mid;

int euclid(int x, int y, int &k, int &l) {
	if (y == 0) {
		k = 1;
		l = 0;
		return x;
	}
	int g = euclid(y, x % y, l, k);
	l -= k * (x / y);
	return g;
}

void solve() {
	int p, q;
	scanf("%d%d", &q, &p);
	int k, l;
	int g = euclid(p, q, k, l);
	if (n % g != 0) {
		printf("-1\n");
		return;
	}
	k %= q / g;
	if (k < 0) k += q / g;
	k = ((ll)k * (n / g)) % (q / g);
	if ((ll)k * p > n) {
		printf("-1\n");
		return;
	}
	assert((n - k * p) % q == 0);
	k *= p;
	ll t = (ll)p * q / g;
	k += ((mid - k) / t) * t;
	ll ans = pref[k];
	if (k + t <= n) ans = min(ans, pref[k + t]);
	printf("%lld\n", T - ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	T = 0;
	for (int i = 0; i < n; i++) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		T += x;
		a[i] = x - y;
	}
	sort(a, a + n);
	pref[0] = 0;
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + a[i];
	mid = 0;
	while(mid < n && a[mid] < 0) mid++;

	int q;
	scanf("%d", &q);
	while(q--) solve();

	return 0;
}