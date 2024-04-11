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


int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	ll k;
	ll cur;
	scanf("%d%lld%lld", &n, &k, &cur);
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		ll y = cur % k;
		if (y > 0) y = k - y;
		y = min(y, x);
		cur += y;
		ans += (cur + k - 1) / k;
		cur = x - y;
	}
	ans += (cur + k - 1) / k;
	printf("%lld\n", ans);

	return 0;
}