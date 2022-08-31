#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 10;
int n;
int l[N][N], r[N][N], a[N][N];
int ans1 = -1, ans2 = -1;
int bal[N];

void relaxAns(int x, int y)
{
	if (ans1 == -1)
	{
		ans1 = x;
		ans2 = y;
		return;
	}
	if (x > ans1) return;
	if (x == ans1 && y <= ans2) return;
	ans1 = x;
	ans2 = y;
	return;
}

void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n * (n - 1) / 2; i++)
	{
		int x, y, L, R, A;
		scanf("%d%d%d%d%d", &x, &y, &L, &R, &A);
		x--;
		y--;
		l[x][y] = L;
		r[x][y] = R;
		a[x][y] = A;
	}
	return;
}

void brute(int x, int y, int fl, int cost)
{
	if (x == 0 && y == n - 1)
	{
		x = 1;
		y = 2;
	}
	if (y == n)
	{
		x++;
		y = x + 1;
	}
	if (x >= n - 1)
	{
		relaxAns(fl, cost);
		return;
	}
	for (int f = l[x][y]; f <= r[x][y]; f++)
	{
		if (x != 0 && bal[x] < f) break;
		if (y == n - 1 && bal[x] != f) continue;
		bal[x] -= f;
		bal[y] += f;
		brute(x, y + 1, fl + (x == 0 ? f : 0), cost + f * f + (f == 0 ? 0 : a[x][y]));
		bal[y] -= f;
		bal[x] += f;
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	if (l[0][n - 1] == 0)
		brute(0, 1, 0, 0);
	else
		brute(0, 1, l[0][n - 1], a[0][n - 1] + l[0][n - 1] * l[0][n - 1]);
	printf("%d %d\n", ans1, ans2);

	return 0;
}