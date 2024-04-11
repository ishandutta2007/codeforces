#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

double r;
double tr;

inline double getSum(int n)
{
	return (s64)n * (n - 1) * r + 2 * (n - 1) * tr;
}

int main()
{
	int m;
	cin >> m >> r;

	tr = r * sqrt(2.0);

	double res = 0.0;
	for (int i = 1; i <= m; i++)
	{
		double cur = 0.0;
		if (i - 2 >= 1)
			cur += getSum(i - 1);
		if (i - 1 >= 1)
			cur += 2 * r + tr;
		cur += 2 * r;
		if (i + 1 <= m)
			cur += 2 * r + tr;
		if (i + 2 <= m)
			cur += getSum(m - i);
		cur /= m, cur /= m;
		res += cur;
	}
	cout << fixed << setprecision(8) << res << endl;

	return 0;
}