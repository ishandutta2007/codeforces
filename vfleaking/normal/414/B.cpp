#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 2000;
const int MaxL = 2000;

const int Mod = 1000000007;

int main()
{
	int n, l;
	cin >> n >> l;

	static int f[MaxL + 1][MaxN + 1];
	f[0][1] = 1;

	for (int i = 0; i < l; i++)
		for (int a = 1; a <= n; a++)
			for (int b = a; b <= n; b += a)
				f[i + 1][b] += f[i][a], f[i + 1][b] %= Mod;

	int res = 0;
	for (int a = 1; a <= n; a++)
		res += f[l][a], res %= Mod;
	cout << res << endl;

	return 0;
}