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

pll a[4];

ll calc(vector<ll> x) {
	sort(all(x));
	ll res = 0;
	for (int i = 0; i < (int)x.size(); i++)
		res += abs(x[i] - x[1]);
	return res;
}

void solve() {
	for (int i = 0; i < 4; i++)
		scanf("%lld%lld", &a[i].first, &a[i].second);
	vector<ll> d;
	d.push_back(0LL);
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++) {
			d.push_back(abs(a[i].first - a[j].first));
			d.push_back(abs(a[i].second - a[j].second));
		}
	sort(all(d));
	d.resize(unique(all(d)) - d.begin());
	ll ans = (ll)1e18;
	sort(a, a + 4);
	do {
		vector<ll> x(4), y(4);
		for (ll w : d) {
			for (int i = 0; i < 4; i++) {
				x[i] = a[i].first;
				y[i] = a[i].second;
			}
			x[2] -= w;
			x[3] -= w;
			y[1] -= w;
			y[2] -= w;
			ans = min(ans, calc(x) + calc(y));
		}
	} while(next_permutation(a, a + 4));
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