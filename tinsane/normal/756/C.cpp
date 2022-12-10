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
const ld EPS = 1e-11;

#pragma endregion

const int N = 1e5 + 10;
int n;

struct Segt
{
	int a[4 * N];
	int top[4 * N];
	void init()
	{
		fill(a, a + 4 * n, -INF);
		memset(top, 0, sizeof top);
	}
	void apply(int ind, int v)
	{
		a[ind] += v;
		top[ind] += v;
	}
	void push(int ind)
	{
		if (top[ind] == 0)
			return;
		apply(ind * 2, top[ind]);
		apply(ind * 2 + 1, top[ind]);
		top[ind] = 0;
	}
	void add(int ind, int l, int r, int L, int R, int v)
	{
		if (L <= l && r <= R)
		{
			apply(ind, v);
			return;
		}
		if (r < L || R < l)
			return;
		push(ind);
		int m = (l + r) / 2;
		add(ind * 2, l, m, L, R, v);
		add(ind * 2 + 1, m + 1, r, L, R, v);
		a[ind] = max(a[ind * 2], a[ind * 2 + 1]);
	}
	void add(int l, int r, int v)
	{
		add(1, 0, n - 1, l, r, v);
	}
	int find(int ind, int l, int r)
	{
		if (l == r)
			return l;
		push(ind);
		int m = (l + r) / 2;
		if (a[ind * 2 + 1] > 0)
			return find(ind * 2 + 1, m + 1, r);
		else
			return find(ind * 2, l, m);
	}
	int find()
	{
		if (a[1] <= 0)
			return -1;
		return find(1, 0, n - 1);
	}
} segt;

int xs[N];

void solve()
{
	scanf("%d", &n);
	segt.init();
	for (int i = 0; i < n; ++i)
	{
		int p, t;
		scanf("%d%d", &p, &t);
		--p;
		if (t == 0)
			segt.add(0, p, -1);
		else
		{
			scanf("%d", &xs[p]);
			segt.add(p, p, INF);
			segt.add(0, p, 1);
		}
		int ind = segt.find();
		if (ind != -1)
			printf("%d\n", xs[ind]);
		else
			puts("-1");
	}
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