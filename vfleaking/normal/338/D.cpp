#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxAN = 10000;

inline s64 modmul(s64 a, s64 b, s64 m)
{
	s64 res = 0;
	s64 t = a;
	for (s64 i = b; i > 0; i >>= 1)
	{
		if (i & 1)
			res = (res + t) % m;
		t = (t + t) % m;
	}
	return res;
}
inline s64 modrev(s64 a, s64 m)
{
	s64 x1 = 1, x2 = 0, x3 = a % m;
	s64 y1 = 0, y2 = 1, y3 = m;
	while (y3 != 1)
	{
		s64 k = x3 / y3;
		x1 -= k * y1, x2 -= k * y2, x3 -= k * y3;
		swap(x1, y1), swap(x2, y2), swap(x3, y3);
	}
	return y1 >= 0 ? y1 : y1 + m;
}

s64 gcd(s64 a, s64 b)
{
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

bool handle()
{
	s64 n, m;
	int a_n;
	static s64 a[MaxAN];

	cin >> n >> m >> a_n;
	for (int i = 0; i < a_n; i++)
		cin >> a[i];

	s64 x0 = 1, y0 = 0;
	for (int i = 0; i < a_n; i++)
	{
		s64 g = gcd(x0, a[i]);
		s64 t = (a[i] - i % a[i]) % a[i];
		if (y0 % g != t % g)
			return false;

		s64 m1 = x0 / g, m2 = a[i] / g;
		if (x0 > n / m2)
			return false;
		y0 = (m2 * modmul(y0 / g, modrev(m2, m1), m1) + m1 * modmul(t / g, modrev(m1, m2), m2)) % (m1 * m2) * g + y0 % g;
		x0 *= m2;
	}
	if (y0 == 0)
		y0 += x0;
	if (y0 + a_n - 1 > m)
		return false;

	for (int i = 0; i < a_n; i++)
		if (gcd(x0, y0 + i) != a[i])
			return false;
	return true;
}

int main()
{
	if (handle())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}