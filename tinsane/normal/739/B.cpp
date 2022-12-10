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
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#define mp make_pair
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define print_var(x) cout << #x << " : " << (x) << endl
#define print_array(arr, len) {cout << #arr << " : "; for(int i = 0; i < len; ++i) cout << arr[i] << ' '; cout << endl;}
#define print_2d_array(arr, len1, len2) {cout << #arr << endl; for(int i = 0; i < len1; ++i, cout << endl) for(int j = 0; j < len2; ++j) cout << arr[i][j] << ' ';}
#define print_iterable(i) {cout << #i << " : "; for(auto e : i) cout << e << ' '; cout << endl;}
#define print_new_line() cout << endl
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

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-7;
const ld EPS = 1e-13;

#pragma endregion

const int N = 2e5 + 10;
const int LOGN = 20;
int n;
int a[N];
vector<int> edges[N];
int anc[LOGN][N];
int ans[N];
ll path[LOGN][N];

void dfs(int v)
{
	for (int i = 1; i < LOGN; ++i)
	{
		anc[i][v] = anc[i - 1][anc[i - 1][v]];
		path[i][v] = path[i - 1][v] + path[i - 1][anc[i - 1][v]];
	}
	int u = v;
	for (int i = LOGN - 1; i >= 0; --i)
		if (path[i][u] <= a[v])
		{
			a[v] -= path[i][u];
			u = anc[i][u];
		}
	++ans[v];
	if (anc[0][u] != u)
		--ans[anc[0][u]];
	for(auto e : edges[v])
	{
		dfs(e);
		ans[v] += ans[e];
	}
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		edges[a].push_back(i);
		anc[0][i] = a;
		path[0][i] = b;
	}
	dfs(0);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i] - 1);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("alter.in", "r", stdin);
	//freopen("alter.out", "w", stdout);
#endif

#ifdef ST
	while (true)
	{
		solve();
	}
#endif
#ifdef MULTITEST
	int t;
	scanf("%d", &t);
	while (t--)
#endif
		solve();

	eprintf("\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
}