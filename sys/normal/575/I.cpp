#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005, Maxq = 100005;
int n, q, type, opt[Maxq], x[Maxq], y[Maxq], dir[Maxq], len[Maxq], ans[Maxq];
int lowbit(int x)
{
	return x & -x;
}
int sum[Maxn][Maxn];
void add(int x, int y, int w)
{
	x += n, y += n;
	for (int i = x; i <= 2 * n + 1; i += lowbit(i))
		for (int j = y; j <= 2 * n + 1; j += lowbit(j))
			sum[i][j] += w;
}
int ask(int x, int y)
{
	x += n, y += n;
	int tmp = 0;
	for (int i = x; i; i -= lowbit(i))
		for (int j = y; j; j -= lowbit(j))
			tmp += sum[i][j];
	return tmp;
}
void add0(int x, int y, int w)
{
	if (type) return ;
	add(x, y, w);
}
int ask0(int x, int y)
{
	if (type) return 0;
	return ask(x, y);
}
void add1(int x, int y, int w)
{
	if (type != 1) return ;
	add(x - y, y, w);
}
int ask1(int x, int y)
{
	if (type != 1) return 0;
	return ask(x - y, y);
}
void add2(int x, int y, int w)
{
	if (type != 2) return ;
	add(1 - n, y, w);
	add(x + y + 1 - n, y, -w);
}
int ask2(int x, int y)
{
	if (type != 2) return 0;
	return ask(x + y - n, y);
}
void add3(int x, int y, int w)
{
	if (type != 3) return ;
	add(x, 1 - n, w);
	add(x, x - y + 1, -w);
}
int ask3(int x, int y)
{
	if (type != 3) return 0;
	return ask(x, x - y);
}
void add4(int x, int y, int w)
{
	if (type != 4) return ;
	add(1 - n, x + y - n, w);
	add(x + 1, x + y - n, -w);
}
int ask4(int x, int y)
{
	if (type != 4) return 0;
	return ask(x, x + y - n);
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d", &opt[i]);
		if (opt[i] == 1)
			scanf("%d%d%d%d", &dir[i], &x[i], &y[i], &len[i]);
		else scanf("%d%d", &x[i], &y[i]);
	}
	for (type = 0; type <= 4; type++)
	{
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= q; i++)
		{
			if (opt[i] == 1)
			{
				if (dir[i] == 1)
				{
					add0(x[i], y[i], 1);
					add0(x[i] + len[i] + 1, y[i], -1);
					add4(x[i] + len[i], y[i] + 1, -1);
					add4(x[i] - 1, y[i] + len[i] + 2, 1);
				}
				if (dir[i] == 2)
				{
					add0(x[i], y[i] + 1, -1);
					add3(x[i], y[i] - len[i], 1);
					add1(x[i] + len[i] + 2, y[i] + 1, 1);
				}
				if (dir[i] == 3)
				{
					add1(x[i] - len[i], y[i], 1);
					add0(x[i] + 1, y[i], -1);
					add3(x[i] + 1, y[i] + len[i] + 2, 1);
				}
				if (dir[i] == 4)
				{
					add4(x[i], y[i] - len[i], 1);
					add0(x[i] + 1, y[i] + 1, 1);
					add0(x[i] - len[i], y[i] + 1, -1);
					add4(x[i] - len[i] - 1, y[i] + 1, -1);
				}
			}
			else
				ans[i] += ask0(x[i], y[i]) + ask1(x[i], y[i]) + ask2(x[i], y[i]) + ask3(x[i], y[i]) + ask4(x[i], y[i]);
		}
	}
	for (int i = 1; i <= q; i++)
		if (opt[i] == 2)
			printf("%d\n", ans[i]);
	return 0;
}