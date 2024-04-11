#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

typedef long long s64;

const int MaxNC = 10;

const int M = 1000000007;

inline int &modaddto(int &a, const int &b)
{
	a = (a + b) % M;
	return a;
}

int n, m, nC;
int a[MaxNC][MaxNC];

int outcome = 0;

int col_used;
int pos[MaxNC], fixc[MaxNC];
int col[MaxNC][MaxNC];

void dfs(int x, int y)
{
	if (y == m)
		x++, y = 0;
	if (x == n)
	{
		for (int c = 0; c < col_used; c++)
			for (int d = 0; d < c; d++)
				if (fixc[c] != -1 && fixc[d] != -1 && fixc[c] == fixc[d])
					return;
		int n_q = 0;
		for (int c = 0; c < col_used; c++)
			if (fixc[c] == -1)
				n_q++;
		int cur = 1;
		for (int k = 0; k < n_q; k++)
			cur = (s64)cur * (nC - (col_used - n_q) - k) % M;
		outcome = (outcome + cur) % M;
		return;
	}

	for (int c = 0; c < col_used; c++)
		if (pos[c] > y)
		{
			int old = pos[c];
			int oldc = fixc[c];
			if (fixc[c] == -1)
				fixc[c] = a[x][y];
			else if (a[x][y] != -1 && fixc[c] != a[x][y])
				continue;

			pos[c] = y;
			dfs(x, y + 1);
			pos[c] = old;
			fixc[c] = oldc;
		}

	if (col_used < nC)
	{
		pos[col_used] = y;
		fixc[col_used] = a[x][y];
		col_used++;
		dfs(x, y + 1);
		col_used--;
	}
}

int main()
{
	cin >> n >> m >> nC;
	if (n + m - 1 > nC)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			cin >> a[x][y], a[x][y]--;

	col_used = 0;
	dfs(0, 0);

	cout << outcome << endl;
	return 0;
}