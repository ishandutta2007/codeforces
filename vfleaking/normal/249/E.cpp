#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const s64 Mod = 10000000000ll;

inline s64 modplus(const s64 &a, const s64 &b)
{
	return a + b < Mod ? a + b : a + b - Mod;
}
inline s64& modplusto(s64 &a, const s64 &b)
{
	a += b;
	if (a >= Mod)
		a -= Mod;
	return a;
}
inline s64 modminus(const s64 &a, const s64 &b)
{
	return a - b >= 0 ? a - b : a - b + Mod;
}
inline s64& modminusto(s64 &a, const s64 &b)
{
	a -= b;
	if (a < 0)
		a += Mod;
	return a;
}
inline s64 modmult(const s64 &a, const s64 &b)
{
	s64 res = 0ll;
	s64 t = a;
	for (int i = 0; i < 63; i++)
	{
		if (b & (1ll << i))
			modplusto(res, t);
		modplusto(t, t);
	}
	return res;
}

inline double f(const double &x, const double &y)
{
	if (x == 0 || y == 0)
		return 0.0;
	
	double res = 0.0;
	if (x < y)
	{
		res += (x * x + 1) * (x * x) / 2;
		res += (y - x) * ((x + 1) * x / 2);
		res += x * ((y - 1) * y * (2 * y - 1) - (x - 1) * x * (2 * x - 1)) / 6;
	}
	else
	{
		res += (y * y + 1) * (y * y) / 2;
		res -= (x - y) * (y * (y - 1) / 2);
		res += y * (x * (x + 1) * (2 * x + 1) - y * (y + 1) * (2 * y + 1)) / 6;
	}
	return res;
}

// 1 + 2 + ... + n = n * (n + 1) / 2
inline s64 getSum1(s64 a)
{
	s64 b = a + 1;
	if (a % 2 == 0)
		a /= 2;
	else
		b /= 2;
	
	a %= Mod, b %= Mod;
	return modmult(a, b);
}

// 1^2 + 2^2 + ... + n^2 = n * (n + 1) * (2n + 1) / 6
inline s64 getSum2(s64 a)
{
	s64 b = a + 1;
	s64 c = 2 * a + 1;
	
	if (a % 2 == 0)
		a /= 2;
	else
		b /= 2;
	if (a % 3 == 0)
		a /= 3;
	else if (b % 3 == 0)
		b /= 3;
	else
		c /= 3;
	
	a %= Mod, b %= Mod, c %= Mod;
	return modmult(a, modmult(b, c));
}

inline s64 g(const s64 &x, const s64 &y)
{
	if (x == 0 || y == 0)
		return 0ll;
	
	s64 res = 0ll;
	if (x < y)
	{
		modplusto(res, getSum1(x * x));
		modplusto(res, modmult(y - x, getSum1(x)));
		modplusto(res, modmult(x, modminus(getSum2(y - 1), getSum2(x - 1))));
	}
	else
	{
		modplusto(res, getSum1(y * y));
		modminusto(res, modmult(x - y, getSum1(y - 1)));
		modplusto(res, modmult(y, modminus(getSum2(x), getSum2(y))));
	}
	
	return res;
}

int main()
{
	int nCases;
	cin >> nCases;
	while (nCases--)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		double ret = f(x2, y2) - f(x1 - 1, y2) - f(x2, y1 - 1) + f(x1 - 1, y1 - 1);
		s64 res = 0;
		modplusto(res, g(x2, y2));
		modminusto(res, g(x1 - 1, y2));
		modminusto(res, g(x2, y1 - 1));
		modplusto(res, g(x1 - 1, y1 - 1));
		if (ret >= Mod)
			printf("...%010I64d\n", res);
		else
			printf("%I64d\n", res);
	}
	
	return 0;
}