#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int NLetter = 26;

const int MaxN = 2000;
const int MaxM = 2000;

const int Mod = 1000000007;

int main()
{
	int n, m;
	static char s[1 + MaxN + 1];

	cin >> n >> m;
	scanf("%s", s + 1);

	static int f[MaxN + 1][MaxM + 1];
	static int sumF[MaxM + 1];

	f[0][0] = 1, sumF[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int k = 0; k <= m; k++)
		{
			int cntL = s[i] - 'a';
			int cntR = NLetter - cntL - 1;

			f[i][k] = (s64)sumF[k] * cntL % Mod;
			for (int j = i - 1; j >= 0 && (i - j) * (n - i + 1) <= k; j--)
				f[i][k] = (f[i][k] + (s64)f[j][k - (i - j) * (n - i + 1)] * cntR % Mod) % Mod;

			sumF[k] = (sumF[k] + f[i][k]) % Mod;
		}

	cout << sumF[m] << endl;

	return 0;
}