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
	double x, y;

	Point() : x(), y() {}
	Point(double _x, double _y) : x(_x), y(_y) {}

	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	double len() const {
		return sqrt(x * x + y * y);
	}
};

const int N = 20;
double g[N][N];
int n;
Point p[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll a, b, c;
	ll x1, y1, x2, y2;
	scanf("%lld%lld%lld", &a, &b, &c);
	scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);

	ll ans = abs(x2 - x1) + abs(y2 - y1);

	if (a == 0 || b == 0) {
		printf("%lld\n", ans);
		return 0;
	}

	p[0] = Point(x1, y1);
	p[1] = Point(x2, y2);
	n = 2;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			g[i][j] = (i == j ? 0 : 1e20);

	p[2] = Point(x1, (double)(-c - a * x1) / b);
	p[3] = Point(x2, (double)(-c - a * x2) / b);
	p[4] = Point((double)(-c - b * y1) / a, y1);
	p[5] = Point((double)(-c - b * y2) / a, y2);

	n = 6;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = fabs(p[i].x - p[j].x) + fabs(p[i].y - p[j].y);
	for (int i = 2; i < n; i++)
		for (int j = 2; j < n; j++)
			g[i][j] = (p[i] - p[j]).len();

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

	printf("%.13lf\n", g[0][1]);

	return 0;
}