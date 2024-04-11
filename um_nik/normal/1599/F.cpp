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


const int N = 200200;
int n, q;
ll a[N];
ll pref[N], pref2[N], pref3[N];

ll getSum2(ll x, ll d, ll n) {
	ll res = 0;
	res = mult(n, mult(x, x));
	res = add(res, mult(mult(mult(2, d), x), n * (n - 1) / 2 % MOD));
	res = add(res, mult(mult(d, d), n * (n - 1) * (2 * n - 1) / 6 % MOD));
	return res;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	ll X = myRand(MOD);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		a[i] = add(a[i], X);
		pref[i + 1] = add(pref[i], a[i]);
		pref2[i + 1] = add(pref2[i], mult(a[i], a[i]));
		pref3[i + 1] = add(pref3[i], mult(a[i], mult(a[i], a[i])));
	}
	while(q--) {
		int l, r;
		ll d;
		scanf("%d%d%lld", &l, &r, &d);
		l--;
		ll sum = sub(pref[r], pref[l]);
		ll t = (ll)(r - l) * (r - l - 1) / 2;
		t %= MOD;
		t = mult(t, d);
		t = sub(sum, t);
		t = mult(t, rev(r - l));
		ll x = t;
		if (sub(pref2[r], pref2[l]) == getSum2(x, d, r - l)) // && sub(pref3[r], pref3[l]) == getSum3(x, d, r - l))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}