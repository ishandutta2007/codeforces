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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


const double eps = 1e-7;
bool eq(double x, double y) {
	return abs(x - y) < eps;
}
bool ls(double x, double y) {
	return x < y && !eq(x, y);
}
bool lseq(double x, double y) {
	return x < y || eq(x, y);
}

double sqr(double x) {
	return x * x;
}

struct Point {
	double x, y;

	Point() : x(), y() {}
	Point (double _x, double _y) : x(_x), y(_y) {}

	void scan() {
		scanf("%lf%lf", &x, &y);
	}
	void print() {
		printf("%.12lf %.12lf\n", x, y);
	}

	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	Point operator * (const double &k) const {
		return Point(x * k, y * k);
	}
	Point operator / (const double &k) const {
		return Point(x / k, y / k);
	}
	double operator % (const Point &a) const {
		return x * a.x + y * a.y;
	}
	double operator * (const Point &a) const {
		return x * a.y - y * a.x;
	}
	double sqrLen() const {
		return *this % *this;
	}
	double len() const {
		return sqrt(sqrLen());
	}
	Point norm() const {
		return *this / len();
	}
	Point ort() const {
		return Point(-y, x);
	}
};

double getAngle(Point v, Point u) {
	return atan2(v * u, v % u);
}

bool onLine(Point A, Point B, Point C) {
	return eq((A - B) * (A - C), 0);
}
bool onSegm(Point A, Point B, Point C) {
	if (!onLine(A, B, C)) return false;
	return lseq((A - B) % (C - B), 0);
}

bool intersectLines(Point A, Point a, Point B, Point b, Point &I) {
	if (eq(a * b, 0)) return false;
	double y = ((A - B) * a) / (b * a);
	I = B + b * y;
	return true;
}

Point getH(Point P, Point A, Point a) {
	return A + a * (((P - A) % a) / a.sqrLen());
}
bool intersectLineCircle(Point A, Point a, Point O, double R, Point &I1, Point &I2) {
	Point H = getH(O, A, a);
	double x = (O - H).len();
	if (ls(R, x)) return false;
	if (eq(R, x)) {
		I1 = I2 = H;
		return true;
	}
	a = a.norm();
	x = sqrt(sqr(R) - sqr(x));
	I1 = H + a * x;
	I2 = H - a * x;
	return true;
}

bool intersectCircles(Point O1, double R1, Point O2, double R2, Point &I1, Point &I2) {
	if (R1 < R2) {
		swap(O1, O2);
		swap(R1, R2);
	}
	double L = (O1 - O2).len();
	if (ls(R1 + R2, L) || ls(L, R1 - R2) || eq(L, 0)) return false;
	if (eq(R1 + R2, L) || eq(L, R1 - R2)) {
		I1 = I2 = O1 + (O2 - O1).norm() * R1;
		return true;
	}
	double x = (sqr(R1) - sqr(R2) + sqr(L)) / (2 * L);
	Point a = (O2 - O1).norm();
	Point H = O1 + a * x;
	a = a.ort();
	x = sqrt(sqr(R1) - sqr(x));
	I1 = H + a * x;
	I2 = H - a * x;
	return true;
}

bool isInside(Point P, Point O, double R) {
	return lseq((P - O).sqrLen(), sqr(R));
}

vector<vector<Point>> a;
vector<double> sz;

bool insidePoly(Point P, vector<Point> w) {
	int m = (int)w.size() - 1;
	for (int i = 0; i < m; i++)
		if (onSegm(w[i], P, w[i + 1]))
			return true;
	double ang = 0;
	for (int i = 0; i < m; i++)
		ang += getAngle(w[i] - P, w[i + 1] - P);
	return abs(ang) > 1;
}

bool checkPoly(vector<Point> w, Point O, double R) {
	if (insidePoly(O, w)) return true;
	int m = (int)w.size() - 1;
	for (int i = 0; i < m; i++) {
		if (isInside(w[i], O, R)) return true;
		Point H = getH(O, w[i], w[i + 1] - w[i]);
		if (isInside(H, O, R) && onSegm(w[i], H, w[i + 1])) return true;
	}
	return false;
}

vector<Point> readPoly() {
	int n;
	scanf("%d", &n);
	vector<Point> a(n + 1);
	for (int i = 0; i < n; i++)
		a[i].scan();
	a[n] = a[0];
	return a;
}

double sizePoly(vector<Point> w) {
	double S = 0;
	int m = (int)w.size() - 1;
	for (int i = 0; i < m; i++)
		S += w[i] * w[i + 1];
	return abs(S) / 2;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	double R;
	int n, w;
	scanf("%lf%lf%d", &R, &R, &n);
	a.resize(n);
	sz.resize(n);
	for (int i = 0; i < n; i++) {
		a[i] = readPoly();
		sz[i] = sizePoly(a[i]);
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		Point O;
		O.scan();
		scanf("%lf", &R);
		vector<int> res;
		double S = 0;
		for (int i = 0; i < n; i++) {
			if (checkPoly(a[i], O, R)) {
				res.push_back(i);
				S += sz[i];
			}
		}
		printf("%.12lf %d", S, (int)res.size());
		for (int x : res)
			printf(" %d", x);
		printf("\n");
	}

	return 0;
}