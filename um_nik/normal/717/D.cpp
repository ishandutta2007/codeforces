#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

//const int N = 16;
const int N = 128;

struct Matrix
{
	double a[N][N];
	
	Matrix()
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				a[i][j] = (i == j ? 1 : 0);
	}

	Matrix operator * (const Matrix &A) const
	{
		Matrix R = Matrix();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				R.a[i][j] = 0;
				for (int h = 0; h < N; h++)
					R.a[i][j] += a[i][h] * A.a[h][j];
			}
		return R;
	}
};

Matrix bin_pow(Matrix A, int p)
{
	if (p == 0) return Matrix();
	if (p == 2 || (p & 1)) return A * bin_pow(A, p - 1);
	return bin_pow(bin_pow(A, p / 2), 2);
}

double p[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= m; i++)
		scanf("%lf", &p[i]);
	Matrix A = Matrix();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A.a[i][j] = p[i ^ j];
	A = bin_pow(A, n);
	printf("%.13lf\n", 1 - A.a[0][0]);

	return 0;
}