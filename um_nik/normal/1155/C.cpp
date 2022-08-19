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

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

const ll INF = (ll)1e18 + 55;

int n, m;
ll x, y, z;
ll ans1 = INF;
int ans2;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	y = 0;
	scanf("%lld", &x);
	for (int i = 1; i < n; i++) {
		scanf("%lld", &z);
		y = gcd(y, abs(z - x));
	}
	x = (x - 1) % y + 1;
	ans2 = -1;
	for (int i = 0; i < m; i++) {
		scanf("%lld", &z);
		if (y % z) continue;
		z = (x - 1) % z + 1;
		if (z < ans1) {
			ans1 = z;
			ans2 = i + 1;
		}
	}
	if (ans2 == -1)
		printf("NO\n");
	else
		printf("YES\n%lld %d\n", ans1, ans2);

	return 0;
}