#include <iostream>
#include <algorithm>
using namespace std;

typedef long long s64;

const int Mod = 1000000007;

const int NDigit = 10;

int f[NDigit][10][NDigit + 2];
inline void initF()
{
	for (int j = 0; j < 10; j++)
		f[0][j][j == 4 || j == 7] = 1;
	for (int i = 1; i < NDigit; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k <= NDigit; k++)
				for (int p = 0; p < 10; p++)
					f[i][j][k + (j == 4 || j == 7)] += f[i - 1][p][k];
}
inline void query(int n, int *res)
{
	n++;
	
	int len = 0;
	static int a[NDigit + 1];
	while (n > 0)
		a[len++] = n % 10, n /= 10;

	fill(res, res + NDigit + 1, 0);
	int cnt = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		for (int j = 0; j < a[i]; j++)
			for (int k = 0; k + cnt <= NDigit; k++)
				res[k + cnt] += f[i][j][k];
		cnt += a[i] == 4 || a[i] == 7;
	}
	res[0]--;
}

inline s64 comb(const int &n, const int &m)
{
	if (m > n)
		return 0;

	s64 t = 1;
	for (int i = 1; i <= m; i++)
		t *= i;
	s64 a = 0ll, b = 0ll;
	b += 1;
	a += b / t, a %= Mod, b %= t;
	for (int i = 0; i < m; i++)
	{
		a *= n - i, b *= n - i;
		a += b / t, a %= Mod, b %= t;
	}

	return a;
}

int main()
{
	int n;
	cin >> n;

	static int g[NDigit + 1];
	initF();
	query(n, g);

	static s64 h[NDigit + 1][7][NDigit + 1];
	for (int i = 0; i <= 6; i++)
		for (int j = 0; j <= NDigit; j++)
			h[0][i][j] = comb(g[0], i);
	for (int i = 1; i <= NDigit; i++)
		for (int j = 0; j <= 6; j++)
			for (int k = 0; k <= NDigit; k++)
				for (int p = 0; p <= j && p * i <= k; p++)
					h[i][j][k] = (h[i][j][k] + h[i - 1][j - p][k - p * i] * comb(g[i], p)) % Mod;

	s64 res = 0ll;
	for (int i = 1; i <= NDigit; i++)
		res = (res + g[i] * h[i - 1][6][i - 1] % Mod) % Mod;

	res *= 720;
	res %= Mod;

	cout << res << endl;

	return 0;
}