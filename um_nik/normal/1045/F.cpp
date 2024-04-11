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

struct Point {
	ll x, y;

	Point() : x(), y() {}
	Point (ll _x, ll _y) : x(_x), y(_y) {}

	void scan() {
		scanf("%lld%lld", &x, &y);
	}
	void print() {
		eprintf("(%lld %lld)\n", x, y);
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
	ll sqrLen() const {
		return *this % *this;
	}

	bool operator < (const Point &a) const {
		ll z = *this * a;
		if (z != 0) return z > 0;
		return sqrLen() < a.sqrLen();
	}
};

const int N = 200200;
int n;
Point a[N];
Point b[N];
Point c[N];
int h[N];
int H[N];
int m;

void buildGlobal(int BAD) {
	m = 0;
	for (int i = 0; i < n; i++) {
		if (i == BAD) continue;
		while(m > 1 && (a[i] - b[m - 1]) * (a[i] - b[m - 2]) >= 0) m--;
		b[m] = a[i];
		H[m] = i;
		m++;
	}
/*
	for (int i = 0; i < m; i++)
		b[i].print();
*/
}

void buildLocal(int &sz, int L, int R, int BAD, Point P, Point Q) {
	for (int i = L; i < R; i++) {
		if (i == BAD) continue;
		while(sz > 2 && (a[i] - b[sz - 1]) * (a[i] - b[sz - 2]) >= 0) sz--;
		b[sz++] = a[i];
	}
	Point d[2];
	d[0] = P;
	d[1] = Q;
	for (int i = 0; i < 2; i++) {
		while(sz > 2 && (d[i] - b[sz - 1]) * (d[i] - b[sz - 2]) >= 0) sz--;
		b[sz++] = d[i];
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		a[i].scan();
	}

	sort(a, a + n);
	if (a[0].x != 0 || a[0].y != 0) {
		for (int i = n; i > 0; i--)
			a[i] = a[i - 1];
		a[0] = Point(0, 0);
		n++;
	}
/*
	for (int i = 0; i < n; i++)
		a[i].print();
	eprintf("-----------\n");
*/
	buildGlobal(-1);
	for (int i = 0; i < m; i++) {
		if ((b[i].x & 1) || (b[i].y & 1)) {
			printf("Ani\n");
			return 0;
		}
		c[i] = b[i];
	}
	vector<int> bad;
	if (m < 6) {
		for (int i = 1; i < m; i++)
			bad.push_back(H[i]);
	} else {
		bad.push_back(H[1]);
		bad.push_back(H[2]);
		bad.push_back(H[m - 2]);
		bad.push_back(H[m - 1]);
	}
/*
	for (int i = 0; i < m; i++)
		b[i].print();
*/
	for (int i = 3; i < m - 2; i++) {
		b[0] = c[i - 2];
		b[1] = c[i - 1];
		int sz = 2;
		buildLocal(sz, H[i - 1] + 1, H[i + 1], H[i], c[i + 1], c[i + 2]);
		for (int j = 0; j < sz; j++)
			if ((b[j].x & 1) || (b[j].y & 1)) {
				printf("Ani\n");
				return 0;
			}
	}
	for (int id : bad) {
		buildGlobal(id);
		for (int i = 0; i < m; i++)
			if ((b[i].x & 1) || (b[i].y & 1)) {
				printf("Ani\n");
				return 0;
			}
	}
	printf("Borna\n");

	return 0;
}