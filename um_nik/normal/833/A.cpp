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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}

bool isCube(ll x) {
	ll l = 1, r = (ll)1e6 + 3;
	while(r - l > 1) {
		ll m = (l + r) / 2;
		if (m * m * m <= x)
			l = m;
		else
			r = m;
	}
	return l * l * l == x;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		int x, y;
		scanf("%d%d", &x, &y);
		ll z = (ll)x * y;
		if (!isCube(z)) {
			printf("No\n");
			continue;
		}
		int g = gcd(x, y);
		x /= g;
		y /= g;
		if (g % x == 0 && g % y == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}