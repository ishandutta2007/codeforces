#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 1000000;

inline long long getF(long long c, int l)
{
	if (c < 0)
		return -1;
	return c / l;
}

int main()
{
	int n;
	int l;
	long long t;
	static int a[MaxN];

	cin >> n >> l >> t;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);

	t *= 2;

	double res = (double)n * (n - 1) / 2;
	for (int i = 0, j = 0; i < n; i++)
	{
		while (j > 0 && getF(t - a[i] + a[j - 1], l) != getF(t - a[i] + a[0], l))
			j--;
		while (j < n && getF(t - a[i] + a[j], l) == getF(t - a[i] + a[0], l))
			j++;
		res += (double)j * getF(t - a[i] + a[0], l);
		if (j < n)
			res += (double)(n - j) * getF(t - a[i] + a[j], l);
	}
	res -= (double)n * (t / l);
	res /= 4;
	
	printf("%.10f\n", res);

	return 0;
}