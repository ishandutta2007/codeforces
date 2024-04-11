#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 100000;

const double Epsilon = 1e-7;
inline int sign(const double &a)
{
	if (a < -Epsilon)
		return -1;
	else if (a > Epsilon)
		return 1;
	else
		return 0;
}
inline int dblcmp(const double &a, const double &b)
{
	return sign(a - b);
}

struct point
{
	double a, b; // intercept
	
	friend inline bool operator<(const point &lhs, const point &rhs)
	{
		if (dblcmp(lhs.a, rhs.a) != 0)
			return lhs.a < rhs.a;
		return lhs.b > rhs.b;
	}
};

int main()
{
	int n;
	double a, b, c, d;
	static point p[MaxN + 1];
	
	cin >> n;
	scanf("%lf/%lf %lf/%lf", &a, &b, &c, &d);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		p[i].a = (double)x - (c != 0 ? y / c * d : 0.0);
		p[i].b = (double)y - (a != 0 ? x / b * a : 0.0);
	}
	
	sort(p, p + n);
	reverse(p, p + n);
	
	int len = 0;
	double sta[MaxN + 1];
	for (int i = 0; i < n; i++)
		if (sign(p[i].a) > 0 && sign(p[i].b) > 0)
		{
			int pos = upper_bound(sta, sta + len, p[i].b + Epsilon, greater<double>()) - sta;
			if (pos == len)
				len++;
			sta[pos] = p[i].b;
		}
	cout << len << endl;
	
	return 0;
}