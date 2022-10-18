#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int MaxN = 1000;
const int MaxM = 1000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

int n, m;
char a[MaxN + 1][MaxM + 1];

int stX, stY;

bool findSt()
{
	for (stX = 0; stX < n; stX++)
		for (stY = 0; stY < m; stY++)
			if (a[stX][stY] == 'X')
				return true;
	return false;
}

bool check(int r, int c)
{
	static char b[MaxN + 1][MaxM + 1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			b[i][j] = '.';
	int x = stX, y = stY;
	if (stX + r > n)
		return false;
	if (stY + c > m)
		return false;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			b[stX + i][stY + j] = 'X';
	while (true)
	{
		if (x + r < n && a[x + r][y] == 'X')
		{
			for (int i = 0; i < c; i++)
				b[x + r][y + i] = 'X';
			x++;
			continue;
		}
		if (y + c < m && a[x][y + c] == 'X')
		{
			for (int i = 0; i < r; i++)
				b[x + i][y + c] = 'X';
			y++;
			continue;
		}
		break;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] != b[i][j])
				return false;
	return true;
}

int handle()
{
	findSt();
	int res = INT_MAX;

	int r, t, c;

	r = 0, t = 0, c = 0;
	for (int x = stX; x < n && a[x][stY] == 'X'; x++)
		r++;
	if (stX + r < n)
	{
		for (int y = stY; y < m && a[stX][y] == 'X'; y++)
			t++;
		for (int y = stY + t - 1; y >= stY && a[stX + r][y] == 'X'; y--)
			c++;
	}
	if (c == 0)
		c = 1;
	if (check(r, c))
		tension(res, r * c);

	r = 0, t = 0, c = 0;
	for (int y = stY; y < m && a[stX][y] == 'X'; y++)
		c++;
	if (stY + c < m)
	{
		for (int x = stX; x < n && a[x][stY] == 'X'; x++)
			t++;
		for (int x = stX + t - 1; x >= stX && a[x][stY + c] == 'X'; x--)
			r++;
	}
	if (r == 0)
		r = 1;
	if (check(r, c))
		tension(res, r * c);

	return res;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%s", a[i]);

	int res = handle();
	if (res == INT_MAX)
		res = -1;
	cout << res << endl;

	return 0;
}