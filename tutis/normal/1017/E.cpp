/*input
16 3
2 0
3 0
4 0
5 1
6 2
6 3
6 4
5 5
4 6
3 6
2 6
1 5
0 4
0 3
0 2
1 1
2 2
2 0
0 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll N;
ll M;
struct point
{
	ll x, y;
	point() {}
	point(ll x, ll y): x(x), y(y) {}
	ll ilg()
	{
		return x * x + y * y;
	}
};
point operator-(point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}
ll cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
vector<point>convex(vector<point> x)
{
	sort(x.begin(), x.end(), [](point a, point b) {
		return make_pair(a.y, a.x) < make_pair(b.y, b.x);
	});
	vector<point>ret;
	ret.push_back(x[0]);
	x.erase(x.begin());
	sort(x.begin(), x.end(), [&](point a, point b) {
		if (cross(a - ret[0], b - ret[0]) == 0)
			return (a - ret[0]).ilg() > (b - ret[0]).ilg();
		return (cross(a - ret[0], b - ret[0]) > 0);
	});
	for (point a : x)
	{
		if (ret.size() >= 2 && cross(ret[0] - a, ret.back() - ret[0]) == 0)
			continue;
		while (ret.size() >= 2)
		{
			ll k = ret.size();
			if (cross(a - ret[k - 1], ret[k - 1] - ret[k - 2]) >= 0)
				ret.pop_back();
			else
				break;
		}
		ret.push_back(a);
	}
	return ret;
}

const ll modulo = 998244353;
ll mod(ll x, ll m = modulo)
{
	x %= m;
	x += m;
	x %= m;
	return x;
}
ll power(ll x, ll a)
{
	x = mod(x);
	a = mod(a, modulo - 1);
	ll ret = 1;
	ll k = 1;
	while (a)
	{
		if ((k & a) > 0)
		{
			a ^= k;
			ret = mod(ret * x);
		}
		k <<= 1;
		x = mod(x * x);
	}
	return ret;
}

bool same(vector<ll>x, vector<ll>y)
{
	if (x.size() + y.size() <= 3)
		return true;
	if (x.size() != y.size())
		return false;
	srand(clock());
	ll Hy = 0;
	const ll base = 1073 + rand() % 1516;
	ll n = x.size();
	ll w = 1;
	for (ll i = 0; i < n; i++)
	{
		y[i] = mod(y[i]);
		x[i] = mod(x[i]);
		Hy += (w * y[i]);
		w *= base;
		Hy %= modulo;
		w %= modulo;
	}
	ll Hx = 0;
	w = 1;
	for (ll i = 0; i < n; i++)
	{
		Hx += (w * x[i]);
		w *= base;
		Hx %= modulo;
		w %= modulo;
	}
	ll W = mod(1 - power(base, n));
	for (ll i = (n - 1); i >= 0; i--)
	{
		Hx *= base;
		Hx %= modulo;
		Hx += x[i] * W;
		Hx %= modulo;
		if (Hx == Hy)
		{
			return true;
		}
	}
	return false;
}
bool same(vector<point> a, vector<point> b)
{
	if (a.size() != b.size())
	{
		return false;
	}
	vector<ll>x;
	vector<ll>y;
	ll n = a.size();
	for (ll i = 0; i < n; i++)
	{
		x.push_back((a[i] - a[(i + 1) % n]).ilg());
		x.push_back(cross(a[i] - a[(i + 1) % n], a[(i + 1) % n] - a[(i + 2) % n]));
	}
	for (ll i = 0; i < n; i++)
	{
		y.push_back((b[i] - b[(i + 1) % n]).ilg());
		y.push_back(cross(b[i] - b[(i + 1) % n], b[(i + 1) % n] - b[(i + 2) % n]));
	}
	return same(x, y);
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, m;
	N = n;
	M = m;
	while (cin >> n >> m)
	{
		vector<point>x(n);
		vector<point>y(m);
		for (point &i : x)
			cin >> i.x >> i.y;
		for (point &i : y)
			cin >> i.x >> i.y;
		if (same(convex(x), convex(y)))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}