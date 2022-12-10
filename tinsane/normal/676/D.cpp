#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;

const int N = 1010;
int n, m;
int wave[N * N * 4];
int wsi;
int dist[4][N][N];
bool moves[4][N][N];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char str[N];
int sx, sy, fx, fy;

bool in_bounds(int x, int y)
{
	return 0 <= x && x < n &&
		0 <= y && y < m;
}

void try_relax(int x, int y, int dir, int t)
{
	if (!in_bounds(x, y) || dist[dir][x][y] != -1)
		return;
	dist[dir][x][y] = t;
	wave[wsi++] = dir * N * N + x * N + y;
}

void relax(int x, int y, int dir)
{
	try_relax(x, y, (dir + 1) % 4, dist[dir][x][y] + 1);
	for (int i = 0; i < 4; ++i)
	{
		int d = (dir + i) % 4;
		if (moves[i][x][y] && in_bounds(x + dx[d], y + dy[d]) && moves[(i + 2) % 4][x + dx[d]][y + dy[d]])
			try_relax(x + dx[d], y + dy[d], dir, dist[dir][x][y] + 1);
	}
}

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", str);
		for (int j = 0; j < m; ++j)
		{
			if (str[j] == '+' || str[j] == '-' || str[j] == '>' ||
				str[j] == 'L' || str[j] == 'D' || str[j] == 'U')
				moves[0][i][j] = true;
			if (str[j] == '+' || str[j] == '|' || str[j] == 'v' ||
				str[j] == 'L' || str[j] == 'R' || str[j] == 'U')
				moves[1][i][j] = true;
			if (str[j] == '+' || str[j] == '-' || str[j] == '<' ||
				str[j] == 'R' || str[j] == 'D' || str[j] == 'U')
				moves[2][i][j] = true;
			if (str[j] == '+' || str[j] == '|' || str[j] == '^' ||
				str[j] == 'L' || str[j] == 'R' || str[j] == 'D')
				moves[3][i][j] = true;
		}
	}
	scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
	--sx, --sy, --fx, --fy;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < 4; ++k)
				dist[k][i][j] = -1;
	dist[0][sx][sy] = 0;
	wave[0] = sx * N + sy;
	wsi = 1;
	for (int i = 0; i < wsi; ++i)
	{
		int y = wave[i] % N;
		int x = wave[i] / N % N;
		int dir = wave[i] / N / N;
		relax(x, y, dir);
	}
	int ans = min({ dist[0][fx][fy], dist[1][fx][fy], dist[2][fx][fy], dist[3][fx][fy] });
	printf("%d", ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("chocolate.in", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif
	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
	return 0;
}