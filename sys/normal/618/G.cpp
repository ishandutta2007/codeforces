#include <bits/stdc++.h>
using namespace std;

const int Maxn = 55, lim = 50;
int n;
double p, f[Maxn][Maxn], a[Maxn][Maxn], b[Maxn][Maxn];
struct Matrix
{
	double val[Maxn][Maxn];
	Matrix()
	{
		memset(val, 0, sizeof(val));
	}
	Matrix operator * (const Matrix &A) const
	{
		Matrix ans;
		for (int i = 1; i <= lim + 1; i++)
			for (int j = 1; j <= lim + 1; j++)
				for (int k = 1; k <= lim + 1; k++)
					ans.val[i][j] += val[i][k] * A.val[k][j];
		return ans;
	}
} pre, trans;
Matrix fast_pow(Matrix x, long long y)
{
	Matrix ans, now = x;
	for (int i = 1; i <= lim + 1; i++) ans.val[i][i] = 1;
	while (y)
	{
		if (y & 1) ans = ans * now;
		now = now * now;
		y >>= 1;
	}
	return ans;
}
double ans;
int main()
{
	scanf("%d%lf", &n, &p), p /= 1e9;
	a[1][1] = p, a[1][2] = 1 - p;
	b[1][2] = 1 - p;
	for (int i = 2; i <= lim; i++)
	{
		a[i][1] = p, a[i][2] = 1 - p, b[i][2] = 1 - p;
		for (int j = 2; j <= lim; j++)
		{
			a[i][j] += a[i][j - 1] * a[i - 1][j - 1];
			b[i][j] += b[i][j - 1] * a[i - 1][j - 1];
		}
	}
	for (int i = lim; i >= 1; i--)
		for (int j = 1; j <= lim; j++)
			a[i][j] *= 1 - a[i - 1][j], b[i][j] *= 1 - a[i - 1][j];
	f[1][1] = 1, f[1][2] = 2;
	for (int i = 2; i <= lim; i++)
	{
		for (int j = 2; j <= lim; j++)
		{
			double tmp1 = 0, tmp2 = 0;
			for (int k = 1; k < j; k++)
				tmp1 += f[i - 1][k] * a[i - 1][k], tmp2 += a[i - 1][k];
			f[i][j] = j + tmp1 / tmp2;
		}
		double tmp1 = 0, tmp2 = 0;
		for (int k = 2; k <= lim; k++)
			tmp1 += f[i - 1][k] * b[i - 1][k], tmp2 += b[i - 1][k];
		f[i][1] = 1 + tmp1 / tmp2;
	}
	for (int j = 2; j <= lim; j++)
	{
		double tmp2 = 0;
		for (int k = 1; k < j; k++)
			tmp2 += a[lim][k];
		for (int k = 1; k < j; k++)
			trans.val[k][j] = a[lim][k] / tmp2;
		trans.val[lim + 1][j] = j;
	}
	double tmp2 = 0;
	for (int k = 2; k <= lim; k++)
		tmp2 += b[lim][k];
	for (int k = 2; k <= lim; k++)
		trans.val[k][1] = b[lim][k] / tmp2;
	trans.val[lim + 1][1] = trans.val[lim + 1][lim + 1] = pre.val[1][lim + 1] = 1;
	if (n < lim)
		for (int i = 1; i <= n + 1; i++)
			ans += f[n][i] * a[n][i];
	else
	{
		for (int i = 1; i <= lim; i++)
			pre.val[1][i] = f[lim][i];
		Matrix result = pre * fast_pow(trans, n - lim);
		for (int i = 1; i <= lim; i++)
			ans += result.val[1][i] * a[lim][i];
	}
	printf("%.20lf", ans);
	return 0;
}