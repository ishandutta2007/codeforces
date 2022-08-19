#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 200200;
int n;
double a[N];
double w;
double ans;

int main()
{
	scanf("%d%lf", &n, &w);
	for (int i = 0; i < 2 * n; i++)
		scanf("%lf", &a[i]);
	sort(a, a + 2 * n);
	double x = min(a[0], a[n] / 2);
	ans = 3 * x * n;
	ans = min(ans, w);
	printf("%.10lf\n", ans);

	return 0;
}