#include <iostream>
#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int, int> PII;

const int NDir = 4;
const int DirX[] = {-1, 0, 0, 1};
const int DirY[] = {0, -1, 1, 0};

const int MaxN = 500;
const int MaxM = 500;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

int main()
{
	int n, m, nP;
	static char a[1 + MaxN + 1][MaxM + 2];

	cin >> n >> m >> nP;
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			a[i][j] = '#';
	for (int i = 1; i <= n; i++)
		scanf("%s", a[i] + 1), a[i][m + 1] = '#';

	int sx, sy;
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			if (a[x][y] == '.')
				sx = x, sy = y;

	static bool book[MaxN + 1][MaxM + 1];
	int top, bot;
	static PII q[MaxN * MaxM];

	top = bot = 0;

	book[sx][sy] = true, q[bot++] = PII(sx, sy);
	while (top != bot)
	{
		PII v = q[top++];

		for (int d = 0; d < NDir; d++)
		{
			int ux = v.first + DirX[d], uy = v.second + DirY[d];
			if (a[ux][uy] == '.' && !book[ux][uy])
				book[ux][uy] = true, q[bot++] = PII(ux, uy);
		}
	}

	for (int i = 1; i <= nP; i++)
		a[q[bot - i].first][q[bot - i].second] = 'X';

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}

	return 0;
}