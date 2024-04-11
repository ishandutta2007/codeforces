/*input
7
-7 54
-5 31
-2 17
20 19
32 23
34 27
26 57

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
	point() {}
	point(ld x, ld y): x(x), y(y)
	{

	}
	ld r()
	{
		return sqrtl(x * x + y * y);
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
point operator*(point a, point b)
{
	return point(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
ld cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
point X(point a, point b, point c, point d)
{
	b = b - a;
	d = d - c;
	//a+bx=c+dy
	//(a+bx)d=(c+dy)d
	//ad+xbd=cd
	//x=(c-a)d/bd
	ld x = cross(c - a, d) / cross(b, d);
	if (!isfinite(x))
		x = 0.5;
	return a + b * x;
}
point a[302];
ld ta[302];
ld tb[302];
ld tc[302];
pair<int, point> mx[302];
int kiek[301];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y;
	a[n] = a[0];
	point a0 = a[0];
	point a1 = a[2];
	for (int k = 0; k < n; k++)
	{
		tc[k] = -cross(a[k + 1], a[k]);
		ta[k] = (a[k] - a[k + 1]).y;
		tb[k] = -(a[k] - a[k + 1]).x;

		tc[k] /= (a[k] - a[k + 1]).r();
		ta[k] /= (a[k] - a[k + 1]).r();
		tb[k] /= (a[k] - a[k + 1]).r();
	}
	auto check = [&](const ld r)->bool
	{
		fill_n(mx, 300, make_pair(0, a[0]));
		for (int i = 0; i < n; i++)
		{
			point v = a[i + 1] - a[i];
			v = v * point(0, r / v.r());
			for (int j = 0; j < i; j++)
			{
				point w = a[j + 1] - a[j];
				w = w * point(0, r / w.r());
				for (point di : {point(0, 0), v})
				{
					for (point dj : {point(0, 0), w})
					{
						point x = X(a[i] + di, a[i + 1] + di, a[j] + dj, a[j + 1] + dj);
						bool ok = true;
						for (int k = n - 1; k >= 0; k--)
						{
							ld d = ta[k] * x.x + tb[k] * x.y + tc[k];
							if (d < -1e-8)
							{
								ok = false;
								break;
							}
							if (d < r + 1e-8)
							{
								kiek[k] = 1 + kiek[k + 1];
							}
							else
							{
								kiek[k] = 0;
							}
						}
						if (ok == false)
							continue;
						if (kiek[0] == n)
						{
							a0 = a1 = x;
							return true;
						}
						for (int i = n - 1; i >= 0; i--)
						{
							if (kiek[i] != 0)
							{
								kiek[i] = 1 + kiek[(i == n - 1) ? 0 : (i + 1)];
							}
							if (kiek[i] > mx[i].first)
							{
								mx[i].first = kiek[i];
								mx[i].second = x;
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			int ki = mx[i].first;
			int j = (i + ki) % n;
			int kj = mx[j].first;
			if (ki + kj >= n)
			{
				a0 = mx[i].second;
				a1 = mx[j].second;
				return true;
			}
		}
		return false;
	};
	ld r = 15000;
	ld w = r;
	while (w > 4e-7)
	{
		if (check(r - w))
			r = r - w;
		w /= 2;
	}
	cout << fixed << setprecision(10);
	cout << r << "\n";
	cout << a0.x << " " << a0.y << "\n";
	cout << a1.x << " " << a1.y << "\n";
}