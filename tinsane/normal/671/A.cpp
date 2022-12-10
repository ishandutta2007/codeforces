#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
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
#include <unordered_map>
#include <unordered_set>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

double my_sqrt(double x)
{
	if (x < 0 && x > -eps)
		return 0;
	return sqrt(x);
}

struct Point
{
	double x, y;
	Point() : x(), y() {}
	Point(double x, double y) : x(x), y(y) {}
	void read()
	{
		scanf("%lf%lf", &x, &y);
	}
	double operator% (const Point& P) const
	{
		return x * P.x + y * P.y;
	}
	Point operator- (const Point& P) const
	{
		return Point(x - P.x, y - P.y);
	}
	double len() const
	{
		return my_sqrt(*this % *this);
	}
	double dist_to(const Point& P) const
	{
		return (*this - P).len();
	}
};

const int N = 1e5 + 10;
Point A, B, C;
Point bottles[N];
int n;
int a1 = -1, b1 = -1;

void solve()
{
	A.read();
	B.read();
	C.read();
	A = A - C;
	B = B - C;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		bottles[i].read();
		bottles[i] = bottles[i] - C;
	}
	if (n == 1)
	{
		printf("%lf", min(A.dist_to(bottles[0]), B.dist_to(bottles[0])) + bottles[0].len());
		return;
	}
	double s = 0;
	double tans = LINF;
	double ans = LINF;
	for (int i = 0; i < n; ++i)
		s += bottles[i].len() * 2;
	for (int i = 0; i < n; ++i)
	{
		double d = s - bottles[i].len() + bottles[i].dist_to(A);
		if (d < tans)
		{
			tans = d;
			a1 = i;
		}
	}
	ans = min(ans, tans);
	tans = LINF;
	for (int i = 0; i < n; ++i)
	{
		double d = s - bottles[i].len() + bottles[i].dist_to(B);
		if (d < tans)
		{
			tans = d;
			b1 = i;
		}
	}
	ans = min(ans, tans);
	tans = LINF;

	if (a1 != -1)
	{
		double tmp = s - bottles[a1].len() + bottles[a1].dist_to(A);
		tans = tmp;
		for (int i = 0; i < n; ++i)
			if (i != a1)
				tans = min(tans, tmp - bottles[i].len() + bottles[i].dist_to(B));
		ans = min(ans, tans);
	}
	if (b1 != -1)
	{
		double tmp = s - bottles[b1].len() + bottles[b1].dist_to(B);
		tans = tmp;
		for (int i = 0; i < n; ++i)
			if (i != b1)
				tans = min(tans, tmp - bottles[i].len() + bottles[i].dist_to(A));
		ans = min(ans, tans);
	}

	printf("%.9lf", ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("chocolate.in", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}