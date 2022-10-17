#include <iostream>
#include <cstdio>
#define maxn 2005
using namespace std;
const double eps = 1e-6;
int n, a, b;
double p[maxn], q[maxn];
double f[maxn][maxn];
int num[maxn][maxn];
int check(double t)
{
	int cnt;
	double val;
	f[0][0] = 0.0, num[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (register int j = 0; j <= i; j++)
		{
			cnt = num[i - 1][j];
			val = f[i - 1][j];
			if(q[i] - t > 0)
			{
				val += q[i] - t;
				cnt += 1;
			}
			f[i][j] = val, num[i][j] = cnt;
			
			if(j == 0) continue;
			
			cnt = num[i - 1][j - 1];
			val = f[i - 1][j - 1] + p[i];
			if(p[i] + q[i] - p[i] * q[i] - t > p[i])
			{
				val += q[i] - p[i] * q[i] - t;
				cnt += 1;
			}
			if(val > f[i][j])
			{
				f[i][j] = val;
				num[i][j] = cnt;
			}
		}
	}
	return num[n][a];
}
int main()
{
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
	for (int i = 1; i <= n; i++) scanf("%lf", &q[i]);
	double l = 0.0, r = 1.0, mid;
	while(r - l > eps)
	{
		mid = (l + r) / 2;
		if(check(mid) <= b) r = mid;
		else l = mid + eps;
	}
	check(l);
	printf("%.6f", f[n][a] + l * b);
	return 0;
}