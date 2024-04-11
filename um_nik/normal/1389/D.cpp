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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
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

const ll INF = (ll)1e18;

ll getCost(int l1, int r1, int l2, int r2, int d) {
	if (l1 > l2) {
		swap(l1, l2);
		swap(r1, r2);
	}
	ll ans = 0;
	int w = 0;
	if (r1 < l2) {
		ans += l2 - r1;
		w = r2 - l1;
	} else {
		d = max(0, d - (min(r1, r2) - max(l1, l2)));
		w = max(r1, r2) - min(r1, r2) + max(l1, l2) - min(l1, l2);
	}
	if (d <= w) return ans + d;
	return ans + w + 2 * (d - w);
}

void solve() {
	int n, k, l1, l2, r1, r2;
	scanf("%d%d%d%d%d%d", &n, &k, &l1, &r1, &l2, &r2);
	ll ans = INF;
	for (int m = 1; m <= n; m++) {
		int d = k / m;
		ll w1 = getCost(l1, r1, l2, r2, d);
		ll w2 = getCost(l1, r1, l2, r2, d + 1);
//		eprintf("%d %lld %lld\n", m, w1, w2);
		d = k % m;
		ans = min(ans, d * w2 + (m - d) * w1);
	}
	printf("%lld\n", ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}