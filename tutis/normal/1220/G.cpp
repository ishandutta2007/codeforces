/*input
4
0 0
0 1
1 0
1 1
2
0 1 1 2
2 5 5 8
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
mt19937 rng(181415);
struct point
{
	ld x, y;
	point(ld x, ld y): x(x), y(y)
	{

	}
};
point operator-(point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}
point operator+(point a, point b)
{
	return point(a.x + b.x, a.y + b.y);
}
point operator*(point a, point b)
{
	return point(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
ld dist2(point a, point b)
{
	ld x = a.x - b.x;
	ld y = a.y - b.y;
	return (x * x + y * y);
}
struct circle
{
	point o;
	ld r2;
	circle(ld x, ld y, ld r2): o(x, y), r2(r2)
	{

	}
};
vector<point>xx(circle A, circle B)
{
	ld d2 = dist2(A.o, B.o);
	if (d2 < 1e-7)
	{
		return {};
	}
	ld d = sqrtl(abs(d2));
	ld ra = sqrtl(A.r2);
	ld rb = sqrtl(B.r2);
	if (d > ra + rb + 0.01 || d < abs(ra - rb) - 0.01)
		return {};
	ld R2 = A.r2;
	ld r2 = B.r2;
	ld x = (d2 - r2 + R2) / (2 * d);
	ld y = sqrtl(abs(R2 - x * x));
	point v = B.o - A.o;
	return{{A.o + v * point(x / d, y / d)}, {A.o + v * point(x / d, -y / d)}};
}
const ll p1 = 10000019;
const ll p2 = 14000033;
const ll p3 = 1000000007;
ll M1[p1];
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll x_[n], y_[n];
	for (ll i = 0; i < n; i++)
		cin >> x_[i] >> y_[i];
	for (ll i = 0; i < 4 * n; i++)
	{
		ll a = rng() % n;
		ll b = rng() % n;
		swap(x_[a], x_[b]);
		swap(y_[a], y_[b]);
	}
	ll Sx = 0;
	ll Sy = 0;
	for (ll i = 0; i < n; i++)
	{
		Sx += x_[i];
		Sy += y_[i];
	}
	ld xs = ld(Sx) / ld(n);
	ld ys = ld(Sy) / ld(n);
	Sx %= p3;
	Sy %= p3;
	ll m;
	cin >> m;
	while (m--)
	{
		ll Sd = 0;
		ll d[n];
		for (ll i = 0; i < n; i++)
			cin >> d[i];
		shuffle(d, d + n, rng);
		for (ll i = 0; i < n; i++)
		{
			M1[d[i] % p1]++;
			Sd += d[i];
			Sd -= x_[i] * x_[i];
			Sd -= y_[i] * y_[i];
			Sd %= p3;
		}
		set<pair<ll, ll>>ans;
		auto check = [&](ll x, ll y)->void
		{
			ll c = n * ((x * x + y * y) % p3) - 2 * x * Sx - 2 * y * Sy - Sd;
			c %= p3;
			if (c != 0)
				return;
			if (ans.count({x, y}))
			{
				return;
			}
			ll l = 0;
			ll mx = min(n, 7ll);
			for (ll i = 0; i < mx; i++)
			{
				ll D = (x - x_[i]) * (x - x_[i]) + (y - y_[i]) * (y - y_[i]);
				if (M1[D % p1] >= 1)
				{
					l = i + 1;
					M1[D % p1]--;
				}
				else
					break;
			}
			if (l == mx)
			{
				ans.insert({x, y});
			}
			for (ll i = 0; i < l; i++)
			{
				ll D = (x - x_[i]) * (x - x_[i]) + (y - y_[i]) * (y - y_[i]);
				M1[D % p1]++;
			}
		};
		ld r2 = 0;
		ll s9 = 0;
		ll s0 = 0;
		for (ll i = 0; i < n; i++)
		{
			ll c = d[i] % 1000000000;
			ll x = (d[i] - c) / 1000000000;
			s9 += x;
			s0 += c;
		}
		for (ll i = 0; i < n; i++)
		{
			r2 -= ld(x_[i] - xs) * ld(x_[i] - xs) +
			      ld(y_[i] - ys) * ld(y_[i] - ys);
		}
		r2 += ld(s9) * ld(1000000000) + ld(s0);
		r2 /= ld(n);
		circle A(xs, ys, r2);
		ll dm = d[0];
		for (ll i = 0; i < n; i++)
		{
			circle B(x_[i], y_[i], dm);
			for (point i : xx(A, B))
			{
				ll x = round(i.x);
				ll y = round(i.y);
				for (ll dx = -4; dx <= 4; dx++)
					for (ll dy = -4; dy <= 4; dy++)
						check(x + dx, y + dy);
			}
		}
		cout << ans.size() << " ";
		for (auto i : ans)
			cout << i.first << " " << i.second << " ";
		cout << "\n";
		for (ll i = 0; i < n; i++)
		{
			M1[d[i] % p1] = 0;
		}
	}
}