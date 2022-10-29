#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

int n, P, a[100001], b[100001];
long long Sum;

bool check(double T)
{
	double tot = 0;
	for (int i = 1; i <= n; ++ i)
	{
		tot += max(a[i] * T - b[i], 0.0) / P;
	}
	if (tot <= T) return 1;
	return 0;
}

int main()
{
	scanf("%d%d", &n, &P);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%d%d", &a[i], &b[i]);
		Sum += a[i];
	}
	
//	printf("%d\n", check(2));
	
	if (Sum <= P) printf("-1\n");
	else {
		double L, R, Ans;
		L = 0; R = 1e14; Ans = 0;
		for (int i = 1; i <= 100; ++ i)
		{
			double Mid = (L + R) / 2;
			if (check(Mid))
			{
				if (Mid > Ans) Ans = Mid;
				L = Mid;
			} else R = Mid;
		}
		printf("%.9lf\n", Ans);
	}
	return 0;
}