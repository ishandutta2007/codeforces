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
const ld EPS = 1e-11;
#pragma endregion

const int N = 3e5 + 10;
const int LOGN = 20;
int n;
int u[N], d[N];
ll su[N], sd[N], sb[N];
int ju[N][LOGN], jd[N][LOGN], jb[N][LOGN];
pii dpu[N], dpd[N];

void relax(pii& a, pii b)
{
	if (a.first != b.first)
		a = max(a, b);
	else
		a = min(a, b);
}

void calc_jumps(ll ps[N], int jump[N][LOGN])
{
	for (int i = 0; i <= n + 1; ++i)
		for (int j = 0; j < LOGN; ++j)
			jump[i][j] = n + 1;
	map<ll, int> sums;
	for (int i = n; i >= 0; --i)
	{
		if (sums.count(ps[i]))
			jump[i][0] = sums[ps[i]];
		jump[i][0] = min(jump[i][0], jump[i + 1][0]);
		for (int j = 1; j < LOGN; ++j)
			jump[i][j] = jump[jump[i][j - 1]][j - 1];
		sums[ps[i]] = i;
	}
}

void relax(int u, int d, int v)
{
	int b = max(u, d);
	if (jd[d][0] != n + 1)
	{
		int add = 1;
		int nu = u;
		int nd = jd[d][0];
		for (int i = LOGN - 1; i >= 0; --i)
			if (ju[nu][i] <= nd)
			{
				nu = ju[nu][i];
				add += 1 << i;
			}
		relax(dpd[nd], mp(v + add, nu));
	}
	if (ju[u][0] != n + 1)
	{
		int add = 1;
		int nu = ju[u][0];
		int nd = d;
		for (int i = LOGN - 1; i >= 0; --i)
			if (jd[nd][i] <= nu)
			{
				nd = jd[nd][i];
				add += 1 << i;
			}
		relax(dpu[nu], mp(v + add, nd));
	}
	if (jb[b][0] != n + 1)
		relax(dpu[jb[b][0]], mp(v + 1, jb[b][0]));
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &u[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &d[i]);
	for (int i = 0; i < n; ++i)
	{
		su[i + 1] = su[i] + u[i];
		sd[i + 1] = sd[i] + d[i];
		sb[i + 1] = su[i + 1] + sd[i + 1];
	}
	calc_jumps(su, ju);
	calc_jumps(sd, jd);
	calc_jumps(sb, jb);
	for (int i = 0; i < n; ++i)
	{
		relax(i, dpu[i].second, dpu[i].first);
		relax(dpd[i].second, i, dpd[i].first);
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i)
		ans = max({ ans, dpu[i].first, dpd[i].first });
	printf("%d\n", ans);
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