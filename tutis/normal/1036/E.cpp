/*input
9
0 0 4 4
-1 5 4 0
4 0 4 4
5 2 11 2
6 1 6 7
5 6 11 6
10 1 10 7
7 0 9 8
10 -1 11 -1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long double ld;
typedef long long ll;
const ll INF = 1000000000000000000;
struct point
{
	ll x, y;
	point(ll x = INF, ll y = INF): x(x), y(y)
	{

	}
	bool operator<(const point &o)const
	{
		if (x != o.x)
			return x < o.x;
		return y < o.y;
	}
	bool operator==(const point &o)const
	{
		return ((x == o.x) && (y == o.y));
	}
};
ostream& operator<<(ostream &out, const point &a)
{
	out << a.x << " " << a.y;
	return out;
}
point operator-(const point &a, const point &b)
{
	return point(a.x - b.x, a.y - b.y);
}
point operator+(const point &a, const point &b)
{
	return point(a.x + b.x, a.y + b.y);
}
ll operator*(const point &a, const point &b)
{
	return a.x * b.y - a.y * b.x;
}
ll dot(const point &a, const point &b)
{
	return a.x * b.x + a.y * b.y;
}
bool viduj(point a, point b, point c)
{
	if (b.x < min(a.x, c.x))
		return false;
	if (b.x > max(a.x, c.x))
		return false;
	if (b.y < min(a.y, c.y))
		return false;
	if (b.y > max(a.y, c.y))
		return false;
	return (b - a) * (b - c) == 0;
}
point x(point a, point b, point c, point d)
{
	point s;
	b = b - a;
	d = d - c;
	//a + bx = c + dy
	//(a + bx)d = (c + dy)d
	//ld x = (c * d - a * d) / (b * d);
	if (b * d == 0)
		return s;
	point t = a + point(b.x * ((c - a) * d) / (b * d),
	                    b.y * ((c - a) * d) / (b * d));
	if (viduj(a, t, a + b) && viduj(c, t, c + d))
		return t;
	return s;
}
struct ane
{
	size_t operator()(const point &x)const
	{
		return x.x ^ x.y + x.x;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll cnt = 0;
	vector<pair<point, point>>A;
	while (n--)
	{
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll dx = abs(x2 - x1);
		ll dy = abs(y2 - y1);
		cnt += __gcd(dx, dy) + 1;
		gp_hash_table<point, null_type, ane>S;
		S[point()];
		for (pair<point, point>i : A)
			S[x(i.first, i.second, point(x1, y1), point(x2, y2))];
		A.push_back({point(x1, y1), point(x2, y2)});
		cnt -= (ll)S.size() - 1;
	}
	cout << cnt << "\n";
}