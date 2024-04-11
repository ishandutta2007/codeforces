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
map<pii, int> mapchik;
ll a[N];
int n;
ll ans = 0;

void add(int p, ll w) {
	ans -= max(0LL, a[p]);
	a[p] += w;
	ans += max(0LL, a[p]);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		ans += a[i];
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--;z--;
		pii t = mp(x, y);
		if (mapchik.count(t)) {
			add(mapchik[t], 1);
			mapchik.erase(t);
		}
		if (z != -1) {
			add(z, -1);
			mapchik[t] = z;
		}
		printf("%lld\n", ans);
	}

	return 0;
}