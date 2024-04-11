#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const double PI = acos(-1);

const int MaxN = 1000;

int sgn(const double &x)
{
	const double Eps = 1e-9;
	if (x < -Eps)
		return -1;
	else if (x > Eps)
		return 1;
	else
		return 0;
}

struct point
{
	double x, y;
};

int n;
double w, h;
point po[MaxN];

int curCov;
int eve_n;
double eveA[(MaxN + 8) * 2];
int eveId[(MaxN + 8) * 2];

void normAngle(double &a)
{
	while (a < -PI)
		a += 2 * PI;
	while (a > PI)
		a -= 2 * PI;
}

void addArc(double l, double r)
{
	normAngle(l), normAngle(r);
	
	eveA[eve_n++] = l, eveA[eve_n++] = r;
	if (l > r)
		curCov++;
}

inline bool lessEveId(const int &i, const int &j)
{
	if (sgn(eveA[i] - eveA[j]) != 0)
		return eveA[i] < eveA[j];
	return (i & 1) < (j & 1);
}

bool check(int p, double r)
{
	if (r == 0)
		return true;

	curCov = 0;
	eve_n = 0;

	point o = po[p];
	if (r > o.x)
	{
		double theta = acos(o.x / r);
		addArc(-PI - theta, -PI + theta);
		addArc(-PI - theta, -PI + theta);
	}
	if (r > w - o.x)
	{
		double theta = acos((w - o.x) / r);
		addArc(-theta, theta);
		addArc(-theta, theta);
	}
	if (r > o.y)
	{
		double theta = acos(o.y / r);
		addArc(-PI / 2 - theta, -PI / 2 + theta);
		addArc(-PI / 2 - theta, -PI / 2 + theta);
	}
	if (r > h - o.y)
	{
		double theta = acos((h - o.y) / r);
		addArc(PI / 2 - theta, PI / 2 + theta);
		addArc(PI / 2 - theta, PI / 2 + theta);
	}
	for (int i = 0; i < n; i++)
		if (i != p)
		{
			double d = hypot(po[i].x - o.x, po[i].y - o.y);
			if (d == 0 || d >= 2 * r)
				continue;
			double alpha = atan2(po[i].y - o.y, po[i].x - o.x), theta = acos(d / (2 * r));
			addArc(alpha - theta, alpha + theta);
		}
	for (int i = 0; i < eve_n; i++)
		eveId[i] = i;
	sort(eveId, eveId + eve_n, lessEveId);
	if (curCov <= 1)
		return true;
	for (int i = 0; i < eve_n; i++)
	{
		curCov += (eveId[i] & 1) ? -1 : 1;
		if (curCov <= 1)
			return true;
	}
	return false;
}

int main()
{
	srand(192737);

	cin >> w >> h >> n;
	for (int i = 0; i < n; i++)
		scanf("%lf %lf", &po[i].x, &po[i].y);
	random_shuffle(po, po + n);

	double res = 0.0;
	for (int i = 0; i < n; i++)
		if (check(i, res + 1e-9))
		{
			double ri = hypot(w, h);
			double delta = ri - res;
			while (delta > 1e-10)
			{
				double mid = (res + ri) / 2;
				if (check(i, mid))
					res = mid;
				else
					ri = mid;
				delta /= 2;
			}
		}

	printf("%.10f\n", res);

	return 0;
}