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
#include <random>
#include <complex>
#include <regex>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#define mp make_pair
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define print_var(x) cerr << #x << " : " << (x) << endl
#define print_array(arr, len) {cerr << #arr << " : "; for(int i = 0; i < len; ++i) cerr << arr[i] << ' '; cerr << endl;}
#define print_2d_array(arr, len1, len2) {cerr << #arr << endl; for(int i = 0; i < len1; ++i, cerr << endl) for(int j = 0; j < len2; ++j) cerr << arr[i][j] << ' ';}
#define print_iterable(i) {cerr << #i << " : "; for(auto e : i) cerr << e << ' '; cerr << endl;}
#define print_new_line() cerr << endl
#else
#define eprintf(...) (void)0
#define print_var(x) (void)0
#define print_array(arr, len) {}
#define print_2d_array(arr, len1, len2) {}
#define print_iterable(i) {}
#define print_new_line() (void)0
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-11;
#pragma endregion

const int N = 1010;
const int N2 = N * N;
int n, m, k;
char f[N][N];
int sx, sy;
bool in_f(int x, int y)
{
	return 0 <= x && x < n &&
		0 <= y && y < m;
}
int wavex[N2];
int wavey[N2];
int wsi;
int dist[N][N];
char ans[N2];
int asz;
const int D = 4;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
char dc[] = { 'R', 'L', 'D', 'U' };

void solve()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", f[i]);
		for (int j = 0; j < m; ++j)
		{
			if (f[i][j] == 'X')
			{
				sx = i;
				sy = j;
				f[i][j] = true;
			}
			else
				f[i][j] = f[i][j] == '.';
		}
	}
	memset(dist, -1, sizeof dist);
	wavex[0] = sx;
	wavey[0] = sy;
	dist[sx][sy] = 0;
	wsi = 1;
	for (int i = 0; i < wsi; ++i)
	{
		int x = wavex[i];
		int y = wavey[i];
		for (int d = 0; d < D; ++d)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (in_f(nx, ny) && f[nx][ny] && dist[nx][ny] == -1)
			{
				dist[nx][ny] = dist[x][y] + 1;
				wavex[wsi] = nx;
				wavey[wsi] = ny;
				wsi++;
			}
		}
	}
	if (k % 2 == 1 || wsi == 1)
	{
		puts("IMPOSSIBLE");
		return;
	}
	int x = sx;
	int y = sy;
	for (; k > 0; --k)
	{
		int bd = -1;
		char bc = 'Z';
		for (int d = 0; d < D; ++d)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (dc[d] < bc && in_f(nx, ny) && f[nx][ny] && dist[nx][ny] <= k - 1)
			{
				bc = dc[d];
				bd = d;
			}
		}
		if (bd == -1)
			throw;
		ans[asz++] = bc;
		x += dx[bd];
		y += dy[bd];
	}
	puts(ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#ifdef NOERR
	freopen("err.txt", "w", stderr);
#endif
#else
	//freopen("alter.in", "r", stdin);
	//freopen("alter.out", "w", stdout);
#endif

#ifdef ST
	while (true)
		solve();
#endif
#ifdef CASES
#define MULTITEST
#endif
#ifdef MULTITEST
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
#ifdef CASES
		printf("Case #%d: ", i + 1);
#endif
		solve();
#ifdef CASES
		eprintf("Passed case #%d:\n", i + 1);
#endif
	}
#else
	solve();
#endif

	eprintf("\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
}