#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 100;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

int main()
{
	int n;
	static double p[MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p, p + n);

	double res = 0.0;

	double p0, p1;

	p0 = 1.0, p1 = 0.0;
	for (int i = 0; i < n; i++)
	{
		p1 = p0 * p[i] + p1 * (1 - p[i]), p0 *= 1 - p[i];
		relax(res, p1);
	}

	p0 = 1.0, p1 = 0.0;
	for (int i = n - 1; i >= 0; i--)
	{
		p1 = p0 * p[i] + p1 * (1 - p[i]), p0 *= 1 - p[i];
		relax(res, p1);
	}

	printf("%.10f\n", res);

	return 0;
}