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

#ifdef LOCAL
#define ERR_CATCH
#endif

const int p = 5;
const int G = 6;
const int N = 130;
const int MX = 5000;
int n;
int a[N][p];
int cnt[p];
int p6[10];
int stg[p];
int add;
int vas, pet;

bool in_g(int g, int part, int ok)
{
	return (ok <= (part >> g) && (g == G - 1 || ((part >> (g+1)) < ok)));
}

int cost(int g)
{
	return 500 * (g + 1);
}

int tcost(int g, int t)
{
	int c = cost(g);
	return c - (c * t / 250);
}

bool iter_prob(int id)
{
	if (id == p)
	{
		//print_var(vas);
		//print_var(pet);
		//print_iterable(stg);
		return vas > pet;
	}
	int part = n + add;
	if (a[0][id] == -1)
	{
		int curg = -1;
		for (int g = 0; g < G; ++g)
			if (in_g(g, part, cnt[id]))
				curg = g;
		int padd = 0;
		if (a[1][id] != -1)
			padd = tcost(curg, a[1][id]);
		pet += padd;
		if (iter_prob(id + 1))
			return true;
		pet -= padd;
		return false;
	}
	for (int g = 0; g < G; ++g)
		if (cnt[id] <= (part >> g) && (g == G - 1 || cnt[id] + add > (part >> (g+1))))
		{
			stg[id] = g;
			int vadd = 0;
			int padd = 0;
			if (a[0][id] != -1)
				vadd = tcost(g, a[0][id]);
			if (a[1][id] != -1)
				padd = tcost(g, a[1][id]);
			vas += vadd;
			pet += padd;
			if (iter_prob(id + 1))
				return true;
			vas -= vadd;
			pet -= padd;
		}
	return false;
}

void solve()
{
	p6[0] = 1;
	for (int i = 1; i < 10; ++i)
		p6[i] = p6[i - 1] * 6;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < p; ++j)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] != -1)
				++cnt[j];
		}
	print_iterable(cnt);
	for (add = 0; add < MX; ++add)
		if (iter_prob(0))
		{
			print_var(add);
			printf("%d\n", add);
			return;
		}
	puts("-1");
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