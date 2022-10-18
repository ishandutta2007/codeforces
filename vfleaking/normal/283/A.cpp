#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxN = 200001;

int main()
{
	int nO;
	s64 sum = 0ll;
	int n = 1;
	static int a[MaxN + 1];

	a[1] = 0;

	cin >> nO;
	for (int i = 1; i <= nO; i++)
	{
		int type;
		scanf("%d", &type);

		if (type == 1)
		{
			int p, x;
			scanf("%d %d", &p, &x);
			a[p] += x;
			sum += (s64)x * p;
		}
		else if (type == 2)
		{
			int x;
			scanf("%d", &x);
			a[++n] = x;
			a[n - 1] -= x;
			sum += x;
		}
		else if (type == 3)
		{
			sum -= a[n];
			a[n - 1] += a[n];
			n--;
		}
		printf("%.10lf\n", (double)sum / n);
	}

	return 0;
}