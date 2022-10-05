#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const double eps = 1e-10;
int T, n, l;
double tot1, tot2, a[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &l);
		for (int i = 1; i <= n; i++)
			scanf("%lf", &a[i]);
		a[n + 1] = l;
		double lt = 0, rt = l;
		while ((rt - lt) / l >= eps)
		{
			tot1 = tot2 = 0;
			double mid = (lt + rt) / 2;
			for (int i = 1; i <= n + 1; i++)
				if (a[i] <= mid) tot1 += (a[i] - a[i - 1]) / i;
				else
				{
					tot1 += (mid - a[i - 1]) / i;
					break;
				}
			for (int i = n; i >= 0; i--)
				if (a[i] >= mid) tot2 += (a[i + 1] - a[i]) / (n - i + 1);
				else
				{
					tot2 += (a[i + 1] - mid) / (n - i + 1);
					break;
				}
			if (tot1 >= tot2) rt = mid;
			else lt = mid;
		}
		printf("%.15lf\n", tot1);
	}
	return 0;
}