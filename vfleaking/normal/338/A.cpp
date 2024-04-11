#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

// mod
const int Mod = 1000000009;

inline int modinv(const int &a)
{
	int x1 = 1, x2 = 0, x3 = Mod;
	int y1 = 0, y2 = 1, y3 = a;
    while (y3 != 1)
    {
        int k = x3 / y3;
        x1 -= y1 * k, x2 -= y2 * k, x3 -= y3 * k;
        swap(x1, y1), swap(x2, y2), swap(x3, y3);
    }
	return y2 >= 0 ? y2 : y2 + Mod;
}
inline int modadd(const int &a, const int &b)
{
	int res = a + b;
	return res >= Mod ? res - Mod : res;
}
inline int modsub(const int &a, const int &b)
{
	int res = a - b;
	return res < 0 ? res + Mod : res;
}
inline int modmul(const int &a, const int &b)
{
	return (s64)a * b % Mod;
}
inline int moddiv(const int &a, const int &b)
{
	return modmul(a, modinv(b));
}

inline int& modaddto(int &a, const int &b)
{
	a += b;
	if (a >= Mod)
		a -= Mod;
	return a;
}
inline int& modsubto(int &a, const int &b)
{
	a -= b;
	if (a < 0)
		a += Mod;
	return a;
}
inline int& modmulto(int &a, const int &b)
{
	a = modmul(a, b);
	return a;
}
inline int& moddivto(int &a, const int &b)
{
	a = moddiv(a, b);
	return a;
}

inline int modpow(const int &a, const int &n)
{
	int res = 1;
	int t = a;
	for (int i = n; i > 0; i >>= 1)
	{
		if (i & 1)
			modmulto(res, t);
		modmulto(t, t);
	}
	return res;
}

int main()
{
	int n, m, k;

	cin >> n >> m >> k;

	int rest = m - (n - n / k);
	if (rest < 0)
		rest = 0;

	int res = modmul(modmul(2, k), modsub(modpow(2, rest), 1));
	modaddto(res, m - rest * k);
	cout << res << endl;

	return 0;
}