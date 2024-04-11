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



int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll t1, t2, m;
	scanf("%lld%lld%lld", &t1, &t2, &m);
	t2 = ((t1 + t2 - 1) / t2) * t2;
	t2 -= t1;
	m *= 2;
	ll p = 2 * t1 + t2;
	ll k = m / p;
	ll ans = k * (t1 + t2);
	m %= p;
	ans *= 2;
	if (m <= 2 * t1) {
		ans += m;
	} else {
		ans += 2 * t1;
		ans += (m - 2 * t1) * 2;
	}
	printf("%lld.%lld\n", ans / 2, (ans & 1) * 5);

	return 0;
}