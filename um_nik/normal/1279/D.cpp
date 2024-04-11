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

const int N = 1e6 + 7;
ll r[N];
ll a[N];
ll b[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	r[1] = 1;
	for (ll x = 2; x < N; x++)
		r[x] = sub(0, mult(r[MOD % x], MOD / x));

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		ll p = mult(r[k], r[n]);
		while(k--) {
			int x;
			scanf("%d", &x);
			a[x] = add(a[x], r[n]);
			b[x] = add(b[x], p);
		}
	}
	ll ans = 0;
	for (int i = 0; i < N; i++)
		ans = add(ans, mult(a[i], b[i]));
	printf("%lld\n", ans);

	return 0;
}