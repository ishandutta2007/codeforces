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

const int N = 200200;
vector<ll> a[N];
ll mx;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		while(k--) {
			ll x;
			scanf("%lld", &x);
			mx = max(mx, x);
			a[i].push_back(x);
		}
	}
	for (int i = 0; i < n; i++) {
		ll p = 0;
		for (ll x : a[i])
			p = max(p, x);
		ans += (mx - p) * (ll)a[i].size();
	}
	printf("%lld\n", ans);

	return 0;
}