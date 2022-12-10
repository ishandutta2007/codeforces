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
#define print_var(x) cout << #x << " : " << (x) << endl
#define print_array(arr, len) {cout << #arr << " : "; for(int i = 0; i < len; ++i) cout << arr[i] << ' '; cout << endl;}
#define print_2d_array(arr, len1, len2) {cout << #arr << endl; for(int i = 0; i < len1; ++i, cout << endl) for(int j = 0; j < len2; ++j) cout << arr[i][j] << ' ';}
#define print_iterable(i) {cout << #i << " : "; for(auto e : i) cout << e << ' '; cout << endl;}
#define print_new_line() cout << endl
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

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-7;
const ld EPS = 1e-13;

#pragma endregion

const int N = 1e5 + 10;
int n, m;
pii segs[N];
int ans[N];

void solve()
{
	scanf("%d%d", &n, &m);
	int l = INF;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		l = min(l, b - a + 1);
	}
	for (int i = 0; i < n; ++i)
		ans[i] = i % l;

	printf("%d\n", l);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("alter.in", "r", stdin);
	//freopen("alter.out", "w", stdout);
#endif

#ifdef ST
	while (true)
	{
		solve();
	}
#endif
#ifdef MULTITEST
	int t;
	scanf("%d", &t);
	while (t--)
#endif
		solve();

	eprintf("\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
}