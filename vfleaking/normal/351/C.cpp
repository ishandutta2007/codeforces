#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int MaxN = 20;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

class Matrix
{
public:
	static const int MaxMatN = 30;
	static int N;
private:
	int a[MaxMatN + 1][MaxMatN + 1];
public:
	inline int operator()(const int &x, const int &y) const
	{
		return a[x][y];
	}
	inline int &operator()(const int &x, const int &y)
	{
		return a[x][y];
	}

	inline Matrix &operator*=(const Matrix &rhs)
	{
		static int c[MaxMatN + 1][MaxMatN + 1];
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++)
			{
				c[i][j] = INT_MAX;
				for (int k = 0; k <= N; k++)
					if (a[i][k] != INT_MAX && rhs.a[k][j] != INT_MAX)
						tension(c[i][j], a[i][k] + rhs.a[k][j]);
			}
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++)
				a[i][j] = c[i][j];
		return *this;
	}
};
int Matrix::N;

inline Matrix matpow(const Matrix &a, const int &n)
{
	Matrix res;
	for (int i = 0; i <= Matrix::N; i++)
		for (int j = 0; j <= Matrix::N; j++)
			res(i, j) = (i != j) * INT_MAX;
	Matrix t = a;
	for (int i = n; i > 0; i >>= 1)
	{
		if (i & 1)
			res *= t;
		t *= t;
	}
	return res;
}

int main()
{
	int n, m;
	static int a[MaxN], b[MaxN];

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	Matrix::N = n * 3 / 2;
	Matrix res;
	for (int i = 0; i <= Matrix::N; i++)
		for (int j = 0; j <= Matrix::N; j++)
			res(i, j) = (i != j) * INT_MAX;
	for (int p = 0; p < n; p++)
	{
		Matrix t;
		for (int i = 0; i <= Matrix::N; i++)
			for (int j = 0; j <= Matrix::N; j++)
			{
				if (j == i + 1)
					t(i, j) = a[p];
				else if (j == i - 1)
					t(i, j) = b[p];
				else
					t(i, j) = INT_MAX;
			}
		res *= t;
	}

	res = matpow(res, m);

	cout << res(0, 0) << endl;

	return 0;
}