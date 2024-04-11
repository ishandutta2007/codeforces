/*input
2 5
2 3
3 4
1 1
1 4
4 2
4 7
2 5
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct point
{
	ld x, y;
	point()
	{
		x = 0;
		y = 0;
	}
	point (ld x, ld y): x(x), y(y)
	{

	}
	ld r()
	{
		return sqrtl(x * x + y * y);
	}
	ld r2()const
	{
		return (x * x + y * y);
	}
	point operator!()const
	{
		return point(x, -y);
	}
	ld kampas()
	{
		return atan2(y, x);
	}
	int ketv()
	{
		if (x >= 0 && y >= 0)
			return 0;
		if (y >= 0)
			return 1;
		if (x <= 0)
			return 2;
		return 3;
	}
};
point operator-(const point &a, const point &b)
{
	return point(a.x - b.x, a.y - b.y);
}
point operator+(const point &a, const point &b)
{
	return point(a.x + b.x, a.y + b.y);
}
point operator*(const point &a, ld k)
{
	return point(a.x * k, a.y * k);
}
point operator*(const point &a, const point &b)
{
	return point(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
point operator/(const point &a, const point &b)
{
	return (a * (!b)) * ld(1.0 / b.r2());
}
ld cross(const point &a, const point &b)
{
	return a.x * b.y - a.y * b.x;
}
point inv(const point &p, const point &a)
{
	return point(1, 0) / (!(a - p));
}
bool operator !=(const point &a, const point &b)
{
	return (a - b).r2() > 1e-10;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if (m <= 2)
	{
		cout << "-1\n";
		return 0;
	}
	point R[n], B[m];
	for (int i = 0; i < n; i++)
		cin >> R[i].x >> R[i].y;
	for (int i = 0; i < m; i++)
		cin >> B[i].x >> B[i].y;
	ld best = 1;
	auto check = [&](point p)->void
	{
		vector<point>B_;
		vector<point>R_;
		for (point r : R)
			R_.push_back(inv(p, r));
		for (point b : B)
		{
			if (b != p)
				B_.push_back(inv(p, b));
		}
		int i = 0;
		for (int j = 0; j < (int)B_.size(); j++)
			if (B_[j].x < B_[i].x)
				i = j;
		swap(B_[0], B_[i]);
		sort(B_.begin() + 1, B_.end(), [&](point a, point b) {
			ld c = cross(a - B_[0], b - B_[0]);
			if (abs(c) < 1e-14)
				return (a - B_[0]).r2() < (b - B_[0]).r2();
			else
				return c > 0;
		});
		vector<point>C;
		for (point b : B_)
		{
			while (C.size() >= 2)
			{
				if (cross(b - C.back(), C.back() - C[C.size() - 2]) > -1e-15)
					C.pop_back();
				else
					break;
			}
			C.push_back(b);
		}
		auto check1 = [&](point a, point v, bool rr)
		{
			ld d = abs(cross(a, v) / v.r());
			if (d < 1e-16 || isnan(d))
				return;
			ld r = 0.5 / d;
			for (point r : R_)
			{
				if (cross(r - a, v) > 0)
				{
					rr = true;
				}
			}
			for (point r : B_)
			{
				if (cross(r - a, v) > 1e-16)
				{
					rr = false;
					break;
				}
			}
			if (rr)
			{
				best = max(best, r);
			}
		};
		for (int i = 0; i < (int)C.size(); i++)
		{
			check1(C[i], C[i]*point(0, -1), false);
			int j = (i + 1) % C.size();
			check1(C[i], C[j] - C[i], false);
		}
		for (point r : R_)
		{
			int i = 0;
			int j = 0;
			for (int w = 1024; w != 0; w /= 2)
			{
				for (int ww : {w, -w})
				{
					int i1 = (i + ww) % C.size();
					if (i1 < 0)
						i1 += C.size();
					if (i1 >= (int)C.size())
						i1 -= C.size();
					if (cross(C[i1] - r, C[i] - r) < 0)
						i = i1;
				}
				for (int ww : {w, -w})
				{
					int j1 = (j + ww) % C.size();
					if (j1 < 0)
						j1 += C.size();
					if (j1 >= (int)C.size())
						j1 -= C.size();
					if (cross(C[j1] - r, C[j] - r) > 0)
						j = j1;
				}
			}
			check1(r, C[j] - r, true);
			check1(r, r - C[i], true);
		}
	};
	for (point r : R)
	{
		int p[m];
		iota(p, p + m, 0);
		sort(p, p + m, [&](int i, int j)
		{
			if (i == j)
				return false;
			return (B[i] - r).kampas() < (B[j] - r).kampas();
		});
		for (int t = 0; t < m; t++)
		{
			if ((B[p[t]] - r).ketv() != (B[p[(t + 1) % m]] - r).ketv() &&
			        cross(B[p[t]] - r, B[p[(t + 1) % m]] - r) < 0.2)
			{
				cout << "-1\n";
				return 0;
			}
		}
	};
	for (point p : B)
		check(p);
	cout << fixed << setprecision(10) << best << "\n";
}