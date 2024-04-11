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

const int P = 1e9 + 7;
int sum(int a, int b)
{
	a += b;
	return a >= P ? a - P : a;
}
int mul(int a, int b)
{
	return (ll)a * b % P;
}
const int N = 310;
int n;
int a[N];
int cnt[N];
int dp[2][N][N];

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int ans = 1;
	int cl_cnt = 0;
	for(int i = 0; i < n; ++i)
	{
		if (a[i] == -1)
			continue;
		cnt[cl_cnt] = 1;
		for(int j = i + 1; j < n; ++j)
		{
			if (a[j] == -1)
				continue;
			auto x = (ll)a[i] * a[j];
			ll sq = sqrt(x) + 1e-6;
			if (sq * sq == x)
			{
				++cnt[cl_cnt];
				a[j] = -1;
			}
		}
		++cl_cnt;
	}
	int cid = 0;
	int total = 0;
	dp[cid][0][0] = 1;
	for(int i = 0; i < cl_cnt; ++i)
	{
		for(int j = 0; j < cnt[i]; ++j, ++total)
		{
			auto& cdp = dp[cid];
			auto& ndp = dp[cid ^ 1];
			memset(ndp, 0, sizeof ndp);
			for(int b = 0; b < N; ++b)
				for(int cb = 0; cb < N; ++cb)
				{
					auto cur = cdp[b][cb];
					if (cur == 0)
						continue;
					ndp[b][cb + 1] = sum(ndp[b][cb + 1], mul(cur, 2 * j - cb));
					if (b > 0)
						ndp[b - 1][cb] = sum(ndp[b - 1][cb], mul(cur, b));
					ndp[b][cb] = sum(ndp[b][cb], mul(cur, total + 1 - (2 * j - cb) - b));
				}
			cid ^= 1;
		}
		auto& cdp = dp[cid];
		auto& ndp = dp[cid ^ 1];
		memset(ndp, 0, sizeof ndp);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (cdp[i][j] > 0)
					ndp[i + j][0] = sum(ndp[i + j][0], cdp[i][j]);
		cid ^= 1;
	}
	printf("%d\n", dp[cid][0][0]);
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