#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
#define mp make_pair

const int N = 53;
char s[N][N];
const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, 1, 0, -1};
piii a[N * N];
int n, m, k;
int sz;
bool used[N][N];
int cnt;

bool checkCell(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	return s[x][y] == '.';
}

void dfs(int x, int y)
{
	used[x][y] = 1;
	cnt++;
	for (int d = 0; d < 4; d++)
	{
		int xx = x + DX[d], yy = y + DY[d];
		if (!checkCell(xx, yy)) continue;
		if (used[xx][yy]) continue;
		dfs(xx, yy);
	}
	return;
}

void dfs2(int x, int y)
{
	s[x][y] = '*';
	for (int d = 0; d < 4; d++)
	{
		int xx = x + DX[d], yy = y + DY[d];
		if (!checkCell(xx, yy)) continue;
		dfs2(xx, yy);
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf(" %s ", s[i]);
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
		{
			if (x > 0 && x < n - 1 && y > 0 && y < m - 1) continue;
			if (s[x][y] == '*') continue;
			dfs(x, y);
		}
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
		{
			if (s[x][y] == '*') continue;
			if (used[x][y]) continue;
			cnt = 0;
			dfs(x, y);
			a[sz++] = mp(cnt, mp(x, y));
		}
	if (sz < k) throw;
	sort(a, a + sz);
	reverse(a, a + sz);
	int sum = 0;
	for (int i = k; i < sz; i++)
	{
		sum += a[i].first;
		dfs2(a[i].second.first, a[i].second.second);
	}
	printf("%d\n", sum);
	for (int i = 0; i < n; i++)
		printf("%s\n", s[i]);

	return 0;
}