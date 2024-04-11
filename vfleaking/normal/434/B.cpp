#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 1000;
const int MaxM = 1000;

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

struct Table
{
	int n, m;
	int a[MaxN + 1][MaxM + 1];
	int h[MaxN + 1][MaxM + 1];

	void init()
	{
		for (int x = 1; x <= n; x++)
			for (int y = 1; y <= m; y++)
				h[x][y] = a[x][y] ? h[x - 1][y] + 1 : 0;
	}
	void change(int x0, int y0)
	{
		a[x0][y0] = !a[x0][y0];
		for (int x = x0; x <= n; x++)
			h[x][y0] = a[x][y0] ? h[x - 1][y0] + 1 : 0;
	}
	int query(int x0, int y0)
	{
		static int le[MaxM + 1], ri[MaxN + 1];
		for (int y = 1; y <= m; y++)
		{
			le[y] = y - 1;
			while (le[y] > 0 && h[x0][y] <= h[x0][le[y]])
				le[y] = le[le[y]];
		}
		for (int y = m; y >= 1; y--)
		{
			ri[y] = y + 1;
			while (ri[y] <= m && h[x0][y] <= h[x0][ri[y]])
				ri[y] = ri[ri[y]];
		}

		int res = 0;
		for (int y = 1; y <= m; y++)
			if (le[y] < y0 && y0 < ri[y])
			relax(res, (ri[y] - le[y] - 1) * h[x0][y]);
		return res;
	}
};

int main()
{
	int n, m, nQ;
	static int a[MaxN + 1][MaxM + 1];

	cin >> n >> m >> nQ;
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			scanf("%d", &a[x][y]);

	static Table t1, t2, t3, t4;
	t1.n = n, t1.m = m;
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			t1.a[x][y] = a[x][y];

	t2.n = n, t2.m = m;
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			t2.a[x][y] = a[n + 1 - x][y];

	t3.n = m, t3.m = n;
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			t3.a[y][x] = a[x][y];

	t4.n = m, t4.m = n;
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			t4.a[y][x] = a[x][m + 1 - y];

	t1.init();
	t2.init();
	t3.init();
	t4.init();

	while (nQ--)
	{
		int type, x0, y0;
		scanf("%d %d %d", &type, &x0, &y0);

		if (type == 1)
		{
			t1.change(x0, y0);
			t2.change(n + 1 - x0, y0);
			t3.change(y0, x0);
			t4.change(m + 1 - y0, x0);
		}
		else
		{
			int res = 0;
			relax(res, t1.query(x0, y0));
			relax(res, t2.query(n + 1 - x0, y0));
			relax(res, t3.query(y0, x0));
			relax(res, t4.query(m + 1 - y0, x0));
			cout << res << endl;
		}
	}

	return 0;
}