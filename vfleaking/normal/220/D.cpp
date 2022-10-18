#include <iostream>
using namespace std;

typedef long long s64;

const s64 Mod = 1000000007;

int main()
{
	const int MaxW = 4000;
	const int MaxH = 4000;

	s64 w, h;

	cin >> w >> h;
	
	s64 nAll = (w + 1) * (h + 1);

	s64 n00 = ((w + 2) >> 1) * ((h + 2) >> 1);
	s64 n01 = ((w + 2) >> 1) * ((h + 1) >> 1);
	s64 n10 = ((w + 1) >> 1) * ((h + 2) >> 1);
	s64 n11 = ((w + 1) >> 1) * ((h + 1) >> 1);

	s64 res = 0;
	res = (res + n00 * (n00 - 1) % Mod * (nAll - 2)) % Mod;
	res = (res + n00 * n01 % Mod * (n00 + n01 - 2) * 2) % Mod;
	res = (res + n00 * n10 % Mod * (n00 + n10 - 2) * 2) % Mod;
	res = (res + n00 * n11 % Mod * (n00 + n11 - 2) * 2) % Mod;
	res = (res + n01 * (n01 - 1) % Mod * (nAll - 2)) % Mod;
	res = (res + n01 * n10 % Mod * (n01 + n10 - 2) * 2) % Mod;
	res = (res + n01 * n11 % Mod * (n01 + n11 - 2) * 2) % Mod;
	res = (res + n10 * (n10 - 1) % Mod * (nAll - 2)) % Mod;
	res = (res + n10 * n11 % Mod * (n10 + n11 - 2) * 2) % Mod;
	res = (res + n11 * (n11 - 1) % Mod * (nAll - 2)) % Mod;

	static int g[MaxW + 1][MaxH + 1];
	for (int i = 0; i <= max(w, h); i++)
		for (int j = 0; j <= max(w, h); j++)
		{
			if (i == 0)
				g[i][j] = j;
			else if (j == 0)
				g[i][j] = i;
			else if (i > j)
				g[i][j] = g[j][i - j];
			else
				g[i][j] = g[i][j - i];
		}

	if (w >= 2)
	{
		res -= (w + 1) * w % Mod * (w - 1) % Mod * (h + 1) % Mod;
		if (res < 0)
			res += Mod;
	}
	if (h >= 2)
	{
		res -= (h + 1) * h % Mod * (h - 1) % Mod * (w + 1) % Mod;
		if (res < 0)
			res += Mod;
	}

	for (int i = 1; i <= w; i++)
		for (int j = 1; j <= h; j++)
		{
			res -= ((g[i][j] - 1) * (w - i + 1) * (h - j + 1) * 12) % Mod;
			if (res < 0)
				res += Mod;
		}

	cout << res << endl;
	
	return 0;
}