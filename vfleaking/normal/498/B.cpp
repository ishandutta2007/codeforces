#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 5000;
const int MaxT = 5000;

int main()
{
	int n, totT;
	cin >> n >> totT;

	static double f[MaxT + 1];
	double res = 0;

	f[0] = 1;
	for (int i = 0; i < n; i++)
	{
		int pv, s;
		scanf("%d %d", &pv, &s);
		double p = (double)pv / 100;

		double cp = 1;
		for (int k = 1; k < s; k++)
			cp *= 1 - p;

		static double g[MaxT + 1];

		g[0] = f[0];
		for (int t = 1; t <= totT; t++)
			g[t] = g[t - 1] * (1 - p) + f[t];
		for (int t = totT; t >= 1; t--)
		{
			double c = g[t - 1];
			double d = 0;
			if (s <= t)
				d = g[t - s];
			f[t] = (c - cp * d) * p;
			if (t >= s)
				f[t] += cp * f[t - s];
		}
		f[0] = 0;

		for (int t = 0; t <= totT; t++)
			res += f[t];
	}

	printf("%.10f\n", res);

	return 0;
}