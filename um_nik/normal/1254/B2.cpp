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

const ll INF = (ll)2e18;
const int N = (int)1e6 + 77;
int n;
ll a[N];

ll solve(ll d) {
//	eprintf("solve %lld\n", d);
	ll ans = 0;
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		ll h = a[i];
		ll z = min(h, d - cur);
		h -= z;
		cur += z;
		if (cur <= d / 2) ans += cur;
		if (cur > d / 2) ans += d - cur;
		if (cur == d) cur = 0;
		if (h > 0) {
			h %= d;
			cur = h;
			if (cur <= d / 2) ans += cur;
			if (cur > d / 2) ans += d - cur;
		}
//		eprintf("%lld ", cur);
	}
	if (cur != 0) throw;
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	if (sum == 1) {
		printf("-1\n");
		return 0;
	}
	ll ans = INF;
	for (ll x = 2; x * x <= sum; x++) {
		if (sum % x) continue;
		ans = min(ans, solve(x));
		while(sum % x == 0) sum /= x;
	}
	if (sum > 1) ans = min(ans, solve(sum));
	printf("%lld\n", ans);

	return 0;
}