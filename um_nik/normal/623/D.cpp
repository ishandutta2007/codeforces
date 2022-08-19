#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

const double INF = (int)1e9;

const int T = (int)1e6;
const int N = 111;
int n;
double p[N];
double q[N];
int r[N];
double ans = 1;
int a[N];

int choose()
{
	int v = -1;
	double val = INF;
	for (int i = 0; i < n; i++)
	{
		double w = (1 - q[i]) / (1 - q[i] * (1 - p[i]));
		if (w < val)
		{
			val = w;
			v = i;
		}
	}
	return v;
}

void addOne()
{
	int v = choose();
	a[v]++;
	q[v] *= (1 - p[v]);
	double Q = 1;
	for (int i = 0; i < n; i++)
		Q *= 1 - q[i];
	ans += 1 - Q;
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &r[i]);
		p[i] = r[i] / 100.;
		q[i] = 1;
	}
	for (int it = 0; it < T; it++)
		addOne();
	printf("%.10lf\n", ans);

	return 0;
}