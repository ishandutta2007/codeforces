#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#pragma comment(linker, "/STACK:167772160")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#ifdef LOCAL
#define eprint() debugOutput()
#else
#define eprint() ;
#endif

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const double pi = 2 * atan2(1, 0);
const ld PI = 2 * atan2l(1, 0);
const double eps = 1e-8;
const ld EPS = 1e-12;
void debugOutput();

bool deq(ld a, ld b)
{
	return abs(a - b) < eps;
}

bool dls(ld a, ld b)
{
	return a < b && !deq(a, b);
}

bool dls_eq(ld a, ld b)
{
	return a < b || deq(a, b);
}

ld my_sqrt(ld x)
{
	if (x < 0 && deq(x, 0))
		return 0;
	return sqrtl(x);
}

struct Point
{
	ld x, y;
	Point() : x(), y() {}
	Point(ld _x, ld _y) : x(_x), y(_y) {}
	void read()
	{
		cin >> x >> y;
	}
	void print() const
	{
		cout << x << ' ' << y << '\n';
	}
	bool operator== (Point P) const
	{
		return deq(x, P.x) && deq(y, P.y);
	}
	Point operator- (const Point& P) const
	{
		return Point(x - P.x, y - P.y);
	}
	Point operator+ (const Point& P) const
	{
		return Point(x + P.x, y + P.y);
	}
	Point operator* (ld k) const
	{
		return Point(x * k, y * k);
	}
	Point operator/ (ld k) const
	{
		return Point(x / k, y / k);
	}
	ld operator* (const Point& P) const
	{
		return x * P.y - y * P.x;
	}
	ld operator% (const Point& P) const
	{
		return x * P.x + y * P.y;
	}
	ld operator^ (const Point& P) const
	{
		return atan2l(*this * P, *this % P);
	}
	Point ort() const
	{
		return Point(-y, x);
	}
	Point norm() const
	{
		return *this / len();
	}
	ld len2() const
	{
		return x * x + y * y;
	}
	ld len() const
	{
		return my_sqrt(len2());
	}
	ld dist_to(const Point& P) const
	{
		return (*this - P).len();
	}
};

int get_intersection(
	const Point & O1, double r1,
	const Point & O2, double r2,
	Point & A, Point & B)
{
	double d = O1.dist_to(O2);
	if (dls(r1 + r2, d) || dls(d, fabs(r1 - r2)))
		return 0;
	double a = (r1 * r1 - r2 * r2 + d * d) / 2 / d;
	double h = my_sqrt(r1 * r1 - a * a);
	Point v = O2 - O1;
	Point u = v.ort();
	v = v.norm() * a;
	u = u.norm() * h;
	Point H = O1 + v;
	A = H + u;
	B = H - u;
	if (u == Point())
		return 1;
	return 2;
}

Point O1, O2;
ld r1, r2, ans;

void solve()
{
	cout << setprecision(15) << fixed;
	O1.read();
	cin >> r1;
	O2.read();
	cin >> r2;
	if (r1 > r2)
	{
		swap(O1, O2);
		swap(r1, r2);
	}

	if (dls_eq(r1 + r2, O1.dist_to(O2)))
	{
		cout << 0;
		return;
	}
	else if (dls_eq(O1.dist_to(O2), r2 - r1))
	{
		cout << PI * r1 * r1;
		return;
	}

	Point A, B;
	get_intersection(O1, r1, O2, r2, A, B);
	ld alpha1 = abs((A - O1) ^ (B - O1)), 
		alpha2 = abs((A - O2) ^ (B - O2));
	ld s1 = (r1 * r1 * alpha1 - abs((A - O1) * (B - O1))) / 2;
	ld s2 = (r2 * r2 * alpha2 - abs((A - O2) * (B - O2))) / 2;
	if (deq(((A - O1) ^ (B - O1)) + ((B - O1) ^ (O2 - O1)) + ((O2 - O1) ^ (A - O1)), 0))
		ans = s1 + s2;
	else
		ans = PI * r1 * r1 - s1 + s2;

	cout << abs(ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("sequence.in", "r", stdin);
	//freopen("sequence.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}

void debugOutput()
{}