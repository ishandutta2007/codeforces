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

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

struct Point {
	int x, y;

	Point() : x(), y() {}
	Point (int _x, int _y) {
		x = _x;
		y = _y;
		if (x < 0 || (x == 0 && y < 0)) {
			x *= -1;
			y *= -1;
		}
		int g = gcd(abs(x), abs(y));
		x /= g;
		y /= g;
	}

	bool operator < (const Point &p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
};

map<Point, ll> mapchik;
map<ll, set<pii>> A;

void tryAdd(int x, int y, ll dd) {
	mapchik[Point(x, y)] += dd;
	ll r = (ll)x * x + (ll)y * y;
	for (pii t : A[r]) {
		int xx = -x - t.first, yy = -y - t.second;
		Point p = Point(xx, yy);
		mapchik[p] += 2 * dd;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int q;
	scanf("%d", &q);
	int tot = 0;
	while(q--) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1) {
			tot++;
			tryAdd(x, y, 1);
			ll r = (ll)x * x + (ll)y * y;
			A[r].insert(mp(x, y));
		} else if (t == 2) {
			tot--;
			ll r = (ll)x * x + (ll)y * y;
			A[r].erase(mp(x, y));
			tryAdd(x, y, -1);
			
		} else {
			Point p = Point(x, y);
			printf("%lld\n", tot - mapchik[p]);
		}
	}

	return 0;
}