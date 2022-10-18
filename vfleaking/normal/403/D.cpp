#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxN = 1000;
const int MaxL = 1000;

const int Mod = 1000000007;

int comb[MaxN + 1][MaxL + 1];
int f[MaxL + 1][MaxN + 1];

void init()
{
	for (int i = 0; i <= MaxN; i++)
	{
		comb[i][0] = 1;
		for (int j = 1; j <= i && j <= MaxL; j++)
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % Mod;
	}

	f[0][0] = 1;
	for (int l = 1; l <= MaxL; l++)
		for (int s = 0; s <= MaxN; s++)
		{
			f[l][s] = 0;
			for (int val = 0; val + (val + 1) * (l - 1) <= s; val++)
				f[l][s] = (f[l][s] + f[l - 1][s - val - (val + 1) * (l - 1)]) % Mod;
			f[l][s] = (s64)f[l][s] * l % Mod;
		}
}
int query(int n, int l)
{
	int res = 0;
	for (int s = 0; s <= n; s++)
		res = (res + (s64)f[l][s] * comb[n - s][l]) % Mod;
	return res;
}

int main()
{
	init();

	int nCases;
	cin >> nCases;
	while (nCases--)
	{
		int n, l;
		scanf("%d %d", &n, &l);
		printf("%d\n", query(n, l));
	}

	return 0;
}