#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int query(int x1, int y1, int x2, int y2)
{
	if (x1 > x2 || y1 > y2) return 0;
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}

void solve(int &x1, int &x2, int &y1, int &y2)
{
	int l = x1 - 1, r = x2;
	while(r - l > 1)
	{
		int mid = (l + r) / 2;
		if (query(x1, y1, mid, y2) > 0)
			r = mid;
		else
			l = mid;
	}
	x2 = r;
	l = x1;
	r = x2 + 1;
	while(r - l > 1)
	{
		int mid = (l + r) / 2;
		if (query(mid, y1, x2, y2) > 0)
			l = mid;
		else
			r = mid;
	}
	x1 = l;
	l = y1 - 1;
	r = y2;
	while(r - l > 1)
	{
		int mid = (l + r) / 2;
		if (query(x1, y1, x2, mid) > 0)
			r = mid;
		else
			l = mid;
	}
	y2 = r;
	l = y1;
	r = y2 + 1;
	while(r - l > 1)
	{
		int mid = (l + r) / 2;
		if (query(x1, mid, x2, y2) > 0)
			l = mid;
		else
			r = mid;
	}
	y1 = l;
	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	int x1 = 1, x2 = n, y1 = 1, y2 = n;
	solve(x1, x2, y1, y2);
	int x3, x4, y3, y4;
	if (query(1, 1, x1 - 1, n) > 0)
	{
		x3 = 1;
		x4 = x1 - 1;
		y3 = 1;
		y4 = n;
	}
	else if (query(x2 + 1, 1, n, n) > 0)
	{
		x3 = x2 + 1;
		x4 = n;
		y3 = 1;
		y4 = n;
	}
	else if (query(1, 1, n, y1 - 1) > 0)
	{
		x3 = 1;
		y3 = 1;
		x4 = n;
		y4 = y1 - 1;
	}
	else if (query(1, y2 + 1, n, n) > 0)
	{
		x3 = 1;
		y3 = y2 + 1;
		x4 = n;
		y4 = n;
	}
	else throw;
	solve(x3, x4, y3, y4);
	printf("! %d %d %d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3, x4, y4);
	fflush(stdout);

	return 0;
}