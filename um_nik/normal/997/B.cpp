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

const ll INF = (ll)1e15;
ll a[100][2];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll n;
	scanf("%lld", &n);
	for (int i = 0; i < 49; i++) {
		a[i][0] = INF;
		a[i][1] = -INF;
	}
	for (ll x = 0; x <= 100; x++)
		for (ll y = 0; y <= 100; y++) {
			if (x + y > n) continue;
			ll z1 = x * 5 + y * 10 + (n - x - y) * 1;
			ll z2 = x * 5 + y * 10 + (n - x - y) * 50;
			a[z1 % 49][0] = min(a[z1 % 49][0], z1);
			a[z2 % 49][1] = max(a[z2 % 49][1], z2);
		}
	ll ans = 0;
	for (int i = 0; i < 49; i++) {
		if (a[i][1] < 0) continue;
		ans += (a[i][1] - a[i][0]) / 49 + 1;
	}
	printf("%lld\n", ans);

	return 0;
}