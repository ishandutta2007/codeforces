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

const ll MOD = (ll)1e6 + 3;
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

ll rev[MOD];

const int N = 12;
ll a[N];
ll b[N], c[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	rev[1] = 1;
	for (ll x = 2; x < MOD; x++)
		rev[x] = sub(0, mult(MOD / x, rev[MOD % x]));

	for (int i = 0; i < N; i++) {
		printf("? %d\n", i);
		fflush(stdout);
		for (int j = 0; j < N; j++)
			a[j] = 0;
		a[0] = 1;
		for (int j = 0; j < N; j++) {
			if (j == i) continue;
			for (int k = N - 1; k > 0; k--)
				a[k] = sub(a[k - 1], mult(a[k], j));
			a[0] = sub(0, mult(a[0], j));
		}
		ll y;
		scanf("%lld", &y);
		if (y == -1) throw;
		for (int j = 0; j < N; j++) {
			if (j == i) continue;
			y = mult(y, rev[sub(i, j)]);
		}
		for (int k = 0; k < N; k++)
			c[k] = add(c[k], mult(y, a[k]));
	}
/*
	for (int k = 0; k < N; k++) {
		printf("%lld ", c[k]);
	}
	printf("\n");
	fflush(stdout);
*/
	for (ll x = 0; x < MOD; x++) {
		ll w = 0;
		for (int k = N - 1; k >= 0; k--) {
			w = add(mult(w, x), c[k]);
		}
		if (w == 0) {
			printf("! %lld\n", x);
			fflush(stdout);
			return 0;
		}
	}
	printf("! -1\n");
	fflush(stdout);

	return 0;
}