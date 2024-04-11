#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef pair<double, double> pdd;
#define mp make_pair

const double INF = 1e100;
pdd A, B, C;
const int N = 100100;
int n;
pdd p[N];
double ans = INF;
double addToAns = 0;
double a[2][3];
int b[2][3];

double sqr(double x)
{
	return x * x;
}
double getDist(pdd A, pdd B)
{
	return sqrt(sqr(A.first - B.first) + sqr(A.second - B.second));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%lf%lf", &B.first, &B.second);
	scanf("%lf%lf", &C.first, &C.second);
	scanf("%lf%lf", &A.first, &A.second);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf", &p[i].first, &p[i].second);

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			a[i][j] = INF;
			b[i][j] = -1;
		}

	for (int i = 0; i < n; i++)
	{
		addToAns += 2 * getDist(A, p[i]);
		double d = getDist(B, p[i]) - getDist(A, p[i]);
		int col = i;
		for (int j = 0; j < 2; j++)
		{
			if (d < a[0][j])
			{
				swap(a[0][j], d);
				swap(b[0][j], col);
			}
		}
		d = getDist(C, p[i]) - getDist(A, p[i]);
		col = i;
		for (int j = 0; j < 2; j++)
		{
			if (d < a[1][j])
			{
				swap(a[1][j], d);
				swap(b[1][j], col);
			}
		}
	}

	ans = min(a[0][0], a[1][0]);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			if (b[0][i] == b[1][j]) continue;
			ans = min(ans, a[0][i] + a[1][j]);
		}

	printf("%.10lf\n", ans + addToAns);

	return 0;
}