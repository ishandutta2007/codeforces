#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int DX[] = {0, -1, 0, 1};
const int DY[] = {1, 0, -1, 0};

const int N = 2010;
const int SZ = N * N;

int n, m;
char table[N][N];
int deg[N][N];
pii q[SZ];
int topQ = 0;

void fail()
{
	puts("Not unique");
	exit(0);
}

bool check(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m && table[x][y] == '.';
}

void putTile(int x1, int y1, int x2, int y2)
{
	if (mp(-x1, y1) > mp(-x2, y2))
	{
		putTile(x2, y2, x1, y1);
		return;
	}
	if (y1 == y2)
	{
		table[x1][y1] = 'v';
		table[x2][y2] = '^';
	}
	else
	{
		table[x1][y1] = '<';
		table[x2][y2] = '>';
	}
}

void changeDeg(int x, int y)
{
	for (int d = 0; d < 4; d++)
	{
		int nx = x + DX[d];
		int ny = y + DY[d];
		if (check(nx, ny))
		{
			deg[nx][ny]--;
			if (deg[nx][ny] == 1)
				q[topQ++] = mp(nx, ny);
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf(" %s", table[i]);
	
	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < m; s++)
		{
			for (int d = 0; d < 4; d++)
			{
				int nx = i + DX[d];
				int ny = s + DY[d];
				if (check(nx, ny))
					deg[i][s]++;
			}
			if (deg[i][s] == 1)
				q[topQ++] = mp(i, s);
		}
	}

	for (int i = 0; i < topQ; i++)
	{
		pii v = q[i];
		if (table[v.X][v.Y] != '.')
			continue;
		for (int d = 0; d < 4; d++)
		{
			int nx = v.X + DX[d];
			int ny = v.Y + DY[d];
			if (check(nx, ny))
			{
				putTile(v.X, v.Y, nx, ny);
				changeDeg(nx, ny);
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int s = 0; s < m; s++)
		{
			if (table[i][s] == '.')
				fail();
		}
	for (int i = 0; i < n; i++)
		printf("%s\n", table[i]);

	return 0;
}