#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int M = 1000000009;

const int MaxN = 4000;

int main()
{
	int n, w, b;
	cin >> n >> w >> b;

	static int fact[MaxN + 1];
	static int comb[MaxN + 1][MaxN + 1];

	fact[0] = 1;
	for (int i = 1; i <= MaxN; i++)
		fact[i] = (s64)fact[i - 1] * i % M;
	for (int i = 0; i <= MaxN; i++)
		for (int j = 0; j <= i; j++)
			comb[i][j] = j == 0 ? 1 : (comb[i - 1][j] + comb[i - 1][j - 1]) % M;

	int res = 0;
	for (int i = 1; i <= n - 2; i++)
		for (int j = i + 1; j <= n - 1; j++)
			res = (res + (s64)fact[w] * fact[b] % M * comb[w - 1][i + n - j - 1] % M * comb[b - 1][j - i - 1] % M) % M;

	cout << res << endl;

	return 0;
}