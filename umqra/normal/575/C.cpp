#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <ctime>
#include <valarray>
#include <complex>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;

const int C = (int)1e6;
const int INF = (int)1e8;
const int N = 23;
const int S = (int)2e5;
int table[N][N][2];
int v[N], u[N];
int mt[N];
int way[N];
int minDist[N];
int used[N];
int a[N][N];
int ans = INF;
int n;
int precalced[N];

struct Change
{
	int* ptr;
	int val;

	Change() : ptr(), val() {}
	Change(int* _ptr, int _val) : ptr(_ptr), val(_val) {}

	void apply()
	{
		*ptr = val;
	}
};
Change stackChanges[S];
int stSz;

void undo(int oldSz)
{
	while(stSz > oldSz)
	{
		stSz--;
		stackChanges[stSz].apply();
	}
}

void setVal(int* ptr, int val)
{
	stackChanges[stSz++] = Change(ptr, *ptr);
	*ptr = val;
}

void read()
{
	scanf("%d", &n);
	int p1[N], p2[N];
	for (int i = 0; i < n; i++)
		p1[i] = p2[i] = i;
	random_shuffle(p1, p1 + n);
	random_shuffle(p2, p2 + n);
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &table[p1[i]][p2[j]][k]);
				table[p1[i]][p2[j]][k] = C - table[p1[i]][p2[j]][k];
			}
	return;
}

void oneWayHungarian(int pos, int t)
{
	for (int i = 0; i < n; i++)
		a[pos + 1][i + 1] = table[pos][i][t];
	int row = pos + 1;
	setVal(mt + 0, row);
	for (int col = 0; col <= n; col++)
	{
		minDist[col] = INF;
		way[col] = -1;
		used[col] = 0;
	}
	int col = 0;
	while(row)
	{
		int ncol = -1;
		int delta = INF;
		used[col] = 1;
		for (int c = 0; c <= n; c++)
		{
			if (used[c]) continue;
			int newD = a[row][c] + v[row] + u[c];
			if (newD < minDist[c])
			{
				minDist[c] = newD;
				way[c] = col;
			}
			if (minDist[c] < delta)
			{
				delta = minDist[c];
				ncol = c;
			}
		}
		if (ncol == -1) throw;
		col = ncol;
		row = mt[col];
		for (int c = 0; c <= n; c++)
		{
			if (used[c])
			{
				setVal(u + c, u[c] + delta);
				setVal(v + mt[c], v[mt[c]] - delta);
			}
			else
				minDist[c] = minDist[c] - delta;
		}
	}
	while(col)
	{
		int ncol = way[col];
		setVal(mt + col, mt[ncol]);
		col = ncol;
	}
	return;
}

int getCurrentRes(int pos)
{
	return u[0] + precalced[pos];
}

void brute(int pos, int friday)
{
	if (getCurrentRes(pos) >= ans) return;
	if (pos == n)
	{
		ans = getCurrentRes(pos);
		return;
	}
	int t = rand() & 1;
	for (int i = 0; i < 2; i++, t ^= 1)
	{
		if (t)
		{
			if (friday * 2 == n) continue;
		}
		else
		{
			if ((pos - friday) * 2 == n) continue;
		}
		int oldSz = stSz;
		oneWayHungarian(pos, t);
		brute(pos + 1, friday + t);
		undo(oldSz);
	}
	return;
}

void precalc()
{
	precalced[n] = 0;
	for (int pos = n - 1; pos >= 0; pos--)
	{
		for (int i = 0; i < n; i++)
			a[pos + 1][i + 1] = min(table[pos][i][0], table[pos][i][1]);
		int row = pos + 1;
		setVal(mt + 0, row);
		for (int col = 0; col <= n; col++)
		{
			minDist[col] = INF;
			way[col] = -1;
			used[col] = 0;
		}
		int col = 0;
		while(row)
		{
			int ncol = -1;
			int delta = INF;
			used[col] = 1;
			for (int c = 0; c <= n; c++)
			{
				if (used[c]) continue;
				int newD = a[row][c] + v[row] + u[c];
				if (newD < minDist[c])
				{
					minDist[c] = newD;
					way[c] = col;
				}
				if (minDist[c] < delta)
				{
					delta = minDist[c];
					ncol = c;
				}
			}
			if (ncol == -1) throw;
			col = ncol;
			row = mt[col];
			for (int c = 0; c <= n; c++)
			{
				if (used[c])
				{
					setVal(u + c, u[c] + delta);
					setVal(v + mt[c], v[mt[c]] - delta);
				}
				else
					minDist[c] = minDist[c] - delta;
			}
		}
		while(col)
		{
			int ncol = way[col];
			setVal(mt + col, mt[ncol]);
			col = ncol;
		}
		precalced[pos] = u[0];
	}
	undo(0);
	return;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	read();
	precalc();
	brute(0, 0);
	printf("%d\n", n * C - ans);

	return 0;
}