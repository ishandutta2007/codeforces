#include <bits/stdc++.h>
using namespace std;

struct z
{
	int x, y, r;
};

z dat[1005];
int n;
set<pair<int, int>> ans;

void check(int x, int y)
{
	for (int i = 0; i < n; i++)
	{
		if (dat[i].r*dat[i].r >=
			(dat[i].x - x)*(dat[i].x - x) +
			(dat[i].y - y)*(dat[i].y - y))
			return;
	}
	ans.emplace(x, y);
}

int main()
{
	int xa, ya, xb, yb;
	scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
	if (xa > xb) swap(xa, xb);
	if (ya > yb) swap(ya, yb);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &dat[i].x, &dat[i].y, &dat[i].r);
	}

	for (int i = xa; i <= xb; i++)
	{
		check(i, ya);
		check(i, yb);
	}

	for (int i = ya; i <= yb; i++)
	{
		check(xa, i);
		check(xb, i);
	}

	printf("%zd\n", ans.size());
}