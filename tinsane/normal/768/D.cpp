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

const int N = 1010;
const int X = 1e4 + 10;
int k, q;
ld dp[N], dp_n[N];
ld days[X];

void solve()
{
	scanf("%d%d", &k, &q);
	dp[0] = 1;
	for (int it = 0; it < X; ++it)
	{
		ld s = 0;
		for (int i = 0; i <= k; ++i)
			s += dp[i];
		for (int i = 0; i <= k; ++i)
			dp[i] /= s;
		days[it] = dp[k];
		fill(dp_n, dp_n + k + 1, 0);
		for (int i = 0; i <= k; ++i)
		{
			dp_n[i] += dp[i] * i / k;
			dp_n[i + 1] += dp[i] * (k - i) / k;
		}
		//print_array(dp, 10);
		memcpy(dp, dp_n, sizeof dp_n);
	}
	for (int i = 0; i < q; ++i)
	{
		int d;
		scanf("%d", &d);
		for (int i = 0; i < X; ++i)
			if(d < days[i] * 2000)
			{
				printf("%d\n", i);
				break;
			}
	}
	//printf("%.10lf\n", (double)days[X - 1]);
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