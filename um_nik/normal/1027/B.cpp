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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

ll n;

void solve() {
	ll x, y;
	scanf("%lld%lld", &x, &y);
	x--;y--;
	ll ans = 0;
	if ((x + y) % 2 == 0) {
		ans += (x / 2) * n;
		if (x % 2 == 0) {
		} else {
			ans += (n + 1) / 2;
		}
		ans += y / 2;
	} else {
		ans += (n * n + 1) / 2;
		ans += (x / 2) * n;
		if (x % 2 == 0) {

		} else {
			ans += n / 2;
		}
		ans += y / 2;
	}
	printf("%lld\n", ans + 1);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int q;
	scanf("%lld%d", &n, &q);
	while(q--) solve();

	return 0;
}