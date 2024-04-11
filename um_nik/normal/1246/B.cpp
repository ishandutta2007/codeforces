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

const int N = 100100;
int d[N];
unordered_map<int, int> mapchik;
int n, k;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++) {
		if (d[i] != 0) continue;
		for (int j = i; j < N; j += i)
			if (d[j] == 0)
				d[j] = i;
	}

	scanf("%d%d", &n, &k);
	while(n--) {
		int x;
		scanf("%d", &x);
		mapchik[x]++;
	}
	ll ans = 0;
	for (pii t : mapchik) {
		int x = t.first;
		ll w = t.second;
		bool sqGood = true;
		ll z = 1;
		while(x > 1) {
			int p = d[x];
			int q = 0;
			while(x % p == 0) {
				x /= p;
				q++;
			}
			q %= k;
			sqGood &= ((2 * q) % k == 0);
			q = k - q;
			if (q == k) q = 0;
			for (int i = 0; z < (ll)t.first && i < q; i++)
				z *= p;
		}
		if (sqGood) ans += w * (w - 1) / 2;
		if (z >= t.first) continue;
		for (ll r = 1;; r++) {
			ll s = z;
			for (int i = 0; x < (ll)t.first && i < k; i++)
				s *= r;
			if (s >= (ll)t.first) break;
			ans += w * (mapchik.count(s) == 0 ? 0 : mapchik[s]);
		}
	}
	printf("%lld\n", ans);

	return 0;
}