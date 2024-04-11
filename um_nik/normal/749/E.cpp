#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100100;
int n;
int p[N];
double f[2][N];

void add(int k, int r, double x)
{
	for (; r < n; r |= r + 1)
		f[k][r] += x;
	return;
}
double getSum(int k, int r)
{
	double res = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		res += f[k][r];
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
		p[i] = n - p[i];
	}
	double ans = 0;
	for (int k = 1; k <= n; k++)
		ans += (double)(n + 1 - k) * k * (k - 1) / 4;

	for (int i = 0; i < n; i++)
	{
		double A = getSum(0, p[i]), B = getSum(1, p[i]);
		ans += A + B * i;
		add(0, p[i], (double)n * (n - 2 * i - 1) / 2.);
		add(1, p[i], i + 1);
	}
	printf("%.13lf\n", (2 * ans) / n / (n + 1));

	return 0;
}