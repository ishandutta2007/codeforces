#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int M = 1000000007;

const int MaxN = 2000;
const int MaxM = 2000;

int main()
{
	int n, m;
	static int f[MaxN + 1][MaxM + 1];

	cin >> n >> m;

	for (int j = 2; j <= m; j++)
		f[1][j] = 1;
	for (int i = 2; i <= n; i++)
	{
		int sum = 0;
		for (int j = 2; j <= m; j++)
		{
			sum = (sum + f[i - 1][j]) % M;
			f[i][j] = (f[i][j - 1] + sum) % M;
		}
	}

	static int g[MaxN + 1][MaxM + 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			g[i][j] = (f[i][j] + g[i - 1][j]) % M;

	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= m; j++)
			res = (res + (s64)(m - j + 1) * g[i][j] % M * (g[n - i + 1][j] + M - g[n - i][j])) % M;

	cout << res << endl;

	return 0;
}