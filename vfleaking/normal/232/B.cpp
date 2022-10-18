#include <iostream>
using namespace std;

typedef long long s64;

const int MaxN = 100;
const int MaxK = MaxN * MaxN;

// mod operator
const int Mod = 1000000007;
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

inline s64 qpow(const int &a, const s64 &n)
{
	s64 t = a;
	s64 res = 1ll;
	for (int i = 0; i < 62; i++)
	{
		if (n & 1ll << i)
			res = res * t % Mod;
		t = t * t % Mod;
	}
	return res;
}

int main()
{
	int n, k;
	s64 m;
	
	cin >> n >> m >> k;

	static int comb[MaxN + 1][MaxN + 1];
	comb[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++)
			comb[i][j] = modplus(comb[i - 1][j - 1], comb[i - 1][j]);
	}

	static int f[MaxN + 1][MaxK + 1];
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		s64 t = (m - i) / n + 1;
		
		static s64 powValue[MaxN + 1];
		for (int p = 0; p <= n; p++)
			powValue[p] = qpow(comb[n][p], t);
		
		for (int j = 0; j <= k; j++)
		{
			f[i][j] = 0;
			for (int p = 0; p <= n && p <= j; p++)
				f[i][j] = modplus(f[i][j], powValue[p] * f[i - 1][j - p] % Mod);
		}
	}

	cout << f[n][k] << endl;

	return 0;
}