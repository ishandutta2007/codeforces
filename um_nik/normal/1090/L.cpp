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

ll t, n, a, b, k;

bool solve(ll m) {
	return m * k <= min(a, m) * ((n + 1) / 2) + min(b, m) * (n / 2);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%lld%lld%lld%lld%lld", &t, &n, &a, &b, &k);
	ll l = 0, r = t + 1;
	while(r - l > 1) {
		ll x = (l + r) / 2;
		if (solve(x))
			l = x;
		else
			r = x;
	}
	printf("%lld\n", l);

	return 0;
}