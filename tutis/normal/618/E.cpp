/*input
5 4
1 1 3
2 3 90
2 5 48
1 4 1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
struct point
{
	ld x, y;
	point() {}
	point(ld x, ld y): x(x), y(y) {}
	bool operator<(const point &o)const
	{
		if (x != o.x)
			return x < o.x;
		return y < o.y;
	}
	ld r()
	{
		return sqrtl(x * x + y * y);
	}
};
point operator!(const point &a)
{
	return point(a.x, -a.y);
}
point operator+(const point &a, const point &b)
{
	return point(a.x + b.x, a.y + b.y);
}
point operator-(const point &a, const point &b)
{
	return point(a.x - b.x, a.y - b.y);
}
point operator-(const point &a)
{
	return point(-a.x, -a.y);
}
point operator*(const point &a, const point &b)
{
	return point(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
point operator*(const point &a, ld k)
{
	return point(a.x * k, a.y * k);
}
const ld PI = acosl(-1);
struct matrix
{
	ld A[3][3];
	matrix() {}
	matrix(ld k)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j)
					A[i][j] = k;
				else
					A[i][j] = 0;
			}
		}
	}
	matrix(point v)
	{
		A[0][0] = 1; A[0][1] = 0; A[0][2] = v.x;
		A[1][0] = 0; A[1][1] = 1; A[1][2] = v.y;
		A[2][0] = 0; A[2][1] = 0; A[2][2] = 1;
	}
};
matrix operator*(const matrix &a, const matrix &b)
{
	matrix c;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c.A[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				c.A[i][j] += b.A[i][k] * a.A[k][j];
			}
		}
	}
	return c;
}
matrix suk(ld alfa)
{
	matrix x;
	x.A[0][0] = cos(alfa); x.A[0][1] = -sin(alfa); x.A[0][2] = 0;
	x.A[1][0] = sin(alfa); x.A[1][1] = cos(alfa); x.A[1][2] = 0;
	x.A[2][0] = 0; x.A[2][1] = 0; x.A[2][2] = 1;
	return x;
}
struct ST
{
	int l, r;
	matrix lazy = matrix(1);
	ST *left;
	ST *right;
	ST(int l, int r): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
		}
	}
	void fix()
	{
		if (l < r)
		{
			left->lazy = left->lazy * lazy;
			right->lazy = right->lazy * lazy;
			lazy = matrix(1);
		}
	}
	void add(int x, int y, matrix d)
	{
		if (x <= l && r <= y)
		{
			lazy = lazy * d;
			return;
		}
		if (r < x || y < l)
			return;
		fix();
		left->add(x, y, d);
		right->add(x, y, d);
	}
	matrix get(int i)
	{
		if (l == r)
			return lazy;
		fix();
		if (i <= (l + r) / 2)
			return left->get(i);
		else
			return right->get(i);
	}
} medis(0, 300000);
point convert(ld i, const matrix &x)
{
	ld a = x.A[0][0] * i + x.A[0][2];
	ld b = x.A[1][0] * i + x.A[1][2];
	return point(a, b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	matrix galas(1);
	while (m--)
	{
		int x, i;
		ld z;
		cin >> x >> i >> z;
		matrix op;
		if (x == 1)
		{
			point A = convert(i - 1, medis.get(i - 1));
			point B = convert(i, medis.get(i));
			point v = B - A;
			v = v * (z / v.r());
			op = matrix(v);
		}
		else
		{
			z *= -PI / 180.0;
			point A = convert(i - 1, medis.get(i - 1));
			op = (matrix(-A) * suk(z)) * matrix(A);
		}
		medis.add(i, n, op);
		galas = galas * op;
		point C = convert(n, galas);
		cout << fixed << setprecision(15) << C.x << " " << C.y << "\n";
	}
}