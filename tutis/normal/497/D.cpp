/*input
0 0
10
0 0
0 9
-17 9
-17 -16
16 -16
16 -15
-16 -15
-16 8
-1 8
-1 0

6 0
10
-3 1
-3 -8
14 -8
14 17
-19 17
-19 16
13 16
13 -7
-2 -7
-2 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct point
{
	ll x, y;
	void skaityk()
	{
		cin >> x >> y;
	}
	point()
	{

	}
	point(ll x, ll y): x(x), y(y)
	{

	}
	ll dist2()
	{
		return x * x + y * y;
	}
	ld dist()
	{
		return sqrtl(dist2());
	}
};
point operator+(point a, point b)
{
	return point(a.x + b.x, a.y + b.y);
}
point operator-(point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}
ll cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
point operator*(point a, point b)
{
	return point(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
ll sgn(ll x)
{
	if (x < 0)
		return -1;
	if (x > 0)
		return 1;
	return 0;
}
bool gal(point a, point b1, point b2, ll R)
{
	ll D1 = (a - b1).dist2();
	ll D2 = (a - b2).dist2();
	if (D1 == R || D2 == R)
		return true;
	if (D1 < R && D2 < R)
		return false;
	if (D1 > R && D2 < R)
		return true;
	if (D1 < R && D2 > R)
		return true;
	if (cross(b1 - a, b2 - a) == 0)
	{
		if ((b1 - b2).dist2() < (a - b2).dist2())
			return false;
		if ((b1 - b2).dist2() < (a - b1).dist2())
			return false;
		return true;
	}
	point c = a + (b1 - b2) * point(0, 1);
	if (sgn(cross(b2 - c, c - a)) != sgn(-cross(b1 - c, c - a)))
		return false;
	ll S = abs(cross(b1 - a, b2 - a));
	return S * S <= R * (b1 - b2).dist2();
}
bool kertasi(point a, point b, point c, point d)
{
	if (cross(a - b, c - a) == 0)
		return false;
	if (cross(a - b, d - a) == 0)
		return false;
	if (cross(c - d, a - d) == 0)
		return false;
	if (cross(c - d, b - d) == 0)
		return false;
	if ((cross(b - a, c - a) > 0) == (cross(b - a, d - a) > 0))
		return false;
	if ((cross(c - d, a - c) > 0) == (cross(c - d, b - c) > 0))
		return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	point P;
	P.skaityk();
	int n;
	cin >> n;
	point A[n];
	for (point &a : A)
		a.skaityk();
	point Q;
	Q.skaityk();
	int m;
	cin >> m;
	point B[m];
	for (point &b : B)
		b.skaityk();
	for (point &a : A)
		a = a - P + Q;
	ll R = (P - Q).dist2();
	bool daugiau = false;
	bool maziau = false;
	for (point a : A)
	{
		for (point b : B)
		{
			ll D = (a - b).dist2();
			if (D >= R)
				daugiau = true;
			if (D <= R)
				maziau = true;
		}
	}
	for (point a : A)
	{
		for (int i = 0; i < m; i++)
		{
			maziau |= gal(a, B[i], B[(i + 1) % m], R);
		}
	}
	for (point b : B)
	{
		for (int i = 0; i < n; i++)
		{
			maziau |= gal(b, A[i], A[(i + 1) % n], R);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			maziau |= kertasi(A[i], A[(i + 1) % n], B[j], B[(j + 1) % m]);
		}
	}
	if (daugiau && maziau)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
}