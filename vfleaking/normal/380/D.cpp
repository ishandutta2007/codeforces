#include <iostream>
#include <cstdio>
#include <utility>
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

inline int modpow2(int n)
{
	int res = 1;
	int t = 2;
	for (int i = n; i >= 1; i >>= 1)
	{
		if (i & 1)
			modmulto(res, t);
		modmulto(t, t);
	}
	return res;
}
inline int modcomb(int n, int k)
{
	int res = 1;
	for (int i = 0; i < k; i++)
		modmulto(res, n - i);
	for (int i = 1; i <= k; i++)
		moddivto(res, i);
	return res;
}

int n;
int a[MaxN + 1];

int solve()
{
	int ap_n = 0;
	static pair<int, int> ap[MaxN];

	for (int i = 1; i <= n; i++)
		if (a[i] > 0)
			ap[ap_n++] = make_pair(a[i], i);
	sort(ap, ap + ap_n);

	if (ap_n == 0)
		return modpow2(n - 1);

	int res = 1;

	int le = 1, ri = n;
	while (ap_n >= 1)
	{
		int p = ap[ap_n - 1].second;
		if (ap_n == 1)
		{
			int cur = 0;
			if (a[p] == 1)
				modaddto(cur, modcomb(ri - le, p - le));
			else
			{
				if (p - le + 1 >= a[p])
					modaddto(cur, modmul(modpow2(a[p] - 2), modcomb(ri - le + 1 - a[p], p - le + 1 - a[p])));
				if (ri - p + 1 >= a[p])
					modaddto(cur, modmul(modpow2(a[p] - 2), modcomb(ri - le + 1 - a[p], ri - p + 1 - a[p])));
			}
			modmulto(res, cur);
		}
		else
		{
			int q = ap[ap_n - 2].second;
			if (q < p)
			{
				if (!(p - a[p] + 1 <= q && q < p))
					return 0;
				if (p - a[p] + 1 < le)
					return 0;
				modmulto(res, modcomb(ri - le + 1 - a[p], p - le + 1 - a[p]));
				le = p - a[p] + 1, ri = p - 1;
			}
			else
			{
				if (!(p < q && q <= p + a[p] - 1))
					return 0;
				if (p + a[p] - 1 > ri)
					return 0;
				modmulto(res, modcomb(ri - le + 1 - a[p], ri - p + 1 - a[p]));
				le = p + 1, ri = p + a[p] - 1;
			}
		}
		ap_n--;
	}
	return res;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	cout << solve() << endl;

	return 0;
}