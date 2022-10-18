#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

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

const int MaxN = 100000;
const int MaxK = 100;

int main()
{
	int n, m;
	static int a[MaxN + 1];

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	static int comb[MaxN + MaxK + 1][MaxK + 1];
	for (int i = 0; i <= MaxN + MaxK; i++)
	{
		comb[i][0] = 1;
		for (int j = 1; j <= MaxK && j <= i; j++)
			comb[i][j] = modadd(comb[i - 1][j], comb[i - 1][j - 1]);
	}

	static int b[MaxK + 2][MaxN + 1];

	for (int i = 0; i < m; i++)
	{
		int l, r, cK;
		scanf("%d %d %d", &l, &r, &cK);

		modaddto(b[cK + 1][l], 1);
		for (int j = 0; j <= cK && r + 1 + j <= n; j++)
			modsubto(b[j + 1][r + 1 + j], comb[r + 1 - l + cK][cK - j]);
	}

	static int rb[MaxN + 1];
	for (int k = MaxK + 1; k >= 1; k--)
	{
		for (int i = 1; i <= n; i++)
			modaddto(rb[i], b[k][i]);
		for (int i = 1; i <= n; i++)
			modaddto(rb[i], rb[i - 1]);
	}
	for (int i = 1; i <= n; i++)
		modaddto(a[i], rb[i]);

	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}