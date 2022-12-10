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

const int N = 1e6 + 10;
const int Z = N / 2;
const int K = 1010;
bool ok[K];
int n, k;
int dp1[Z], dp2[Z];

void solve()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i)
	{
		int a;
		scanf("%d", &a);
		if (a == n)
		{
			puts("1");
#ifndef LOCAL
			return;
#endif
		}
		ok[a] = true;
	}
	vector<int> pos, neg;
	vector<int> vals;
	for (int i = 0; i < K; ++i)
		if (ok[i])
		{
			if (i > n)
				pos.push_back(i - n);
			else
				neg.push_back(n - i);
		}
	fill(dp1, dp1 + Z, INF);
	fill(dp2, dp2 + Z, INF);
	for (auto v : pos)
		dp1[v] = 1;
	for (auto v : neg)
		dp2[v] = 1;
	for(auto v : pos)
		for (int i = 0; i + v < Z; ++i)
			dp1[i + v] = min(dp1[i + v], dp1[i] + 1);
	for (auto v : neg)
		for (int i = 0; i + v < Z; ++i)
			dp2[i + v] = min(dp2[i + v], dp2[i] + 1);
	int ans = INF;
	for (int i = 0; i < Z; ++i)
		ans = min(ans, dp1[i] + dp2[i]);
	if (ans == INF)
		puts("-1");
	else
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