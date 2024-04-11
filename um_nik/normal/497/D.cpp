#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;

struct Point
{
	int x, y;

	Point () : x(), y() {}
	Point (int _x, int _y) : x(_x), y(_y) {}

	void scan()
	{
		scanf("%d%d", &x, &y);
	}

	void print()
	{
		printf("%d %d\n", x, y);
	}

	Point operator + (Point a)
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator - (Point a)
	{
		return Point(x - a.x, y - a.y);
	}

	ll operator % (Point a)
	{
		return x * a.x + y * a.y;
	}
	ll operator * (Point a)
	{
		return x * a.y - y * a.x;
	}
	ll sqLen()
	{
		return *this % *this;
	}

	Point rotate()
	{
		return Point(-y, x);
	}
};

int n, m;
Point P, Q;
Point PQ;
const int N = 1010;
Point A[N], B[N];
bool ans = false;
ll R;

ll sqr(ll x)
{
	return x * x;
}
int sgn(ll x)
{
	if (x == 0) return 0;
	if (x < 0) return -1;
	if (x > 0) return 1;
	throw;
}

double getMinD(Point O, Point C, Point D)
{
	ll minD = min( (O - C).sqLen(), (O - D).sqLen() );
	Point OC = C - O;
	Point OD = D - O;
	Point OH = (D - C).rotate();
	if ( sgn( OH * OC ) * sgn( OH * OD ) != -1 )
		return (double)minD;
	return (double)sqr( OC * OD ) / (double)(D - C).sqLen();
}

bool getIntersect(Point O, Point C, Point D)
{
	ll maxD = max( (O - C).sqLen(), (O - D).sqLen() );
	double minD = getMinD(O, C, D);
	return (minD <= (double)R && R <= maxD);
}

int main()
{
	P.scan();
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		A[i].scan();
	Q.scan();
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		B[i].scan();
	PQ = Q - P;
	R = PQ.sqLen();

	for (int i = 0; i < n; i++)
	{
		Point O = A[i] + PQ;
		for (int j = 0; j < m; j++)
		{
			ans |= getIntersect(O, B[j], B[(j + 1) % m]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		Point O = B[i] - PQ;
		for (int j = 0; j < n; j++)
		{
			ans |= getIntersect(O, A[j], A[(j + 1) % n]);
		}
	}
	if (ans)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}