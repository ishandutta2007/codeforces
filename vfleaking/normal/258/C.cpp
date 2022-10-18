#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

// mod
const int Mod = 1000000007;

inline int modinv(const int &a)
{
	int x1 = 1, x2 = 0, x3 = Mod;
	int y1 = 0, y2 = 1, y3 = a;
	while (y3 != 0)
	{
		int k = x3 / y3;
		int t1 = x1 - y1 * k, t2 = x2 - y2 * k, t3 = x3 - y3 * k;
		x1 = y1, x2 = y2, x3 = y3;
		y1 = t1, y2 = t2, y3 = t3;
	}
	if (x3 != 1)
		return -1;
	return x2 >= 0 ? x2 : x2 + Mod;
}
inline int modplus(const int &a, const int &b)
{
	int res = a + b;
	return res >= Mod ? res - Mod : res;
}
inline int modminus(const int &a, const int &b)
{
	int res = a - b;
	return res < 0 ? res + Mod : res;
}
inline int modmult(const int &a, const int &b)
{
	return (s64)a * b % Mod;
}
inline int moddiv(const int &a, const int &b)
{
	return modmult(a, modinv(b));
}


inline int& modplusto(int &a, const int &b)
{
	a += b;
	if (a >= Mod)
		a -= Mod;
	return a;
}
inline int& modminusto(int &a, const int &b)
{
	a -= b;
	if (a < 0)
		a += Mod;
	return a;
}
inline int& modmultto(int &a, const int &b)
{
	a = modmult(a, b);
	return a;
}
inline int& moddiv(int &a, const int &b)
{
	a = moddiv(a, b);
	return a;
}

inline int qpow(const int &a, const int &n)
{
	int t = a;
	int res = 1ll;
	for (int i = 0; i < 31; i++)
	{
		if (n & 1 << i)
			modmultto(res, t);
		modmultto(t, t);
	}
	return res;
}

int main()
{
	int n;
	static int a[MaxN + 1];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);

	int res = 0;
	for (int lcm = 1; lcm <= a[n - 1]; lcm++)
	{
		int len = 0;
		static int d[1000];
		for (int i = 1; i * i <= lcm; i++)
			if (lcm % i == 0)
				d[len++] = i;
		for (int i = len - 1; i >= 0; i--)
			if (d[i] * d[i] != lcm)
				d[len++] = lcm / d[i];

		static int pos[1000];
		for (int i = 0; i < len; i++)
			pos[i] = lower_bound(a, a + n, d[i]) - a;

		int cur = 1;
		for (int i = 0; i < len - 1; i++)
			modmultto(cur, qpow(i + 1, pos[i + 1] - pos[i]));
		modmultto(cur, modminus(qpow(len, n - pos[len - 1]), qpow(len - 1, n - pos[len - 1])));
		modplusto(res, cur);
	}
	cout << res << endl;

	return 0;
}