#include <iostream>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 1000;

const int INF = 2000000000;

const int NDir = 4;
const int DirX[] = {-1,  0, 0, 1};
const int DirY[] = { 0, -1, 1, 0};

inline int toInt(char c)
{
	switch (c)
	{
		case 'U': return 0;
		case 'L': return 1;
		case 'R': return 2;
		case 'D': return 3;
	}
	return -1;
}

int n;
int dir[MaxN], delta[MaxN];

int seqXLen = 0, seqYLen = 0;
int seqX[MaxN * 3 + 5], seqY[MaxN * 3 + 5];

int a[MaxN * 3 + 5][MaxN * 3 + 5];

inline void dfs(const int &x, const int &y)
{
	if (!(0 <= x && x < seqXLen))
		return;
	if (!(0 <= y && y < seqYLen))
		return;
	if (a[x][y] != 0)
		return;
	a[x][y] = 2;
	for (int i = 0; i < NDir; i++)
		dfs(x + DirX[i], y + DirY[i]);
}

int main()
{
	int n;
	static int dir[MaxN], delta[MaxN];
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c >> delta[i];
		dir[i] = toInt(c);
	}

	int curX = 0, curY = 0;
	seqX[seqXLen++] = -INF;
	seqX[seqXLen++] = INF;
	seqY[seqYLen++] = -INF;
	seqY[seqYLen++] = INF;

	seqX[seqXLen++] = 0;
	seqX[seqXLen++] = -1;
	seqX[seqXLen++] = 1;
	seqY[seqYLen++] = 0;
	seqY[seqYLen++] = -1;
	seqY[seqYLen++] = 1;
	for (int i = 0; i < n; i++)
	{
		curX += DirX[dir[i]] * delta[i];
		curY += DirY[dir[i]] * delta[i];
		seqX[seqXLen++] = curX;
		seqX[seqXLen++] = curX - 1;
		seqX[seqXLen++] = curX + 1;
		seqY[seqYLen++] = curY;
		seqY[seqYLen++] = curY - 1;
		seqY[seqYLen++] = curY + 1;
	}
	sort(seqX, seqX + seqXLen);
	sort(seqY, seqY + seqYLen);
	seqXLen = unique(seqX, seqX + seqXLen) - seqX;
	seqYLen = unique(seqY, seqY + seqYLen) - seqY;

	curX = 0, curY = 0;
	for (int i = 0; i < n; i++)
	{
		int targetX, targetY;
		targetX = curX + DirX[dir[i]] * delta[i];
		targetY = curY + DirY[dir[i]] * delta[i];

		int tsx = lower_bound(seqX, seqX + seqXLen, curX) - seqX;
		int tsy = lower_bound(seqY, seqY + seqYLen, curY) - seqY;
		int tex = lower_bound(seqX, seqX + seqXLen, targetX) - seqX;
		int tey = lower_bound(seqY, seqY + seqYLen, targetY) - seqY;
		while (tsx != tex || tsy != tey)
		{
			a[tsx][tsy] = 1;
			tsx += DirX[dir[i]], tsy += DirY[dir[i]];
		}
		a[tex][tey] = 1;

		curX = targetX, curY = targetY;
	}

	dfs(0, 0);

	s64 res = 0ll;
	for (int i = 0; i < seqXLen; i++)
		for (int j = 0; j < seqYLen; j++)
			if (a[i][j] != 2)
				res += (s64)(seqX[i + 1] - seqX[i]) * (seqY[j + 1] - seqY[j]);
	cout << res << endl;

	return 0;
}