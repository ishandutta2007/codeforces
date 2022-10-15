/*input
5 4
1 1 2 1 1
2 1 5
1 2 4 2
2 2 4
2 1 5

*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct mat
{
	ll a[2][2];
};
mat operator*(const mat &a, const mat &b)
{
	mat ret;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ret.a[i][j] = 0;
			for (int k = 0; k < 2; k++)
			{
				ret.a[i][j] += a.a[i][k] * b.a[k][j];
			}
			ret.a[i][j] %= 1000000007;
		}
	}
	return ret;
}
mat operator+(const mat &a, const mat &b)
{
	mat ret;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ret.a[i][j] = (a.a[i][j] + b.a[i][j]) % 1000000007;
		}
	}
	return ret;
}
mat fibo;
mat one;
mat zero;
mat power(mat x, int pow)
{
	if (pow == 0)
	{
		return one;
	}
	if (pow % 2 == 1)
		return (power(x, pow - 1) * x);
	mat ret = power(x, pow / 2);
	return ret * ret;
}
struct ST
{
	int l, r;
	mat suma;
	mat lazy = one;
	ST *left, *right;
	ST(int l, int r, int a[]): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2, a);
			right = new ST((l + r) / 2 + 1, r, a);
			suma = left->suma + right->suma;
		}
		else
		{
			suma = power(fibo, a[l]);
		}
	}
	void fix()
	{
		suma = suma * lazy;
		if (l < r)
		{
			left->lazy = left->lazy * lazy;
			right->lazy = right->lazy * lazy;
		}
		lazy = one;
	}
	void mult(int x, int y, mat daug)
	{
		fix();
		if (r < x || y < l)
			return;
		if (x <= l && r <= y)
		{
			lazy = lazy * daug;
			return fix();
		}
		left->mult(x, y, daug);
		right->mult(x, y, daug);
		suma = left->suma + right->suma;
	}
	mat sum(int x, int y)
	{
		if (r < x || y < l)
			return zero;
		fix();
		if (x <= l && r <= y)
		{
			return suma;
		}
		return left->sum(x, y) + right->sum(x, y);
	}
};
int main()
{
	fibo.a[0][0] = 0;
	fibo.a[0][1] = fibo.a[1][0] = fibo.a[1][1] = 1;
	one.a[0][0] = one.a[1][1] = 1;
	one.a[0][1] = one.a[1][0] = 0;
	zero.a[0][0] = zero.a[1][1] = 0;
	zero.a[0][1] = zero.a[1][0] = 0;
	int n, m;
	cin >> n >> m;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ST medis(1, n, a);
	while (m--)
	{
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1)
		{
			int x;
			cin >> x;
			medis.mult(l, r, power(fibo, x));
		}
		else
		{
			cout << medis.sum(l, r).a[1][0] << "\n";
		}
	}
}