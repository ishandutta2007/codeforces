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

int n, m;
set<pii> a;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;y--;
		a.insert(mp(x, y));
		a.insert(mp(y, x));
	}
	for (int k = 1; k < n; k++) {
		if (n % k) continue;
		bool ok = true;
		for (pii t : a) {
			int x = (t.first + k) % n, y = (t.second + k) % n;
			if (a.count(mp(x, y)) == 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");

	return 0;
}