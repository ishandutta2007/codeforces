#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

const double eps = 1e-12;
int n, T;
const int N = 5050;
int a[N][2];
double b[N][2];
double dp[2][N][2];
double ans;

double bin_pow(double x, int pow)
{
	if (pow == 0)
		return 1.;
	if (pow == 1)
		return x;
	if (pow == 2)
		return x * x;
	if (pow & 1)
		return bin_pow(x, pow - 1) * x;
	return bin_pow( bin_pow(x, pow / 2), 2);
}

void read()
{
	scanf("%d%d", &n, &T);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i][0], &a[i][1]);
		b[i][0] = (double)a[i][0] / 100.;
		if (a[i][0] == 0)
			b[i][1] = 1.;
		else
			b[i][1] = bin_pow(1. - b[i][0], a[i][1]);
	}
	return;
}

void solve()
{
	dp[0][0][1] = 1.;
	for (int it = 0; it < n; it++)
	{
		for (int t = 0; t < T; t++)
		{
			if (fabs(dp[0][t][0] + dp[0][t][1]) < eps) continue;
			dp[0][t][0] += dp[0][t][1];
			dp[1][t + 1][1] += dp[0][t][0] * b[it][0];
			dp[0][t + 1][0] += dp[0][t][0] * (1. - b[it][0]);
			if (t + a[it][1] <= T)
			{
				dp[1][t + a[it][1]][1] += dp[0][t][1] * b[it][1];
				dp[0][t + a[it][1]][0] -= dp[0][t][1] * b[it][1];
			}
		}
		ans += (dp[0][T][0] + dp[0][T][1]) * (double)it;
		for (int t = 0; t <= T; t++)
			for (int j = 0; j < 2; j++)
			{
				dp[0][t][j] = dp[1][t][j];
				dp[1][t][j] = 0.;
			}
	}
	for (int t = 0; t <= T; t++)
		ans += (dp[0][t][0] + dp[0][t][1]) * (double)n;
	return;
}

int main()
{
	read();
	solve();
	printf("%.13lf\n", ans);

	return 0;
}