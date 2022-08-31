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

struct Point {
	ll x, y;

	Point() : x(), y() {}
	Point (ll _x, ll _y) : x(_x), y(_y) {}

	void scan() {
		scanf("%lld%lld", &x, &y);
	}

	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	ll operator * (const Point &a) const {
		return x * a.y - y * a.x;
	}
};

const int N = 100100;
int n;
Point a[N];
Point b[N];
int m;

bool solve(Point P, Point p) {
	m = 0;
	for (int i = 0; i < n; i++) {
		if ((a[i] - P) * p != 0)
			b[m++] = a[i];
	}
	if (m <= 2) return true;
	P = b[0];
	p = b[1] - b[0];
	for (int i = 0; i < m; i++) {
		if ((b[i] - P) * p != 0)
			return false;
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		a[i].scan();
	if (n <= 4) {
		printf("YES\n");
		return 0;
	}
	if (solve(a[0], a[1] - a[0]) || solve(a[0], a[2] - a[0]) || solve(a[1], a[2] - a[1]))
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}