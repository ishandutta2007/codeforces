#pragma region Kek
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<ctime>
#include<cstring>
using namespace std;

#pragma comment(linker, "/STACK:17100500")

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 0
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#pragma endregion

const int N = 1 << 7;

struct Matrix
{
	double a[N][N];
	Matrix(double e = 0) : a()
	{
		for (int i = 0; i < N; i++)
			a[i][i] = e;
	}
	double *operator[](int p)
	{
		return a[p];
	}
	const double *operator[](int p) const
	{
		return a[p];
	}
	Matrix operator*(const Matrix &b) const
	{
		Matrix c;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					c[i][j] += a[i][k] * b[k][j];
		return c;
	}
};

int n, x;
double prob[N];
Matrix mat, vec;

Matrix bin_pow(Matrix a, int b)
{
	Matrix c(1);
	while (b > 0)
	{
		if (b % 2 == 1)
			c = c * a;
		a = a * a;
		b /= 2;
	}
	return c;
}

void solve()
{
	scanf("%d%d", &n, &x);
	for (int i = 0; i <= x; i++)
		scanf("%lf", &prob[i]);

	for (int mask = 0; mask < N; mask++)
		for (int i = 0; i <= x; i++)
		{
			int new_mask = mask ^ i;
			mat[mask][new_mask] += prob[i];
		}

	mat = bin_pow(mat, n);
	vec[0][0] = 1;
	vec = vec * mat;
	printf("%.10lf\n", 1 - vec[0][0]);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#else
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#endif

	solve();

	eprintf("\n\nTime: %.3f\n", clock() * 1. / CLOCKS_PER_SEC);
}