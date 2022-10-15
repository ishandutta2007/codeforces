/**
4
-10 -10
-10 10
10 10
10 -10
3
-10 0
1 5
2 2
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct taskas
{
	ll x, y;
	taskas() {}
	taskas(ll x, ll y): x(x), y(y) {}
	void get()
	{
		cin >> x >> y;
	}
	bool operator<(taskas a)
	{
		return x * a.y > a.x * y;
	}
	bool operator>(taskas a)
	{
		return x * a.y < a.x * y;
	}
	ld angle()
	{
		return atan2(y, x);
	}
};
taskas operator-(taskas a, taskas b)
{
	return taskas(a.x - b.x, a.y - b.y);
}
taskas operator^(taskas a, taskas b)
{
	return b - a;
}
taskas operator*(taskas a, taskas b)
{
	return taskas(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
ll crossP(taskas a, taskas b)
{
	return a.x * b.y - b.x * a.y;
}
ll area(taskas A, taskas B, taskas C)
{
	return abs
	       (
	           (A.x + B.x) * (A.y - B.y) +
	           (B.x + C.x) * (B.y - C.y) +
	           (C.x + A.x) * (C.y - A.y)
	       );
}
struct convex
{
	vector<taskas> V;
	convex(ll n): V(n) {}
	void fix()
	{	//V[0] turi tureti minimalu y.
		ll y = 10000000000ll;
		ll k = 0;
		vector<taskas> S = V;
		for (ll i = 0; i < V.size(); i++)
		{
			S[i] = V[i];
			if (y > V[i].y)
			{
				y = V[i].y;
				k = i;
			}
		}
		for (ll i = 0; i < V.size(); i++)
			V[i] = S[(i + k) % V.size()];
	}
	void get()
	{
		for (ll i = 0; i < V.size(); i++)
			V[i].get();
		fix();
	}
#define eps 1e-10
	bool inside(taskas a, ll i, ll j)
	{	//j>i
		if ((V[0]^a).y < 0)
			return false;
		if ((V[0]^a) < (V[0]^V[j]))
			return false;
		if ((V[0]^a) > (V[0]^V[i]))
			return false;
		if (abs(i - j) <= 1)
		{
			if (area(a, V[i], V[j]) == 0)
				return false;
			return area(V[0], V[i], a) +
			       area(V[0], V[j], a) +
			       area(V[i], V[j], a) ==
			       area(V[0], V[i], V[j]);
		}
		else
		{
			if (area(V[0], a, V[1]) == 0 || area(V[0], a, V[V.size() - 1]) == 0)
				return false;
			ll k = (i + j) / 2;
			if (inside(a, i, k) || inside(a, k, j))
				return true;
		}
		return false;
	}
	bool inside(taskas a)
	{
		return inside(a, 1, V.size() - 1);
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	convex A(n);
	A.get();
	ll m;
	cin >> m;
	while (m--)
	{
		taskas a;
		a.get();
		if (!A.inside(a))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}