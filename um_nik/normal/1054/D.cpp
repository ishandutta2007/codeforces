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

map<int, int> mapchik;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);
	ll ans = (ll)n * (n + 1) / 2;
	k = 1 << k;
	k--;
	int x = 0;
	mapchik[0] = 1;
	while(n--) {
		int y;
		scanf("%d", &y);
		x ^= y;
		if (x & 1) x ^= k;
		mapchik[x]++;
	}
	for (auto t : mapchik) {
		ll z = t.second;
		ll z1 = z / 2;
		ll z2 = z - z1;
		ans -= z1 * (z1 - 1) / 2;
		ans -= z2 * (z2 - 1) / 2;
	}
	printf("%lld\n", ans);

	return 0;
}