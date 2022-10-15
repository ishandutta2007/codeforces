#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int q, n;
void checkmax(int &x, int y)
{
	if (x < y)
	{
		x = y;
	}
}
void checkmin(int &x, int y)
{
	if (x > y)
	{
		x = y;
	}
}
int main()
{
	scanf("%d", &q);
	while (q--)
	{
		int maxx = 1e5, maxy = 1e5, minx = -1e5, miny = -1e5;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			int x, y, f1, f2, f3, f4;
			scanf("%d%d%d%d%d%d", &x, &y, &f1, &f2, &f3, &f4);
			if (!f1)
			{
				checkmax(minx, x);
			}
			if (!f2)
			{
				checkmin(maxy, y);
			}
			if (!f3)
			{
				checkmin(maxx, x);
			}
			if (!f4)
			{
				checkmax(miny, y);
			}
		}
		if (maxx < minx || maxy < miny)
		{
			printf("0\n");
		}
		else
		{
			printf("1 %d %d\n", minx, miny);
		}
	}
	return 0;
}