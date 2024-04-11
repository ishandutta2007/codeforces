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

struct Point {
	ll x, y;

	Point() : x(), y() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}

	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	ll operator * (const Point &a) const {
		return x * a.y - y * a.x;
	}

	double len() const {
		return sqrtl((ld)x * x + (ld)y * y);
	}

	bool operator < (const Point &a) const {
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
};

const int N = 100100;
int n;
Point a[N];
Point h[N];
int m;

bool cmp(const Point &v, const Point &u) {
	ll x = v * u;
	if (x != 0) return x > 0;
	return v.len() < u.len();
}

void graham() {
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++) {
		while(m > 1 && (a[i] - h[m - 1]) * (a[i] - h[m - 2]) >= 0) m--;
		h[m++] = a[i];
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		a[i] = Point(x, y - x * x);
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--)
		a[i] = a[i] - a[0];
	graham();
	h[m] = h[0];

	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (h[i + 1].x < h[i].x)
			ans++;
	}
	printf("%d\n", ans);

	return 0;
}