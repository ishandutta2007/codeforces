#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int M = 1000000007;

const int MaxM = 1000000;

int main()
{
	int n = 0, m = 0;

	int a_n;
	cin >> a_n;
	for (int i = 0; i < a_n; i++)
	{
		int v;
		scanf("%d", &v);
		if (v == 2)
			n++;
		else
			m++;
	}

	static int g[MaxM + 1];
	g[0] = g[1] = 1;
	for (int i = 2; i <= m; i++)
		g[i] = (g[i - 1] + (s64)g[i - 2] * (i - 1)) % M;

	int res = g[m];
	for (int i = 0; i < n; i++)
		res = (s64)res * (n + m - i) % M;

	cout << res << endl;

	return 0;
}