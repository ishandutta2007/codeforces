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

void solve() {
	ll x, y;
	scanf("%lld%lld", &x, &y);
	x = abs(x - y);
	ll n = 0;
	// n * (n + 1) / 2 >= x
	// n * (n + 1) >= 2 * x
	n = (ll)sqrt(2 * x);
	n = max(n, 0LL);
	while(n > 0 && n * (n + 1) / 2 > x) n--;
	while(n * (n + 1) / 2 < x || ((n * (n + 1) / 2 - x) & 1)) n++;
	printf("%lld\n", n);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}