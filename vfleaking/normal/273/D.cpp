#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxN = 150;
const int MaxM = 150;

// mod
const int Mod = 1000000007;

inline int modinv(const int &a)
{
	int x1 = 1, x2 = 0, x3 = Mod;
	int y1 = 0, y2 = 1, y3 = a;
	while (y3 != 1)
	{
		int k = x3 / y3;
		int t1 = y1 - x1 * k, t2 = y2 - x2 * k, t3 = y3 - x3 * k;
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
inline int& moddiv(int &a, const int &b)
{
	a = moddiv(a, b);
	return a;
}

int n, m;

int cur, before;
int f[2][2][2][MaxM + 1][MaxM + 1];

int querySumBefore(const int &typeL, const int &typeR, const int &ll, const int &lr, const int &rl, const int &rr)
{
	if (ll > lr || rl > rr)
		return 0;

	int res = 0;
	modplusto(res, f[before][typeL][typeR][lr][rr]);
	modminusto(res, f[before][typeL][typeR][ll - 1][rr]);
	modminusto(res, f[before][typeL][typeR][lr][rl - 1]);
	modplusto(res, f[before][typeL][typeR][ll - 1][rl - 1]);
	return res;
}

int main()
{
	cin >> n >> m;

	cur = 0, before = 1;

	int res = 0;

	for (int x = 1; x <= n; x++, swap(cur, before))
	{
		for (int yl = 1; yl <= m; yl++)
			for (int yr = 1; yr <= m; yr++)
			{
				f[cur][0][0][yl][yr] = modplus(1, querySumBefore(0, 0, yl, yr, yl, yr));
				f[cur][0][1][yl][yr] = modplus(querySumBefore(0, 0, yl, yr, yr + 1, m), querySumBefore(0, 1, yl, yr, yr, m));
				f[cur][1][0][yl][yr] = modplus(querySumBefore(0, 0, 1, yl - 1, yl, yr), querySumBefore(1, 0, 1, yl, yl, yr));

				f[cur][1][1][yl][yr] = 0;
				modplusto(f[cur][1][1][yl][yr], querySumBefore(0, 0, 1, yl - 1, yr + 1, m));
				modplusto(f[cur][1][1][yl][yr], querySumBefore(0, 1, 1, yl - 1, yr, m));
				modplusto(f[cur][1][1][yl][yr], querySumBefore(1, 0, 1, yl, yr + 1, m));
				modplusto(f[cur][1][1][yl][yr], querySumBefore(1, 1, 1, yl, yr, m));
			}
		
		for (int yl = 1; yl <= m; yl++)
			for (int yr = 1; yr <= m; yr++)
				for (int typeL = 0; typeL <= 1; typeL++)
					for (int typeR = 0; typeR <= 1; typeR++)
					{
						if (yl > yr)
							f[cur][typeL][typeR][yl][yr] = 0;
						modplusto(res, f[cur][typeL][typeR][yl][yr]);
						modplusto(f[cur][typeL][typeR][yl][yr], f[cur][typeL][typeR][yl - 1][yr]);
						modplusto(f[cur][typeL][typeR][yl][yr], f[cur][typeL][typeR][yl][yr - 1]);
						modminusto(f[cur][typeL][typeR][yl][yr], f[cur][typeL][typeR][yl - 1][yr - 1]);
					}
	}

	cout << res << endl;

	return 0;
}