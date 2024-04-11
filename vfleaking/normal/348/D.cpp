#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int Mod = 1000000007;

const int MaxN = 3000;
const int MaxM = 3000;

int n, m;
char a[MaxN + 1][MaxM + 2];
int f[MaxN + 1][MaxM + 1];

inline int &modaddto(int &lhs, const int &rhs)
{
	lhs += rhs;
	if (lhs >= Mod)
		lhs -= Mod;
	return lhs;
}

inline int calc(const int &x1, const int &y1, const int &x2, const int &y2)
{
	if (x1 > x2 || y1 > y2)
		return 0;
	for (int x = x1; x <= x2; x++)
		for (int y = y1; y <= y2; y++)
		{
			if (a[x][y] == '#')
				f[x][y] = 0;
			else if (x == x1 && y == y1)
				f[x][y] = 1;
			else
			{
				f[x][y] = 0;
				if (x - 1 >= x1)
					modaddto(f[x][y], f[x - 1][y]);
				if (y - 1 >= y1)
					modaddto(f[x][y], f[x][y - 1]);
			}
		}
	return f[x2][y2];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%s", a[i] + 1);

	int part1 = (s64)calc(1, 2, n - 1, m) * calc(2, 1, n, m - 1) % Mod;
	int part2 = (s64)calc(1, 2, n, m - 1) * calc(2, 1, n - 1, m) % Mod;
	cout << (part1 - part2 + Mod) % Mod << endl;

	return 0;
}