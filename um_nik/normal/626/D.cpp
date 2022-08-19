#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 10100;
int n;
int a[N];
double p[N];
double q[N];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			p[a[j] - a[i]] += 2. / n / (n - 1);
	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < N / 2; j++)
			q[i + j] += p[i] * p[j];
	double sum = 0;
	double ans = 0;
	for (int i = 0; i < N / 2; i++)
	{
		ans += p[i] * sum;
		sum += q[i];
	}
	printf("%.10lf\n", ans);

	return 0;
}