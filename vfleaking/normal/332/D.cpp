#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 2000;

int main()
{
	int n, nK;
	static int a[MaxN + 1][MaxN + 1];

	cin >> n >> nK;
	for (int i = 1; i <= n; i++)
	{
		a[i][i] = -1;
		for (int j = i + 1; j <= n; j++)
			scanf("%d", &a[i][j]), a[j][i] = a[i][j];
	}

	double res = 0;
	for (int v = 1; v <= n; v++)
	{
		int d = 0;
		for (int u = 1; u <= n; u++)
			d += a[v][u] != -1;

		if (d >= nK)
		{
			double prob = (double)nK / d;
			for (int k = 0; k < nK; k++)
				prob *= (double)(d - k) / (n - k);

			for (int u = 1; u <= n; u++)
				if (a[v][u] != -1)
					res += prob * a[v][u];
		}
	}

	printf("%.0f\n", floor(res));

	return 0;
}