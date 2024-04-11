#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

const int MaxN = 30;
const int MaxM = 30;
const int MaxS = 900;

int sgn(int x)
{
	if (x < 0)
		return -1;
	else if (x > 0)
		return 1;
	else
		return 0;
}

int n, m;
int a[MaxN + 1][MaxM + 1];
int b[MaxN + 1][MaxM + 1];

vector< pair<int, int> > sol;

void smove(int x, int y) {
	if (!sol.empty())
	{
		swap(a[sol.back().first][sol.back().second], a[x][y]);
		if (sol.size() >= 2 && sol[sol.size() - 2] == make_pair(x, y))
		{
			sol.pop_back();
			return;
		}
	}
	sol.push_back(make_pair(x, y));
}

void orzl(int cx, int cy)
{
	if (cx == 1)
	{
		for (int i = 1; i <= cy; i++)
			smove(2, i);
		smove(cx, cy);
		smove(cx, cy - 1);
		for (int i = cy; i >= 1; i--)
			smove(2, i);
	}
	else
	{
		for (int i = 2; i <= cy; i++)
			smove(1, i);
		for (int i = 2; i < cx; i++)
			smove(i, cy);
		smove(cx, cy);
		smove(cx, cy - 1);
		for (int i = cx - 1; i >= 2; i--)
			smove(i, cy);
		for (int i = cy; i >= 2; i--)
			smove(1, i);
	}
	smove(1, 1);
}
void orzr(int cx, int cy)
{
	if (cx == 1)
	{
		for (int i = 1; i <= cy; i++)
			smove(2, i);
		smove(cx, cy);
		smove(cx, cy + 1);
		for (int i = cy; i >= 1; i--)
			smove(2, i);
	}
	else
	{
		for (int i = 2; i <= cy; i++)
			smove(1, i);
		for (int i = 2; i < cx; i++)
			smove(i, cy);
		smove(cx, cy);
		smove(cx, cy + 1);
		for (int i = cx - 1; i >= 2; i--)
			smove(i, cy);
		for (int i = cy; i >= 2; i--)
			smove(1, i);
	}
	smove(1, 1);
}
void orzu(int cx, int cy)
{
	if (cy == 1)
	{
		for (int i = 1; i <= cx; i++)
			smove(i, 2);
		smove(cx, cy);
		smove(cx - 1, cy);
		for (int i = cx; i >= 1; i--)
			smove(i, 2);
	}
	else
	{
		for (int i = 2; i <= cx; i++)
			smove(i, 1);
		for (int i = 2; i < cy; i++)
			smove(cx, i);
		smove(cx, cy);
		smove(cx - 1, cy);
		for (int i = cy - 1; i >= 2; i--)
			smove(cx, i);
		for (int i = cx; i >= 2; i--)
			smove(i, 1);
	}
	smove(1, 1);
}
void orzd(int cx, int cy)
{
	if (cy == 1)
	{
		for (int i = 1; i <= cx; i++)
			smove(i, 2);
		smove(cx, cy);
		smove(cx + 1, cy);
		for (int i = cx; i >= 1; i--)
			smove(i, 2);
	}
	else
	{
		for (int i = 2; i <= cx; i++)
			smove(i, 1);
		for (int i = 2; i < cy; i++)
			smove(cx, i);
		smove(cx, cy);
		smove(cx + 1, cy);
		for (int i = cy - 1; i >= 2; i--)
			smove(cx, i);
		for (int i = cx; i >= 2; i--)
			smove(i, 1);
	}
	smove(1, 1);
}

void orzmove(int sx, int sy, int tx, int ty)
{
	if (sx > tx)
	{
		swap(sx, tx);
		swap(sy, ty);
	}

	for (int i = sx; i < tx; i++)
		orzd(i, sy);

	if (sy == ty)
	{
		for (int i = tx - 1; i > sx; i--)
			orzu(i, sy);
	}
	else if (sy < ty)
	{
		for (int i = sy; i < ty; i++)
			orzr(tx, i);
		for (int i = ty - 1; i > sy; i--)
			orzl(tx, i);
		for (int i = tx; i > sx; i--)
			orzu(i, sy);
	}
	else
	{
		for (int i = sy; i > ty; i--)
			orzl(tx, i);
		for (int i = ty + 1; i < sy; i++)
			orzr(tx, i);
		for (int i = tx; i > sx; i--)
			orzu(i, sy);
	}
}

void handle()
{
	if (n == 1 || m == 1)
	{
		bool rotated = m == 1;
		if (rotated)
		{
			for (int i = 1; i <= n; i++)
				a[1][i] = a[i][1];
			for (int i = 1; i <= n; i++)
				b[1][i] = b[i][1];
			swap(n, m);
		}

		for (int l = 1; l <= m; l++)
			for (int r = l; r <= m; r++)
			{
				bool ok = true;
				for (int i = 1; i <= m; i++)
				{
					int c;
					if (i < l)
						c = a[1][i];
					else if (i < r)
						c = a[1][i + 1];
					else if (i == r)
						c = a[1][l];
					else
						c = a[1][i];
					if (b[1][i] != c)
					{
						ok = false;
						break;
					}
				}
				if (ok)
				{
					for (int i = l; i <= r; i++)
					{
						if (!rotated)
							sol.push_back(make_pair(1, i));
						else
							sol.push_back(make_pair(i, 1));
					}
					return;
				}
			}
		for (int l = 1; l <= m; l++)
			for (int r = l; r <= m; r++)
			{
				bool ok = true;
				for (int i = 1; i <= m; i++)
				{
					int c;
					if (i < l)
						c = a[1][i];
					else if (i == l)
						c = a[1][r];
					else if (i <= r)
						c = a[1][i - 1];
					else
						c = a[1][i];
					if (b[1][i] != c)
					{
						ok = false;
						break;
					}
				}
				if (ok)
				{
					for (int i = r; i >= l; i--)
					{
						if (!rotated)
							sol.push_back(make_pair(1, i));
						else
							sol.push_back(make_pair(i, 1));
					}
					return;
				}
			}
		return;
	}

	int cx = -1, cy;
	for (int x = 1; x <= n && cx == -1; x++)
		for (int y = 1; y <= m && cx == -1; y++)
			if (a[x][y] == b[1][1])
				cx = x, cy = y;
	if (cx == -1)
		return;

	for (int i = cx; i > 1; i--)
		smove(i, cy);
	for (int i = cy; i >= 1; i--)
		smove(1, i);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cx = -1;
			for (int x = i; x <= n && cx == -1; x++)
				for (int y = x == i ? j : 1; y <= m && cx == -1; y++)
					if (a[x][y] == b[i][j])
						cx = x, cy = y;
			if (cx == -1)
			{
				sol.clear();
				return;
			}
			if (cx == i && cy == j)
				continue;
			orzmove(cx, cy, i, j);
		}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &b[i][j]);

	handle();

	cout << (int)sol.size() - 1 << endl;
	for (int i = 0; i < (int)sol.size(); i++)
		printf("%d %d\n", sol[i].first, sol[i].second);

	return 0;
}