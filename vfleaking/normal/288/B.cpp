#include <iostream>
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

inline int modpow(const int &a, int b)
{
	int t = a;
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			modmultto(res, t);
		modmultto(t, t);
		b >>= 1;
	}
	return res;
}

int dfs_res = 0;
int k;
int p[8 + 1];

inline bool check()
{
	int book;

	book = 0;
	int v = p[1];
	while (v != 1)
	{
		book |= 1 << v;
		v = p[v];

		if (book & 1 << v)
			return false;
	}

	for (int i = 2; i <= k; i++)
	{
		book = 0;

		int u = p[i];
		while (u != 1)
		{
			book |= 1 << u;
			u = p[u];

			if (book & 1 << u)
				return false;
		}
	}
	return true;
}

void dfs(const int &cur)
{
	if (cur == k + 1)
	{
		if (check())
			dfs_res++;
		return;
	}

	for (int i = 1; i <= k; i++)
	{
		p[cur] = i;
		dfs(cur + 1);
	}
}

int main()
{
	int n;
	cin >> n >> k;

	int rest = modpow(n - k, n - k);

	dfs(1);

	cout << modmult(rest, dfs_res) << endl;

	return 0;
}