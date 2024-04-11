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

const int CNT = 1 << 16;
const int D = 16;
int prec[CNT + 1][D];
ll dp[D][D][2];
int digs[D];

ll calc(ll x)
{
	if (x <= 0)
		return 0;
	memset(dp, 0, sizeof dp);
	memset(digs, 0, sizeof digs);
	int dsz = 0;
	for (ll tx = x; tx != 0; tx >>= 4)
		digs[dsz++] = tx & 15;
	reverse(digs, digs + D);
	dp[0][0][1] = 1;
	for (int i = 0; i + 1 < D; ++i)
		for (int d = 0; d < D; ++d)
			for (int nd = 0; nd < D; ++nd)
			{
				dp[i + 1][max(d, nd)][false] += dp[i][d][false];
				if (nd < digs[i + 1])
					dp[i + 1][max(d, nd)][false] += dp[i][d][true];
				if (nd == digs[i + 1])
					dp[i + 1][max(d, nd)][true] += dp[i][d][true];
			}
	ll ans = 0;
	for (int d = 0; d < D; ++d)
	{
		ans += dp[D - 5][d][false] * prec[CNT][d];
		ans += dp[D - 5][d][true] * prec[(x & (CNT - 1)) + 1][d];
	}
	return ans;
}

void solve_q()
{
	ll l, r;
	scanf("%llx%llx", &l, &r);
	printf("%lld\n", calc(r) - calc(l - 1));
}

int md(int x)
{
	int ans = 0;
	for (; x != 0; x >>= 4)
		ans = max(ans, x & 15);
	return ans;
}

void solve()
{
	for (int i = 0; i < CNT; ++i)
		for (int d = 0; d < D; ++d)
		{
			if (i == 4116)
				int tmp = 1;
			prec[i + 1][d] = prec[i][d];
			auto cmd = max(d, md(i));
			if (i & (1 << cmd))
				++prec[i + 1][d];
		}

	int q;
	scanf("%d", &q);
	while (q--)
		solve_q();
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