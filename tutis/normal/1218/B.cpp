/*input
3
3 -6 3 -5 5 -3 6
3 -7 -2 -8 7 -6 7
4 1 4 -2 2 -5 1 -1 6
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct point
{
	ld x, y;
	bool zin = false;
	ld val = 0;
	point() {}
	point(ld x, ld y): x(x), y(y)
	{

	}
	ld kampas()
	{
		if (zin)
			return val;
		return atan2l(y, x);
	}
	void calc(ld v)
	{
		zin = true;
		val = v;
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
point operator*(point a, ld k)
{
	return point(a.x * k, a.y * k);
}
ld cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
ld f(ld alfa, ld beta, pair<point, point>ab)
{
	point a = ab.first;
	point b = ab.second;
	point va(cosl(alfa), sinl(alfa));
	point vb(cosl(beta), sinl(beta));
	va = va * (cross(a, b) / cross(va, b - a));
	vb = vb * (cross(a, b) / cross(vb, b - a));
	return cross(va, vb) / 2;
}
ld calc(ld alfa, ld beta, const vector<pair<point, point>>&A, pair<point, point>mn = {point(1e10, 1e10), point(1e10, 1e10)}, pair<point, point>mn1 = {point(1e10, 1e10), point(1e10, 1e10)})
{
	if (A.empty())
	{
		if (mn1.first.x < 1e9)
		{
			return f(alfa, beta, mn1) - f(alfa, beta, mn);
		}
		else
			return 0;
	}
	if (beta - alfa < 1e-8)
		return 0;
	vector<pair<point, point>>L, R;
	ld gamma = (alfa + beta) / 2;
	bool ok = true;
	point v(cos(gamma), sin(gamma));
	for (pair<point, point>i : A)
	{
		ld k1 = i.first.val;
		ld k2 = i.second.val;
		if (beta < k1 || k2 < alfa)
			continue;
		if (beta - alfa < PI)
			if (k1 < alfa && beta < k2)
			{
				ld k1 = cross(mn.first, mn.second) / cross(v, mn.second - mn.first);
				ld k2 = cross(mn1.first, mn1.second) / cross(v, mn1.second - mn1.first);
				ld d = cross(i.first, i.second) / cross(v, i.second - i.first);
				if (mn.first.x >= 1e9 || d <= k1)
				{
					mn1 = mn;
					mn = i;
				}
				else if (mn1.first.x >= 1e9 || d <= k2)
				{
					mn1 = i;
				}
				continue;
			}
		ok = false;
		if (k1 < gamma)
			L.push_back(i);
		if (k2 > gamma)
			R.push_back(i);
	}
	if (mn1.first.x < 1e9 && beta - alfa < PI)
	{
		bool ok1 = true;
		ld k2 = cross(mn1.first, mn1.second) / cross(v, mn1.second - mn1.first);
		for (pair<point, point>i : L)
		{
			ld d = cross(i.first, i.second) / cross(v, i.second - i.first);
			if (d <= k2)
			{
				ok1 = false;
				break;
			}
		}
		for (pair<point, point>i : R)
		{
			ld d = cross(i.first, i.second) / cross(v, i.second - i.first);
			if (d <= k2)
			{
				ok1 = false;
				break;
			}
		}
		if (ok1)
			return f(alfa, beta, mn1) - f(alfa, beta, mn);
	}
	if (ok)
		return f(alfa, beta, mn1) - f(alfa, beta, mn);
	return calc(alfa, gamma, L, mn, mn1) + calc(gamma, beta, R, mn, mn1);
}
int sgn(ld x)
{
	if (x < 0)
		return -1;
	if (x > 0)
		return 1;
	return 0;
}
int main()
{
	cout << fixed << setprecision(3);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<point, point>>A;
	while (n--)
	{
		int k;
		cin >> k;
		point a0;
		cin >> a0.x >> a0.y;
		point aj = a0;
		for (int i = 1; i < k; i++)
		{
			point ai;
			cin >> ai.x >> ai.y;
			A.push_back({aj, ai});
			aj = ai;
		}
		A.push_back({aj, a0});
	}
	n = A.size();
	for (int i = 0; i < n; i++)
	{
		if (abs(A[i].first.y) < 0.5 || abs(A[i].second.y) < 0.5)
			continue;
		if ((A[i].first.y > 0) != (A[i].second.y > 0))
		{
			ld k = -A[i].first.y / (A[i].second - A[i].first).y;
			point B = A[i].first + (A[i].second - A[i].first) * k;
			A.push_back({B, A[i].second});
			A[i].second = B;
		}
	}
	vector<pair<point, point>>A_;
	for (pair<point, point>b : A)
	{
		if (abs(cross(b.first, b.second)) > 1e-8)
		{
			A_.push_back(b);
		}
	}
	for (pair<point, point>&i : A_)
	{
		while (sgn(i.first.y) != sgn(i.second.y))
		{
			if (abs(i.first.y) < abs(i.second.y))
			{
				if (i.second.y > 0)
					i.first.y = 1e-11;
				else
					i.first.y = -1e-11;
			}
			else
			{
				if (i.first.y > 0)
					i.second.y = 1e-11;
				else
					i.second.y = -1e-11;
			}
		}
		ld alfa = i.first.kampas();
		ld beta = i.second.kampas();
		if (alfa > beta)
		{
			swap(i.first, i.second);
			swap(alfa, beta);
		}
		i.first.calc(alfa);
		i.second.calc(beta);
	}
	cout << fixed << setprecision(20) << calc(-PI - 0.0001, PI + 0.0001, A_) << "\n";
}