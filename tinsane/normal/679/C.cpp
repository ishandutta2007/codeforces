#pragma region Template
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
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;

#pragma endregion

const int N = 510;
int n, k;
int eng_s[N][N], eng_l[N][N];
int ans[N][N];
char field[N][N];
bool used[N][N];
pii wave[N * N];
int wsi;

bool in_field(int x, int y)
{
	return 0 <= x && x < n &&
		0 <= y && y < n;
}

void relax(int x, int y)
{
	if (!in_field(x, y) || used[x][y])
		return;
	used[x][y] = true;
	wave[wsi].first = x;
	wave[wsi].second = y;
	++wsi;
}

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int last[N];

void upd_col(int j, int f, int l)
{
	if (l <= last[j])
		return;
	if (last[j] == -1 || last[j] < f)
	{
		last[j] = l;
		ans[f][j] += wsi;
		ans[l + 1][j] -= wsi;
	}
	else
	{
		ans[last[j] + 1][j] += wsi;
		last[j] = l;
		ans[l + 1][j] -= wsi;
	}
}

void solve(int x, int y)
{
	wsi = 1;
	used[x][y] = true;
	wave[0].first = x;
	wave[0].second = y;
	for (int i = 0; i < wsi; ++i)
	{
		int wx = wave[i].first;
		int wy = wave[i].second;
		for (int d = 0; d < 4; ++d)
			relax(wx + dx[d], wy + dy[d]);
	}
	fill(last, last + N, -1);
	sort(wave, wave + wsi);
	int b = 0;
	for (int i = 0; i < wsi; ++i)
	{
		if (wave[i].first != wave[b].first)
		{
			for (int j = b; j < i; ++j)
			{
				if (wave[j].second - k >= 0)
					upd_col(wave[j].second - k, max(0, wave[j].first - k + 1), wave[j].first);
				upd_col(wave[j].second + 1, max(0, wave[j].first - k + 1), wave[j].first);
			}
			b = i;
		}
		int f = max(0, wave[i].first - k);
		int l = wave[i].first + 1;
		for (int j = max(0, wave[i].second - k + 1); j <= wave[i].second; ++j)
			upd_col(j, f, l);
	}
	for (int j = b; j < wsi; ++j)
	{
		if (wave[j].second - k >= 0)
				upd_col(wave[j].second - k, max(0, wave[j].first - k + 1), wave[j].first);
		upd_col(wave[j].second + 1, max(0, wave[j].first - k + 1), wave[j].first);
	}
}

void solve()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%s", field[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < k; ++j)
			eng_l[0][i] += field[j][i] == 'X';
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < n; ++j)
			eng_l[i][j] = eng_l[i - 1][j] - (field[i - 1][j] == 'X') + (field[i + k - 1][j] == 'X');
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= n - k; ++j)
			for (int t = 0; t < k; ++t)
				eng_s[i][j] += eng_l[i][j + t];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			used[i][j] = field[i][j] == 'X';
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (!used[i][j])
				solve(i, j);
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ans[i][j] += ans[i - 1][j];
	int best = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			best = max(best, ans[i][j] + eng_s[i][j]);
	printf("%d", best);
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