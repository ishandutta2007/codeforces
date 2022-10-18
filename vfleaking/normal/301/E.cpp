#include <iostream>
#include <cstdio>
using namespace std;

const int Mod = 1000000007;

const int MaxN = 100;
const int MaxM = 100;
const int MaxLM = 100;

inline int &modaddto(int &a, const int &b)
{
	a += b;
	if (a >= Mod)
		a -= Mod;
	return a;
}

int main()
{
	int n, m, lm;
	cin >> n >> m >> lm;

	static int f[2][MaxN + 1][MaxN + 1][MaxLM + 1];

	static int comb[MaxN + 1][MaxN + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= i; j++)
			comb[i][j] = j == 0 ? 1 : min(comb[i - 1][j] + comb[i - 1][j - 1], lm + 1);

	int res = 0;

	for (int v = 0; v < m; v++)
	{
		int cur = v & 1, nxt = 1 - cur;
		for (int k = 1; k <= n; k++)
			modaddto(f[nxt][k][k][1], 1);
		for (int i = 0; i <= n; i++)
			for (int g = 1; i + g <= n; g++)
				for (int l = 1; l <= lm; l++)
					if (f[cur][i][g][l] != 0)
					{
						modaddto(res, f[cur][i][g][l]);
						for (int k = g + 1; i + k <= n; k++)
						{
							int co = comb[k - 1][g - 1];
							if (l * co > lm)
								break;
							modaddto(f[nxt][i + k][k - g][l * co], f[cur][i][g][l]);
						}
						f[cur][i][g][l] = 0;
					}
	}

	cout << res << endl;

	return 0;
}