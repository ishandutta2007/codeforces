#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005, p = 1e9 + 7;
int Sum1[Maxn][Maxn], Sum2[Maxn][Maxn], sum1[Maxn][Maxn], sum2[Maxn][Maxn], n, m, val[Maxn][Maxn];
int lowbit(int x)
{
	return x & -x;
}
void add1(int x, int y, int val)
{
	for (int i = x; i <= n; i += lowbit(i))
		(Sum1[i][y] += val) %= p;
}
void add2(int x, int y, int val)
{
	for (int i = y; i <= m; i += lowbit(i))
		(Sum2[x][i] += val) %= p;
}
int ask1(int x, int y)
{
	int tmp = 0;
	for (int i = x; i; i -= lowbit(i))
		(tmp += Sum1[i][y]) %= p;
	return tmp;
}
int ask2(int x, int y)
{
	int tmp = 0;
	for (int i = y; i; i -= lowbit(i))
		(tmp += Sum2[x][i]) %= p;
	return tmp;
}
int main()
{
	scanf("%d%d", &n, &m);
	add1(1, 1, 1);
	add2(1, 1, 1);
	add1(2, 1, -1);
	add2(1, 2, -1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			char ch = getchar();
			while (ch != '.' && ch != 'R') ch = getchar();
			val[i][j] = ch == 'R' ? 1 : 0;
			sum1[i][j] = sum2[i][j] = val[i][j];
		}
	if (val[n][m])
	{
		printf("0");
		return 0;
	}
	if (n == 1 && m == 1)
	{
		printf("1");
		return 0;
	}
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
		{
			sum1[i][j] += sum1[i + 1][j];
			sum2[i][j] += sum2[i][j + 1];
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			add1(i + 1, j, ask2(i, j));
			add1(n - sum1[i + 1][j] + 1, j, p - ask2(i, j));
			add2(i, j + 1, ask1(i, j));
			add2(i, m - sum2[i][j + 1] + 1, p - ask1(i, j));
		}
	printf("%d", (ask1(n, m) + ask2(n, m)) % p);
	return 0;
}