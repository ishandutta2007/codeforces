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

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	ll g = 0;
	ll x;
	while(n--) {
		scanf("%lld", &x);
		g = gcd(g, x);
	}
	int ans = 0;
	for (ll x = 1; x * x <= g; x++) {
		if (g % x) continue;
		ans++;
		if (x * x != g) ans++;
	}
	printf("%d\n", ans);

	return 0;
}