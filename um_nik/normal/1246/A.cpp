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

ll need(ll x) {
	ll ans = 0;
	while(x > 0) {
		ans += x & 1;
		x >>= 1;
	}
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll n, p;
	scanf("%lld%lld", &n, &p);
	for (ll k = 1;; k++) {
		ll x = n - k * p;
		if (x < k) {
			printf("-1\n");
			return 0;
		}
		if (need(x) <= k) {
			printf("%lld\n", k);
			return 0;
		}
	}

	return 0;
}