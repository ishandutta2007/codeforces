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
typedef pair<double, double> pdd;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const double PI = 4 * atan(1);

const int IT = 80;
const int N = 400200;
int n;
pdd a[N];
pdd b[N];
pdd c[N];
int g[N];

/*
struct Event {
	
};
*/

int calcAns(int m, int s) {
	int res = 0;
	int v = s;
	while(v < s + m) {
		res++;
		v = g[v];
	}
	return res;
}
int solve(double d) {
	for (int i = 0; i < n; i++) {
		double ang = acos(d / a[i].second);
		b[i] = mp(a[i].first - ang, a[i].first + ang);
	}
//	for (int i = 0; i < n; i++)
//		eprintf("(%.5lf %.5lf)\n", b[i].first, b[i].second);
//	eprintf("--------\n");
	for (int i = 0; i < n; i++) {
		while(b[i].first < 0) {
			b[i].first += 2 * PI;
			b[i].second += 2 * PI;
		}
		b[n + i].first = b[i].first + 2 * PI;
		b[n + i].second = b[i].second + 2 * PI;
	}
	sort(b, b + 2 * n);
	double r = b[2 * n - 1].second;
	int m = 0;
	for (int i = 2 * n - 2; i >= 0; i--) {
		if (b[i].second < r) {
			r = b[i].second;
			if (b[i].first < 2 * PI)
				c[m++] = b[i];
		}
	}
	reverse(c, c + m);
//	for (int i = 0; i < m; i++)
//		eprintf("(%.5lf %.5lf)\n", c[i].first, c[i].second);
//	eprintf("---------\n");
	for (int i = 0; i < m; i++) {
		c[m + i].first = c[i].first + 2 * PI;
		c[m + i].second = c[i].second + 2 * PI;
	}
	int pos = 0;
	for (int i = 0; i < m; i++) {
		while(c[pos].first <= c[i].second) pos++;
		g[i] = pos;
	}
	for (int i = 0; i < 2 * m; i++)
		g[m + i] = g[i] + m;
	int T = 0;
	int v = 0;
	int L = 0, R = m;
	while(v < m) {
		int u = g[v];
		if (u - v < R - L) {
			L = v;
			R = u;
		}
		v = u;
		T++;
	}
	for (int i = L; i <= R; i++)
		T = min(T, calcAns(m, i));
	return T;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		a[i] = mp(atan2(y, x), sqrt(x * x + y * y));
	}
	sort(a, a + n);
	
//	solve(0.5);
//	return 0;
	
	double r = a[0].second;
	for (int i = 0; i < n; i++)
		r = min(r, a[i].second);
	double l = 0;
	for (int it = 0; it < IT; it++) {
		double x = (l + r) / 2;
		if (solve(x) <= m)
			l = x;
		else
			r = x;
	}
	printf("%.13lf\n", l);

	return 0;
}