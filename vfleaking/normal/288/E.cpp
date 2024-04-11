#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

// mod
const int Mod = 1000000007;

inline int modinv(const int &a)
{
	int x1 = 1, x2 = 0, x3 = Mod;
	int y1 = 0, y2 = 1, y3 = a;
    while (y3 != 1)
    {
        int k = x3 / y3;
        int t1 = x1 - y1 * k, t2 = x2 - y2 * k, t3 = x3 - y3 * k;
        x1 = y1, x2 = y2, x3 = y3;
        y1 = t1, y2 = t2, y3 = t3;
    }

	return y2 >= 0 ? y2 : y2 + Mod;
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
inline int& moddivto(int &a, const int &b)
{
	a = moddiv(a, b);
	return a;
}

struct modint
{
	int a;

	modint(){}
	modint(const int &_a)
		: a(_a){}

	friend inline modint operator+(const modint &lhs, const modint &rhs)
	{
		return modplus(lhs.a, rhs.a);
	}
	friend inline modint operator-(const modint &lhs, const modint &rhs)
	{
		return modminus(lhs.a, rhs.a);
	}
	friend inline modint operator*(const modint &lhs, const modint &rhs)
	{
		return modmult(lhs.a, rhs.a);
	}

	inline modint &operator+=(const modint &rhs)
	{
		modplusto(a, rhs.a);
		return *this;
	}
};

modint f[MaxN + 1];
modint g[MaxN + 1];
modint cnt[MaxN + 1];

modint full_f[MaxN + 1];
modint full_g[MaxN + 1];
modint full_cnt[MaxN + 1];

modint pow10[MaxN + 1];
modint all1[MaxN + 1];

inline int handle(const char *s)
{
	int n = strlen(s);

	f[0] = 0;
	g[0] = 0;
	cnt[0] = 1;

	full_f[0] = 0;
	full_g[0] = 0;
	full_cnt[0] = 1;

	pow10[0] = 1;
	all1[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		modint t1 = 4 * pow10[i - 1] + 7 * all1[i - 1];
		modint t2 = 7 * pow10[i - 1] + 4 * all1[i - 1];

		int num = s[n - i] - '0';
		f[i] = num * num * pow10[i - 1] * pow10[i - 1] * (cnt[i - 1] - 1) + num * pow10[i - 1] * g[i - 1] + f[i - 1];
		g[i] = num * (cnt[i - 1] * 2 - 2) * pow10[i - 1] + g[i - 1];
		cnt[i] = cnt[i - 1];
		
		full_f[i] = 0;
		full_f[i] += 4 * 4 * pow10[i - 1] * pow10[i - 1] * (full_cnt[i - 1] - 1) + 4 * pow10[i - 1] * full_g[i - 1] + full_f[i - 1];
		full_f[i] += 7 * 7 * pow10[i - 1] * pow10[i - 1] * (full_cnt[i - 1] - 1) + 7 * pow10[i - 1] * full_g[i - 1] + full_f[i - 1];
		full_g[i] = 0;
		full_g[i] += 4 * (full_cnt[i - 1] * 2 - 2) * pow10[i - 1] + full_g[i - 1];
		full_g[i] += 7 * (full_cnt[i - 1] * 2 - 2) * pow10[i - 1] + full_g[i - 1];
		full_f[i] += t1 * t2;
		full_g[i] += t1 + t2;
		full_cnt[i] = full_cnt[i - 1] * 2;

		pow10[i] = pow10[i - 1] * 10;
		all1[i] = all1[i - 1] * 10 + 1;

		if (num == 7)
		{
			f[i] += 4 * 4 * pow10[i - 1] * pow10[i - 1] * (full_cnt[i - 1] - 1) + 4 * pow10[i - 1] * full_g[i - 1] + full_f[i - 1];
			g[i] += 4 * (full_cnt[i - 1] * 2 - 2) * pow10[i - 1] + full_g[i - 1];
			cnt[i] += full_cnt[i - 1];

			f[i] += t1 * t2;
			g[i] += t1 + t2;
		}
	}

	return f[n].a;
}

int main()
{
	static char ls[MaxN + 1];
	static char rs[MaxN + 1];

	cin >> ls >> rs;

	cout << modminus(handle(rs), handle(ls)) << endl;

	return 0;
}