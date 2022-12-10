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

template <typename T, typename Q>
ostream& operator<<(ostream& os, pair<T, Q> p)
{
	return (os << '(' << p.first << ", " << p.second << ')');
}

#define mp make_pair
#define rand govno_ebanoe
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
const int K = 21;
int n, k;
int arr[N];
ll dp[K][N];
ll slow[K][N];
int its[N];
int ti[N];
unsigned int now;
int lb, rb;

int& get(int id)
{
	if (ti[id] != now)
	{
		ti[id] = now;
		its[id] = 0;
	}
	return its[id];
}

int calc_dp(int id, int i, int a, int b, ll& f)
{
	int best = -1;
	while(rb < i)
		f += get(arr[rb++])++;
	while (lb > b + 1)
		f += get(arr[--lb])++;
	while (lb <= b)
		f -= --get(arr[lb++]);
	while (rb > i)
		f -= --get(arr[--rb]);
	dp[id][i] = LINF;
	for(int j = b; j >= a; --j)
	{
		f += get(arr[j])++;
		if (j <= b && dp[id - 1][j] + f <= dp[id][i])
		{
			dp[id][i] = dp[id - 1][j] + f;
			best = j;
		}
	}
	lb = a;
	return best;
}

void calc(int id, int l, int r, int a, int b, ll& tf)
{
	if (r < l)
		return;
	auto m = (l + r) / 2;
	auto mid = calc_dp(id, m, a, min(b, m - 1), tf);
	calc(id, l, m - 1, a, mid, tf);
	calc(id, m + 1, r, mid, b, tf);
}

void calc_layer(int l)
{
	++now;
	lb = 0;
	rb = 1;
	ll f = get(arr[0])++;
	calc(l, 0, n, 0, n, f);
}

void calc_slow()
{
#ifndef LOCAL
	return;
#endif
	++now;
	for (int i = 0; i < n; ++i)
		slow[0][i + 1] = slow[0][i] + get(arr[i])++;
	for(int l = 1; l < k; ++l)
		for(int i = 1; i <= n; ++i)
		{
			slow[l][i] = LINF;
			++now;
			ll f = 0;
			for(int j = i - 1; j >= 0; --j)
			{
				f += get(arr[j])++;
				slow[l][i] = min(slow[l][i], slow[l - 1][j] + f);
			}
		}
}

#ifdef LOCAL
//#define ST
mt19937 rnd(10050);
const int SN = 100;
const int SK = 10;
#endif

void solve()
{
#ifndef ST
	scanf("%d%d", &n, &k);
#else
	n = rnd() % SN + 1;
	k = rnd() % min(SK, n) + 1;
	++now;
#endif
	for (int i = 0; i < n; ++i)
	{
#ifndef ST
		scanf("%d", &arr[i]);
		--arr[i];
#else
		arr[i] = rnd() % n;
#endif
	}
	print_var(now);
	for(int i = 0; i < n; ++i)
	{
		dp[0][i + 1] = dp[0][i];
		dp[0][i + 1] += get(arr[i])++;
	}
	for (int l = 1; l < k; ++l)
		calc_layer(l);
	//print_2d_array(dp, k, n + 1);
	//calc_slow();
	//print_2d_array(slow, k, n + 1);
#ifdef ST
	for (int i = 0; i < k; ++i)
		for (int j = i; j <= n; ++j)
			if (dp[i][j] != slow[i][j])
			{
				eprintf("%d %d\n", n, k);
				print_array(arr, n);
				exit(0);
			}
#else
	printf("%lld\n", dp[k - 1][n]);
#endif
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
#ifdef LOCAL
	eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
#endif
}