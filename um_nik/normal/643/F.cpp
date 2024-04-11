#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int P = 132;
const int M = (int)17e3;
typedef unsigned int uint;
int n, m, p;

struct Matrix
{
	uint a[P][P];

	Matrix()
	{
		for (int i = 0; i <= p; i++)
			for (int j = 0; j <= p; j++)
				a[i][j] = (uint)(i == j);
	}

	Matrix operator * (const Matrix &A) const
	{
		Matrix R = Matrix();
		for (int i = 0; i <= p; i++)
			for (int j = 0; j <= p; j++)
			{
				R.a[i][j] = 0;
				for (int h = 0; h <= p; h++)
					R.a[i][j] += a[i][h] * A.a[h][j];
			}
		return R;
	}
};
Matrix bin_pow(Matrix A, int pw)
{
	cerr << pw << endl;
	if (pw == 0) return Matrix();
	if (pw % 2 == 1 || pw == 2) return A * bin_pow(A, pw - 1);
	return bin_pow(bin_pow(A, pw / 2), 2);
}

uint gcd(uint x, uint y)
{
	return (y == 0 ? x : gcd(y, x % y));
}

uint dp[M + 3][P];
Matrix A, B, C;
uint a[P];

void init()
{
	for (int w = 0; w <= p; w++)
	{
		for (int k = 0; k <= w; k++)
		{
			if (k > 0)
			{
				a[k - 1] = n + w + 1 - k;
				uint x = k;
				for (int i = 0; i < k; i++)
				{
					uint g = gcd(x, a[i]);
					a[i] /= g;
					x /= g;
				}
				if (x > 1) throw;
			}
			uint res = 1;
			for (int i = 0; i < k; i++)
				res *= a[i];
			A.a[w - k][w] = res;
		}
	}
	B = bin_pow(A, M);
	C = Matrix();
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &p, &m);
	p = min(p, n - 1);
	n -= p;
	init();
/*	for (int i = 0; i <= p; i++)
	{
		for (int j = 0; j <= p; j++)
			printf("%u ", A.a[i][j]);
		printf("\n");
	}*/
	for (int i = 0; i <= p; i++)
		dp[0][i] = 1;
	for (int i = 1; i < M; i++)
	{
		for (int j = 0; j <= p; j++)
			dp[i][j] = 0;
		for (int j = 0; j <= p; j++)
			for (int h = j; h <= p; h++)
				dp[i][h] += dp[i - 1][j] * A.a[j][h];
	}
	uint ans = 0;
	for (int i = 1; i <= m; i++)
	{
		if (i % M == 0) C = C * B;
		uint res = 0;
		int w = i % M;
		for (int j = 0; j <= p; j++)
			res += dp[w][j] * C.a[j][p];
//		printf("%u\n", res);
		res *= i;
		ans ^= res;
	}
	printf("%u\n", ans);

	return 0;
}