#include <iostream>
#include <cstdio>
using namespace std;

const int M = 1000000007;
const int MaxN = 10000;

inline int &modaddto(int &a, const int &b)
{
	return a = (a + b) % M;
}

inline int staget(int sta, int p)
{
	return sta >> p & 1;
}
inline int staset(int sta, int p, int v)
{
	return (sta & ~(1 << p)) | v << p;
}

int n;
char a[3][MaxN + 1];

char aget(int i, int j)
{
	if (0 <= i && i < 3 && 0 <= j && j < n)
		return a[i][j];
	return 'X';
}

int main()
{
	cin >> n;
	for (int i = 0; i < 3; i++)
		cin >> a[i];

	static int f[4][MaxN][1 << 3][2];
	f[0][0][7][0] = 1;
	for (int j = 0; j < n; j++)
	{
		if (j > 0)
		{
			for (int sta = 0; sta < (1 << 3); sta++)
				for (int b = 0; b < 2; b++)
					modaddto(f[0][j][sta][b], f[3][j - 1][sta][b]);
		}
		for (int i = 0; i < 3; i++)
			for (int sta = 0; sta < (1 << 3); sta++)
				for (int b = 0; b < 2; b++)
				{
					int cur = f[i][j][sta][b];
					if (cur == 0)
						continue;
					if (aget(i, j) == '.')
					{
						if (aget(i - 1, j) == '.' && staget(sta, i - 1) == 0 && staget(sta, i) == 1)
							modaddto(f[i + 1][j][staset(staset(sta, i - 1, 1), i, 1)][b || aget(i - 2, j) == 'O' || aget(i + 1, j) == 'O'], cur);
						if (aget(i, j - 1) == '.' && staget(sta, i) == 0)
							modaddto(f[i + 1][j][staset(sta, i, 1)][b || aget(i, j - 2) == 'O' || aget(i, j + 1) == 'O'], cur);
					}
					if (staget(sta, i) == 1)
						modaddto(f[i + 1][j][staset(sta, i, aget(i, j) != '.')][b], cur);
				}
	}

	cout << f[3][n - 1][7][1] << endl;

	return 0;
}