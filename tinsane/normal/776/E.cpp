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

const int P = 1e9 + 7;
const int N = 1e6 + 100;
int p[N], d[N], psz;

int f(int x)
{
	int ans = 1;
	while(x != 1)
	{
		int cd = d[x];
		ans *= cd - 1;
		x /= cd;
		for (; d[x] == cd; x /= cd, ans *= cd);
	}
	return ans;
}

int g(int x)
{
	int ans = 0;
	for (int d = 1; d <= x; ++d)
		if (x % d == 0)
			ans += f(d);
	return ans;
}

ll ff(ll x)
{
	ll ans = 1;
	for (ll d = 2; d * d <= x; ++d)
	{
		if (x % d != 0)
			continue;
		x /= d;
		ans *= d - 1;
		for (; x % d == 0; x /= d, ans *= d);
	}
	if (x != 1)
		ans *= x - 1;
	return ans;
}

void solve()
{
	//for (int i = 0; i < N; ++i)
	//	d[i] = i;
	//for (int i = 2; i < N; ++i)
	//{
	//	if (d[i] == i)
	//		p[psz++] = i;
	//	for (int j = 0; j < psz && p[j] <= d[i] && i * p[j] < N; ++j)
	//		d[i * p[j]] = p[j];
	//}
	//for (int i = 1; i <= 20; ++i)
	//	printf("%d : %d\n", i, g(i));
	//return;
	ll n, k;
	cin >> n >> k;
	for (int i = 0; i <= k && n > 1; ++i)
	{
		if (i % 2 == 1)
			n = ff(n);
	}
	cout << n % P;
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