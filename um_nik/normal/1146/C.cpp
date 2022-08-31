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
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int k = 0;; k++) {
		int m = 0;
		for (int i = 0; i < n; i++)
			if ((i >> k) & 1)
				m++;
		if (m == 0 || m == n) break;
		printf("%d %d", m, n - m);
		for (int i = 0; i < n; i++) {
			if ((i >> k) & 1) {
				printf(" %d", i + 1);
			}
		}
		for (int i = 0; i < n; i++) {
			if ((i >> k) & 1) {} else {
				printf(" %d", i + 1);
			}
		}
		printf("\n");
		fflush(stdout);
		int x;
		scanf("%d", &x);
		ans = max(ans, x);
	}
	printf("-1 %d\n", ans);
	fflush(stdout);
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