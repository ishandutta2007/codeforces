#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 1000;
const int MaxM = 1000;

const int MaxD = 8;
const int MaxCD = 2 * MaxD * (MaxD + 1) + 1;
const int MaxRN = MaxCD * 2;

const int ND = 4;
const int DX[] = {-1,  0, 0, 1};
const int DY[] = { 0, -1, 1, 0};

int r_n = 0;
pair<int, int> r[MaxRN];
int rg_l[MaxRN];
pair<int, int> rg[MaxRN][MaxCD];

inline bool isInRG(int p, const pair<int, int> &val)
{
	int idx = lower_bound(rg[p], rg[p] + rg_l[p], val) - rg[p];
	return idx < rg_l[p] && rg[p][idx] == val;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, d;
	static char a[MaxN + 1][MaxM + 2];

	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++)
		scanf("%s", a[i] + 1);

	static int dist[MaxN + 1][MaxM + 1];
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			dist[x][y] = -1;

	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			if (a[x][y] == 'R')
			{
				if (r_n == (2 * d * (d + 1) + 1) * 2)
				{
					cout << -1 << endl;
					return 0;
				}
				r[r_n] = make_pair(x, y);
				
				rg_l[r_n] = 0;
				dist[x][y] = 0, rg[r_n][rg_l[r_n]++] = make_pair(x, y);
				for (int i = 0; i < rg_l[r_n]; i++)
				{
					pair<int, int> v = rg[r_n][i];
					if (dist[v.first][v.second] == d)
						continue;
					for (int d = 0; d < ND; d++)
					{
						pair<int, int> u = make_pair(v.first + DX[d], v.second + DY[d]);
						if (a[u.first][u.second] != 'X' && dist[u.first][u.second] == -1)
							dist[u.first][u.second] = dist[v.first][v.second] + 1, rg[r_n][rg_l[r_n]++] = u;
					}
				}
				for (int i = 0; i < rg_l[r_n]; i++)
					dist[rg[r_n][i].first][rg[r_n][i].second] = -1;
				sort(rg[r_n], rg[r_n] + rg_l[r_n]);
				r_n++;
			}

	for (int i = 0; i < rg_l[0]; i++)
	{
		int p = 1;
		while (p < r_n && isInRG(p, rg[0][i]))
			p++;
		if (p == r_n)
		{
			for (int x = 1; x <= n; x++)
				for (int y = 1; y <= m; y++)
					if (a[x][y] != 'X' && rg[0][i] != make_pair(x, y))
					{
						cout << rg[0][i].first << " " << rg[0][i].second << " " << x << " " << y << endl;
						return 0;
					}
		}
		for (int j = 0; j < rg_l[p]; j++)
		{
			bool ok = true;
			for (int q = p + 1; q < r_n && ok; q++)
				if (!isInRG(q, rg[0][i]) && !isInRG(q, rg[p][j]))
					ok = false;
			if (ok)
			{
				cout << rg[0][i].first << " " << rg[0][i].second << " " << rg[p][j].first << " " << rg[p][j].second << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;
	return 0;
}