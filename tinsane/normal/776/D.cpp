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

const int N = 2e5 + 10;
int n, m;
int r[N];
int f[N], s[N];
vector<int> edges[N], redges[N];
bool used[N];
int topo[N], tsi;

struct DSU
{
	int rank[N];
	int dsu[N];
	void init(int sz)
	{
		memset(rank, 0, sizeof rank);
		for (int i = 0; i < sz; ++i)
			dsu[i] = i;
	}
	int get(int v)
	{
		return dsu[v] == v ? v : dsu[v] = get(dsu[v]);
	}
	void unite(int a, int b)
	{
		a = get(a);
		b = get(b);
		if (a == b)
			return;
		if (rank[a] < rank[b])
			swap(a, b);
		if (rank[a] == rank[b])
			++rank[a];
		dsu[b] = a;
	}
} dsu;

void dfs(int v)
{
	if (used[v])
		return;
	used[v] = true;
	for (auto e : edges[v])
		dfs(e);
	topo[tsi++] = v;
}

void add_edge(int v, int u)
{
	edges[v].push_back(u);
	redges[u].push_back(v);
}

void notp(int x, int y)
{
	add_edge(x, y ^ 1);
	add_edge(y, x ^ 1);
}

void dfs_u(int v)
{
	if (used[v])
		return;
	used[v] = true;
	for (auto e : redges[v])
	{
		if (!used[e])
			dsu.unite(v, e);
		dfs_u(e);
	}
}

void solve()
{
	scanf("%d%d", &n, &m);
	dsu.init(2 * m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &r[i]);
	memset(f, -1, sizeof f);
	memset(s, -1, sizeof s);
	for (int i = 0; i < m; ++i)
	{
		int cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; ++j)
		{
			int x;
			scanf("%d", &x);
			--x;
			if (f[x] == -1)
				f[x] = i;
			else
				s[x] = i;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (s[i] != -1)
		{
			if (r[i])
			{
				notp(2 * f[i], 2 * s[i] + 1);
				notp(2 * f[i] + 1, 2 * s[i]);
			}
			else
			{
				notp(2 * f[i], 2 * s[i]);
				notp(2 * f[i] + 1, 2 * s[i] + 1);
			}
		}
		else if (f[i] != -1)
		{
			if (r[i])
				add_edge(2 * f[i] + 1, 2 * f[i]);
			else
				add_edge(2 * f[i], 2 * f[i] + 1);
		}
	}
	for (int v = 0; v < 2 * m; ++v)
		dfs(v);
	reverse(topo, topo + tsi);
	memset(used, false, sizeof used);
	for (int i = 0; i < tsi; ++i)
		dfs_u(topo[i]);
	for (int i = 0; i < tsi; ++i)
		if (dsu.get(i) == dsu.get(i ^ 1))
		{
			puts("NO");
			return;
		}
	puts("YES");
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
	while(true)
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
		//eprintf("Passed case #%d:\n", i + 1);
#endif
	}
#else
		solve();
#endif

	eprintf("\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
}