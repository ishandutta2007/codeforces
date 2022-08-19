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

	void scan() {
		scanf("%lld%lld", &x, &y);
	}

	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	ll operator % (const Point &a) const {
		return x * a.x + y * a.y;
	}
	ll operator * (const Point &a) const {
		return x * a.y - y * a.x;
	}
	bool operator < (const Point &a) const {
		return *this * a > 0;
	}
};

ll getC(ll n, ll k) {
	if (k < 0 || k > n) return 0;
	ll res = 1;
	for (int i = 0; i < k; i++) {
		res *= n - i;
		res /= i + 1;
	}
	return res;
}

ll A3 = 0, S = 0;

const int N = 303;
int fenv[N];

void addFenv(int p, int x) {
	for(; p < N; p |= p + 1)
		fenv[p] += x;
}
int getFenv(int r) {
	int res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		res += fenv[r];
	return res;
}

Point a[N];
pair<Point, int> b[N], c[N];
int id[N];
int n;

void solve(Point P, Point Q) {
	int m = 0;
	for (int i = 0; i < n; i++) {
		if ((Q - P) * (a[i] - P) <= 0) continue;
		b[m] = mp(a[i] - P, i);
		c[m] = mp(a[i] - Q, i);
		m++;
	}
	S += getC(m, 3);
	sort(b, b + m);
	sort(c, c + m);
	for (int i = 0; i < m; i++)
		id[c[i].second] = i;
	for (int i = 0; i < N; i++)
		fenv[i] = 0;
	for (int i = 0; i < m; i++) {
		int cur = i - getFenv(id[b[i].second]);
		A3 += getC(cur, 2);
		addFenv(id[b[i].second], 1);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		a[i].scan();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				solve(a[i], a[j]);

	A3 /= 3;
//	eprintf("A3 = %lld, S = %lld\n", A3, S);

	S -= 3 * A3 + 4 * (getC(n, 5) - A3);
	printf("%lld\n", S);

	return 0;
}