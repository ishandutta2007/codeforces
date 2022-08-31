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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

char s[10];

bool query(ll l, ll r) {
	printf("%lld %lld\n", l, r);
	fflush(stdout);
	scanf("%s", s);
	if (s[0] == 'B') exit(0);
	if (s[0] == 'Y' && l == r) exit(0);
	return s[0] == 'Y';
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll n;
	ll l, r;
	ll k;
	scanf("%lld%lld", &n, &k);
	l = 1;
	r = n;
	while(true) {
		ll len = r - l + 1;
		if (len > 4 * k + 3) {
			ll m = (l + r) / 2;
			if (query(l, m))
				r = m;
			else
				l = m + 1;
		} else {
			ll x = l + rng() % len;
			if (query(x, x)) throw;
		}
		l = max(1LL, l - k);
		r = min(n, r + k);
	}

	return 0;
}