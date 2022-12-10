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

const int N = 1e6 + 10;
const int SZ = 8 * N;
const int S = 2 * N;

struct Segt
{
	int a[SZ];
	void clear()
	{
		memset(a, 0, sizeof a);
	}
	void inc(int ind, int l, int r, int pos)
	{
		++a[ind];
		if (l == r)
			return;
		int m = (l + r) / 2;
		if (pos <= m)
			inc(ind * 2, l, m, pos);
		else
			inc(ind * 2 + 1, m + 1, r, pos);
	}
	void inc(int pos)
	{
		inc(1, 0, S - 1, pos + N);
	}
	int lift(int ind, int l, int r, int froml)
	{
		if (l == r)
			return l - N;
		int m = (l + r) / 2;
		int tm = m - N;
		if (tm >= 0 || abs(tm + 1) < a[ind * 2] + froml)
		{
			auto res = lift(ind * 2, l, m, froml);
			return res + a[ind * 2 + 1];
		}
		else
			return lift(ind * 2 + 1, m + 1, r, froml + a[ind * 2]);
	}
	int lift()
	{
		return lift(1, 0, S - 1, 0);
	}
} segt;
set<pii> segs;

void add(int x)
{
	auto it = segs.upper_bound({x, INF});
	if (it == segs.begin())
	{
		if (it != segs.end() && it->first == x + 1)
		{
			auto r = it->second;
			segs.erase(it);
			segs.emplace(x, r);
		}
		else
			segs.emplace(x, x);
		segt.inc(x);
		return;
	}
	auto pit = prev(it);
	if (pit->second >= x)
	{
		add(pit->first - 1);
		return;
	}
	segt.inc(x);
	if (pit->second == x - 1)
	{
		auto l = pit->first;
		segs.erase(pit);
		if (it != segs.end() && it->first == x + 1)
		{
			x = it->second;
			segs.erase(it);
		}
		segs.emplace(l, x);
	}
	else if (it != segs.end() && it->first == x + 1)
	{
		auto r = it->second;
		segs.erase(it);
		segs.emplace(x, r);
	}
	else
		segs.emplace(x, x);
}

int solve_q(int x)
{
	add(x);
#ifdef LOCAL
	for(auto seg : segs)
		eprintf("[%d..%d] ", seg.first, seg.second);
	eprintf("\n");
#endif
	return segt.lift();
}

vector<int> slow;

int solve_s(int x)
{
	slow.push_back(x);
	inplace_merge(slow.begin(), prev(slow.end()), slow.end());
	int bal = 0;
	for (auto x : slow)
		if (bal > x)
			--bal;
		else if (bal < x)
			++bal;
	return bal;
}

//#define ST
mt19937 rnd(1000500);

void solve()
{
	int n;
#ifndef ST
	scanf("%d", &n);
#else
	const int X = 20;
	n = rnd() % X;
	eprintf("%d\n", n);
	print_var(n);
	segt.clear();
	segs.clear();
	slow.clear();
#endif
	for (int i = 0; i < n; ++i)
	{
		int x;
#ifndef ST
		scanf("%d", &x);
#else
		x = rnd() % (2 * X + 1) - X;
		print_var(x);
		auto sres = solve_s(x);
#endif
		auto res = solve_q(x);
#ifndef ST
		printf("%d\n", res);
#else
		if (res != sres)
		{
			print_var(res);
			print_var(sres);
			exit(0);
		}
#endif
	}
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