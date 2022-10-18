#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 300;
const int MaxTot = 100000;

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

int n;
int a[MaxN + 1];
int tot;

int next[MaxN + 1];
bool linked[MaxN + 1];

bool book[MaxN + 1];

int outcome[MaxTot + 1];

inline void handle(const int &start)
{
	int li_n = 0;
	static int li[MaxN];

	for (int i = start; i; i = next[i])
	{
		li[li_n++] = i;
		book[i] = true;
	}

	static int li_val[MaxN];
	li_val[0] = a[li[0]];
	for (int i = 1; i < li_n; i++)
		li_val[i] = li_val[i - 1] + a[li[i]];

	for (int j = li_val[li_n - 1]; j <= tot; j++)
		modplusto(outcome[j], outcome[j - li_val[li_n - 1]]);

	s64 sum = 0;
	for (int i = 0; i < li_n - 1; i++)
		sum += li_val[i];
	if (sum > tot)
	{
		cout << 0 << endl;
		exit(0);
	}
	tot -= sum;
	for (int i = 0; i < li_n - 1; i++)
		for (int j = li_val[i]; j <= tot; j++)
			modplusto(outcome[j], outcome[j - li_val[i]]);
}

int main()
{
	int q;
	cin >> n >> q >> tot;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= q; i++)
	{
		int b, c;
		scanf("%d %d", &b, &c);
		next[b] = c;
		linked[c] = true;
	}

	outcome[0] = 1;
	for (int i = 1; i <= n; i++)
		if (!book[i] && !linked[i])
			handle(i);

	if (find(book + 1, book + n + 1, false) != book + n + 1)
		cout << 0 << endl;
	else
		cout << outcome[tot] << endl;

	return 0;
}