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
#ifdef LOCAL
#include <windows.h>
#endif
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

#ifdef LOCAL
#define ERR_CATCH
//#define NOERR
#endif

const int N = 1e5 + 10;
int n, a, b;
int ans;
vector<pii> c, d;
int pm[N];

int solve(vector<pii> v, int s)
{
	pm[0] = 0;
	int res = 0;
	for (int i = 0; i < v.size(); ++i)
		pm[i + 1] = max(pm[i], v[i].second);

	int rit = (int)v.size() - 1;
	for (int i = 1; i < v.size(); ++i)
	{
		int left = s - v[i].first;
		for (; rit >= 0 && left < v[rit].first; --rit);
		if (rit == -1)
			continue;
		if (rit >= i)
			res = max(res, v[i].second + pm[i]);
		else
			res = max(res, v[i].second + pm[rit + 1]);
	}

	return res;
}

void solve()
{
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; ++i)
	{
		int beat, cost;
		char s[10];
		scanf("%d%d%s", &beat, &cost, s);
		if (s[0] == 'C')
			c.emplace_back(cost, beat);
		else
			d.emplace_back(cost, beat);
	}
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());

	int mxc = 0;
	int mxd = 0;
	for (auto p : c)
		if (p.first <= a)
			mxc = max(mxc, p.second);
	for (auto p : d)
		if (p.first <= b)
			mxd = max(mxd, p.second);
	if (mxc > 0 && mxd > 0)
		ans = mxc + mxd;
	ans = max(ans, solve(c, a));
	ans = max(ans, solve(d, b));

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
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
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

	eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
}