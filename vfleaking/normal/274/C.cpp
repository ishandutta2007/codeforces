#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 100;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

inline int sgn(const double &a)
{
	const double Eps = 1e-5;
	if (a < -Eps)
		return -1;
	else if (a > Eps)
		return 1;
	else
		return 0;
}
inline int dblcmp(const double &a, const double &b)
{
	return sgn(a - b);
}

struct point
{
	double x, y;
};

inline double sqr(double x)
{
	return x * x;
}
inline double norm(const point &p)
{
	return sqr(p.x) + sqr(p.y);
}
inline double dist2(const point &a, const point &b)
{
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}

inline double dot(const point &a, const point &o, const point &b)
{
	return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y);
}
inline double cross(const point &a, const point &o, const point &b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

int n;
point po[MaxN];

inline double getR(const int &pa, const int &pb, const int &pc)
{
	point a = po[pa], b = po[pb], c = po[pc];
	if (sgn(dot(a, b, c)) < 0 || sgn(dot(c, a, b)) < 0 || sgn(dot(b, c, a)) < 0)
		return 0;

	double e[2][3] = {
		{2 * (a.x - c.x), 2 * (a.y - c.y), norm(a) - norm(c)},
		{2 * (b.x - c.x), 2 * (b.y - c.y), norm(b) - norm(c)}
	};

	double det = e[0][0] * e[1][1] - e[0][1] * e[1][0];
	if (sgn(det) == 0)
		return 0;
	point o;
	o.x = (e[0][2] * e[1][1] - e[0][1] * e[1][2]) / det;
	o.y = (e[0][0] * e[1][2] - e[0][2] * e[1][0]) / det;

	double r2 = dist2(o, a);
	bool ok = true;
	point d;
	if (sgn(cross(a, o, b)) == 0)
	{
		d = c;
		ok = false;
	}
	if (sgn(cross(b, o, c)) == 0)
	{
		d = a;
		ok = false;
	}
	if (sgn(cross(c, o, a)) == 0)
	{
		d = b;
		ok = false;
	}
	for (int i = 0; i < n; i++)
		if (i != pa && i != pb && i != pc)
		{
			switch (dblcmp(dist2(po[i], o), r2))
			{
				case -1:
					return 0;
				case 0:
					if (!ok && sgn(cross(po[i], o, d)) == 0)
						ok = true;
					break;
				case 1:
					break;
			}
		}
	if (!ok)
		return 0;
    return sqrt(r2);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%lf %lf", &po[i].x, &po[i].y);

	double res = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				relax(res, getR(i, j, k));

	if (res == 0)
		printf("-1\n");
	else
		printf("%.10f\n", res);

	return 0;
}