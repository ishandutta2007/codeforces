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
#include <numeric>
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

template <typename T, typename Q>
void print_pair1(pair<T, Q> x)
{
	cerr << "(" << x.first << ", " << x.second << ")\n";
}

#define print_pair(x) {cerr << #x << " : "; print_pair1(x);}
#else
#define print_pair(x) (void)0
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

#ifdef LOCAL
#define ERR_CATCH
//#define NOERR
#endif

const int N = 3e5 + 10;
int n, m;
int d[N];
vector<pii> edges[N];
bool ans[N];
int par[N];
int q[N];
int qsz;
int wcnt[N];

void solve()
{
	scanf("%d%d", &n, &m);
	int one_cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &d[i]);
		one_cnt += d[i] == 1;
	}
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		edges[a].emplace_back(b, i);
		edges[b].emplace_back(a, i);
	}
	int root = -1;
	for (int i = 0; i < n; ++i)
		if (d[i] == -1)
			root = i;
	if (root == -1 && one_cnt % 2 == 1)
	{
		puts("-1");
		return;
	}
	if (one_cnt == 0)
	{
		puts("0");
		return;
	}
	if (root == -1)
	{
		for (int i = 0; i < n; ++i)
			if (d[i] == 1)
				root = i;
	}
	memset(par, -1, sizeof par);
	par[root] = -2;
	q[qsz++] = root;
	for(int i = 0; i < qsz; ++i)
	{
		auto v = q[i];
		for(auto e : edges[v])
			if (par[e.first] == -1)
			{
				par[e.first] = e.second;
				q[qsz++] = e.first;
			}
	}
	for (int i = 0; i < n; ++i)
		wcnt[i] = d[i] == 1;
	for(int i = n - 1; i > 0; --i)
	{
		auto v = q[i];
		if (wcnt[v] == 0)
			continue;
		ans[par[v]] = true;
		for (auto e : edges[v])
			if (e.second == par[v])
				wcnt[e.first] ^= 1;
	}
	int asz = 0;
	for (int i = 0; i < m; ++i)
		asz += ans[i];
	printf("%d\n", asz);
	for (int i = 0; i < m; ++i)
		if (ans[i])
			printf("%d\n", i + 1);
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
	//freopen("knight.in", "r", stdin);
	//freopen("knight.out", "w", stdout);
#endif

#ifdef ERR_CATCH
	try
	{
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
		char endl1[5];
		fgets(endl1, 5, stdin);
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

#ifdef ERR_CATCH
	}
	catch (logic_error e)
	{
		print_var(e.what());
		puts("___________________________________________________________________________");
		exit(0);
	}
#endif
#ifdef LOCAL
	eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
#endif
}