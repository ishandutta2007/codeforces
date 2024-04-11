#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

const ll MOD = (ll)1e9 + 7;
const int N = 101;
int n, pow;
int a[N];

ll sum(ll x, ll y)
{
	x += y;
	if (x >= MOD)
		return x - MOD;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}

struct Matrix
{
	ll a[N][N];

	Matrix()
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				a[i][j] = 0;
	}

	Matrix operator * (const Matrix &X) const
	{
		Matrix res;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				res.a[i][j] = 0;
				for (int h = 0; h < N; h++)
				{
					res.a[i][j] = sum(res.a[i][j], mult(a[i][h], X.a[h][j]));
				}
			}
		return res;
	}
};

Matrix bin_pow(Matrix x, ll pow)
{
	if (pow == 1) return x;
	if (pow == 2) return x * x;
	if (pow & 1) return x * bin_pow(x, pow - 1);
	return bin_pow(bin_pow(x, pow / 2), 2);
}

Matrix generate()
{
	Matrix A;
	for (int i = 1; i < N - 1; i++)
		A.a[i][i - 1] = 1;
	A.a[N - 1][N - 1] = 1;
	A.a[0][N - 1] = 1;
	for (int i = 0; i < N - 1; i++)
		A.a[0][i] = a[i + 1];
	return A;
}

int main()
{
	scanf("%d%d", &n, &pow);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	Matrix A = generate();
	pow++;
	A = bin_pow(A, pow);
	printf("%I64d\n", A.a[0][100]);

	return 0;
}