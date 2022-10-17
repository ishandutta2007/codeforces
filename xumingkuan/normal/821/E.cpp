#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1000000007, MAXN = 18;
const long long MOD2 = (0x7fffffffffffffffll / MOD - MOD) * MOD;
class Matrix
{
public:
	static int n;
	int a[MAXN][MAXN];
	inline void clear()
	{
		memset(a, 0, sizeof(a));
	}
	Matrix()
	{
		clear();
	}
	Matrix(int)
	{
		clear();
		for(int i = 0; i < n; i++)
			a[i][i] = 1;
	}
	int *operator [](int x)
	{
		return a[x];
	}
	const int *operator [](int x) const
	{
		return a[x];
	}
	void operator *=(const Matrix &b);
	Matrix operator *(const Matrix &b) const;
	void print() const
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				printf("%d ", a[i][j]);
			printf("\n");
		}
	}
};
int Matrix::n = 0;
long long buf[MAXN];
Matrix ret;
void Matrix::operator *=(const Matrix &b)
{
	for(int i = 0; i < n; i++)
	{
		memset(buf, 0, n * sizeof(long long));
		const int *tmp1 = a[i];
		for(int j = 0; j < n; j++)
		{
			const long long tmp2 = tmp1[j];
			if(!tmp2)
				continue;
			const int *tmp3 = b[j];
			for(int k = 0; k < n; k++)
			{
				buf[k] += tmp2 * tmp3[k];
				if(buf[k] >= MOD2)
					buf[k] -= MOD2;
			}
		}
		int *tmp4 = ret[i];
		for(int j = 0; j < n; j++)
			tmp4[j] = buf[j] % MOD;
	}
	for(int i = 0; i < n; i++)
		memcpy(a[i], ret[i], n * sizeof(int));
}
Matrix Matrix::operator *(const Matrix &b) const
{
	for(int i = 0; i < n; i++)
	{
		memset(buf, 0, n * sizeof(long long));
		const int *tmp1 = a[i];
		for(int j = 0; j < n; j++)
		{
			const long long tmp2 = tmp1[j];
			if(!tmp2)
				continue;
			const int *tmp3 = b[j];
			for(int k = 0; k < n; k++)
			{
				buf[k] += tmp2 * tmp3[k];
				if(buf[k] >= MOD2)
					buf[k] -= MOD2;
			}
		}
		int *tmp4 = ret[i];
		for(int j = 0; j < n; j++)
			tmp4[j] = buf[j] % MOD;
	}
	return ret;
}
int n;
long long k;
long long a[123], b[123];
int c[123];
Matrix A, ans, now;
int main()
{
	scanf("%d%I64d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%I64d%I64d%d", &a[i], &b[i], &c[i]);
	b[n] = k;
	Matrix::n = 16;
	for(int i = 0; i < Matrix::n; i++)
	{
		A[i][i] = 1;
		if(i != 0)
			A[i][i - 1] = 1;
		if(i != Matrix::n - 1)
			A[i][i + 1] = 1;
	}
	ans[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = c[i] + 1; j < Matrix::n; j++)
			ans[0][j] = 0;
		Matrix::n = c[i] + 1;
		now = A;
		long long len = b[i] - a[i];
		for(long long j = 1; j <= len; j <<= 1, now *= now)
			if(len & j)
				ans *= now;
	}
	printf("%d\n", ans[0][0]);
	return 0;
}