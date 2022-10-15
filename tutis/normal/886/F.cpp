/*input
9
-1000000 -500000
-750000 250000
-500000 1000000
-250000 -250000
0 -1000000
250000 750000
500000 0
750000 -750000
1000000 500000
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
struct point
{
	ll x, y;
	point(): x(0), y(0)
	{
		;
	}
	point(ll x, ll y): x(x), y(y)
	{
		;
	}
	bool operator<(const point &o)const
	{
		if (x != o.x)
			return x < o.x;
		return y < o.y;
	}
	bool operator==(const point &o)const
	{
		return x == o.x && y == o.y;
	}
	void kryptis()
	{
		ll g = __gcd(abs(x), abs(y));
		x /= g;
		y /= g;
		if (y < 0 || (y == 0 && x < 0))
		{
			x *= -1;
			y *= -1;
		}
	}
};
point operator-(point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}
point operator-(point a)
{
	return point(-a.x, -a.y);
}
point operator+(point a, point b)
{
	return point(a.x + b.x, a.y + b.y);
}
point operator*(point a, ll k)
{
	return point(a.x * k, a.y * k);
}
ll cross(point a, point b)
{
	return a.y * b.x - a.x * b.y;
}
bool symm(vector<ll>&x)
{
	sort(x.begin(), x.end());
	for (ll i = 0; i <= x.size() - i - 1; i++)
		if (x[i] != -x[x.size() - i - 1])
			return false;
	return true;
}
struct custom
{
	size_t operator()(const point &x)const
	{
		return x.x + x.y * 3785412;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	point A[n];
	point M;
	for (ll i = 0; i < n; i++)
	{
		cin >> A[i].x >> A[i].y;
		M = M + A[i];
		A[i] = A[i] * n;
	}
	for (ll i = 0; i < n; i++)
		A[i] = A[i] - M;
	ll G = 0;
	for (ll i = 0; i < n; i++)
	{
		if (A[i].x != 0)
			G = __gcd(A[i].x, G);
		if (A[i].y != 0)
			G = __gcd(A[i].y, G);
	}
	if (G != 0)
		for (ll i = 0; i < n; i++)
		{
			A[i].x /= G;
			A[i].y /= G;
		}
	set<point>AA;
	for (ll i = 0; i < n; i++)
		AA.insert(A[i]);
	bool minus = true;
	vector<bool>blogi(n, false);
	for (ll i = 0; i < n; i++)
	{
		if (AA.count(-A[i]) == false)
			minus = false;
		else
			blogi[i] = true;
	}
	if (minus)
	{
		cout << "-1\n";
		return 0;
	}
	ll ans = 0;
	cc_hash_table<point, vector<int>, custom>C;
	ll nul = -1;
	ll sz = n;
	for (ll i = 0; i < n; i++)
	{
		if (A[i].x == 0 && A[i].y == 0)
		{
			nul = i;
			continue;
		}
		if (blogi[i])
		{
			sz--;
			continue;
		}
		for (ll j = 0; j < i; j++)
		{
			if (blogi[j])
				continue;
			point v = A[i] + A[j];
			if (v.x == 0 && v.y == 0)
				continue;
			v.kryptis();
			C[v].push_back(i);
			C[v].push_back(j);
		}
		point v = A[i];
		v.kryptis();
		C[v].push_back(i);
	}
	for (auto vs : C)
	{
		point V = vs.first;
		vector<int>&a = vs.second;
		if (nul != -1)
			a.push_back(nul);
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		if ((ll)a.size() < sz)
			continue;
		vector<ll>xy;
		for (int i : a)
			xy.push_back(cross(V, A[i]));
		if (symm(xy))
		{
			ans++;
		}
	}
	cout << ans << "\n";
}