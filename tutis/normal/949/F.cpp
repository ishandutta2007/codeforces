/*input
3
4 2
6 2
2 1
2 6
4 4
6 6

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef long long ll;
rope<ll>virvute;
struct point
{
	ll x;
	ll y;
	point() {}
	point(ll x, ll y): x(x), y(y) {}
	bool operator==(const point &kitas)const
	{
		return (x == kitas.x && y == kitas.y);
	}
	bool operator<(const point &b)const
	{
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}
};
point operator+(const point &a, const point &b)
{
	return point(a.x + b.x, a.y + b.y);
}
point operator-(const point &a, const point &b)
{
	return point(a.x - b.x, a.y - b.y);
}
ll operator*(const point &a, const point &b)
{
	return ll(a.x) * ll(b.y) - ll(a.y) * ll(b.x);
}
point x(const point &a, point b, const point &c, point d)
{
	b = b - a;
	d = d - c;
	ll k = d * b;
	if (d * b == 0)
		return point(2e7, 2e7);
	ll k1 = (a - c) * b;
	d.x *= k1;
	if (d.x % k != 0)
		return point(2e7, 2e7);
	d.x /= k;
	d.y *= k1;
	if (d.y % k != 0)
		return point(2e7, 2e7);
	d.y /= k;
	return c + d;
}
const int didumas = 500007;
ll c1;
ll c2;
ll c3;
int h(int x, int y)
{
	if (x == 0 && y == 0)
		return 0;
	int g = __gcd(abs(x), abs(y));
	x /= g;
	y /= g;
	if (x < 0 || (x == 0 && y < 0))
	{
		x *= -1;
		y *= -1;
	}
	int s = (ll(x) + ll(y) * c1);
	s %= didumas;
	if (s < 0)
		s += didumas;
	return s;
}
const int didesnis = 300000000;
int h_(int x, int y)
{
	int s = (ll(x) + ll(y) * c2);
	s %= didesnis;
	if (s < 0)
		s += didesnis;
	return s;
}
int hd(int x, int y)
{
	if (x == 0 && y == 0)
		return 0;
	int g = __gcd(abs(x), abs(y));
	x /= g;
	y /= g;
	if (x < 0 || (x == 0 && y < 0))
	{
		x *= -1;
		y *= -1;
	}
	int s = (ll(x) + ll(y) * c3);
	s %= didesnis;
	if (s < 0)
		s += didesnis;
	return s;
}
bitset<didumas>kiti[5200];
int n;
point p[5200];
bitset<didesnis>buvo;
bitset<didesnis>v0;
bitset<didesnis>v1;
void check(point M)
{
	if (max(abs(M.x), abs(M.y)) > 1000000)
		return;
	if (buvo[h_(M.x, M.y)])
		return;
	buvo[h_(M.x, M.y)] = true;
	for (int i = 0; i < n; i++)
	{
		point v = p[i] - M;
		if (kiti[i][h(v.x, v.y)] == false)
			return;
	}
	for (int i = 0; i < n; i++)
	{
		point v = p[i] - M;
		int H = hd(v.x, v.y);
		if (v1[H])
		{
			for (int j = 0; j <= i; j++)
			{
				point v = p[j] - M;
				H = hd(v.x, v.y);
				v0[H] = v1[H] = false;
			}
			return;
		}
		else if (v0[H])
		{
			v1[H] = true;
		}
		else
		{
			v0[H] = true;
		}
	}
	cout << "Yes\n";
	cout << M.x << " " << M.y << "\n";
	exit(0);
}
int32_t main()
{
	clock_t pradzia = clock();
	srand(pradzia);
	c1 = 200504500 + rand();
	c2 = 2900004560 + rand();
	c3 = 207745000 + rand();
	ios_base::sync_with_stdio(false);
	cin >> n;
	n *= 2;
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	random_shuffle(p, p + n);
	for (int i = 0; i < n; i++)
	{
		buvo[h_(p[i].x, p[i].y)] = true;
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				point v = p[j] - p[i];
				kiti[i][h(v.x, v.y)] = true;
			}
		}
	}
	vector<int>bb(n - 2);
	iota(bb.begin(), bb.end(), 2);
	random_shuffle(bb.begin(), bb.end());
	for (int a = 2; a < n; a++)
	{
		for (int b = 2; b < n; b++)
		{
			check(x(p[0], p[a], p[1], p[b]));
		}
	}
	for (int a = 3; a < n; a++)
	{
		check(x(p[0], p[1], p[2], p[a]));
	}
	cout << "No\n";
	return 0;
}