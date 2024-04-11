#include <stdio.h>
#include <cmath>
using namespace std;

double mindat[100005];
double maxdat[100005];
double d[100005], e[100005];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &maxdat[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &mindat[i]);
	}

	double S = 0, T = 0;
	for (int i = 1; i <= n; i++)
	{
		double X = mindat[i] + maxdat[i];
		double c1 = 1;
		double c2 = S - X - T;
		double c3 = -S * X + maxdat[i];

		double deter = c2*c2 - 4 * c1*c3;
		if (deter < 0) deter = 0;
		else deter = sqrt(deter);
		double res1 = (-c2 + deter) / 2 * c1;
		double res2 = (-c2 - deter) / 2 * c1;

		if (-1e-9 <= res1 && res1 <= 1 + 1e-9)
		{
			e[i] = res1;
			if (e[i] < 0) e[i] = 0;
			if (e[i] > 1) e[i] = 1;
		}
		else e[i] = res2;
		d[i] = X - e[i];

		S += e[i];
		T += d[i];
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%.9f ", d[i]);
	}
	printf("\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%.9f ", e[i]);
	}
	printf("\n");
}