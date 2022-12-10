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
typedef pair<ll, ll> pll;

const int INF = (int)1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;
#pragma endregion

const int N = 4010;
const int K = 810;
const int L = 1e5;
char buf[L];
int n, k;
int a[N][N];
int ps[N][N];
int dp[K][N];

inline int gets(int l, int r)
{
	return (ps[r + 1][r + 1] - 2 * ps[r + 1][l] + ps[l][l]) / 2;
}

void calc_dp(int row, int l, int r, int L, int R)
{
	if (l > r)
		return;
	int m = (l + r) / 2;
	int lb = min(L, m);
	int rb = min(R, m);
	dp[row][m] = INF;
	int mi = lb;
	for (int i = lb; i <= rb; ++i)
	{
		int v = dp[row - 1][i] + gets(i, m - 1);
		if (v < dp[row][m])
		{
			dp[row][m] = v;
			mi = i;
		}
	}
	calc_dp(row, l, m - 1, L, mi);
	calc_dp(row, m + 1, r, mi, R);
}

void calc_dp(int row)
{
	calc_dp(row, 0, n, 0, n);
}

void solve()
{
	scanf("%d%d", &n, &k);
	fgets(buf, L, stdin);
	for (int i = 0; i < n; ++i)
	{
		fgets(buf, L, stdin);
		int l = strlen(buf);
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = buf[2 * j] - '0';
			ps[i + 1][j + 1] = a[i][j] + ps[i][j + 1] + ps[i + 1][j] - ps[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
		dp[0][i] = INF;
	for (int i = 1; i <= k; ++i)
		calc_dp(i);
	printf("%d\n", dp[k][n]);
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