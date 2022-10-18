#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 20;
const int MaxM = 20;

int main()
{
	int n, m;
	cin >> n >> m;

	static bool f[MaxN * MaxM][MaxN * MaxM];
	for (int v = 0; v < n * m; v++)
		f[v][v] = true;

	for (int i = 0; i < n; i++)
	{
		char d;
		cin >> d;
		if (d == '<')
		{
			for (int j = 1; j < m; j++)
				f[i * m + j][i * m + j - 1] = true;
		}
		else
		{
			for (int j = 0; j < m - 1; j++)
				f[i * m + j][i * m + j + 1] = true;
		}
	}
	for (int j = 0; j < m; j++)
	{
		char d;
		cin >> d;
		if (d == '^')
		{
			for (int i = 1; i < n; i++)
				f[i * m + j][(i - 1) * m + j] = true;
		}
		else
		{
			for (int i = 0; i < n - 1; i++)
				f[i * m + j][(i + 1) * m + j] = true;
		}
	}

	int all = n * m;
	for (int k = 0; k < all; k++)
		for (int i = 0; i < all; i++)
			if (f[i][k])
				for (int j = 0; j < all; j++)
					f[i][j] = f[i][j] || (f[i][k] && f[k][j]);

	bool ok = true;
	for (int i = 0; i < all; i++)
		for (int j = 0; j < all; j++)
			if (!f[i][j])
				ok = false;
	if (ok)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}