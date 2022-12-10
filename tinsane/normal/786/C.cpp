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

const int N = 3e5 + 10;

struct Node
{
	int sum;
	Node* lf, *rg;
	Node() : sum(), lf(), rg() {}
	Node(int sum, Node* lf, Node* rg) : sum(sum), lf(lf), rg(rg) {}
	Node* add(int l, int r, int p, int v)
	{
		if (l == r)
			return new Node(sum + v, lf, rg);
		int m = (l + r) / 2;
		Node *nlf = lf;
		Node *nrg = rg;
		if (p <= m)
			nlf = lf->add(l, m, p, v);
		else
			nrg = rg->add(m + 1, r, p, v);
		return new Node(nlf->sum + nrg->sum, nlf, nrg);
	}

	int get(int l, int r, int s)
	{
		if (l == r)
			return l;
		int m = (l + r) / 2;
		if (lf->sum >= s)
			return lf->get(l, m, s);
		else
			return rg->get(m + 1, r, s - lf->sum);
	}
};

Node* build(int l, int r)
{
	if (l == r)
		return new Node();
	int m = (l + r) / 2;
	return new Node(0, build(l, m), build(m + 1, r));
}

int n, k;
int a[N];
int lst[N];
bool beg[N];
Node* segts[N];

int solve(int k)
{
	int res = 0;
	int now = 0;

	for (int now = 0; now != n; now = segts[now]->get(0, n, k + 1))
		++res;

	return res;
}

void solve()
{
	scanf("%d", &n);
	segts[0] = build(0, n);
	fill(lst, lst + N, n);
	memset(beg, true, sizeof beg);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	print_array(a, n);
	for (int i = n - 1; i >= 0; --i)
	{
		int col = a[i];
		a[i] = lst[a[i]];
		beg[a[i]] = false;
		lst[col] = i;
	}

	print_array(a, n);
	print_array(beg, n);

	for (int i = 0; i < n; ++i)
		if (beg[i])
			segts[0] = segts[0]->add(0, n, i, 1);

	for (int i = 0; i < n; ++i)
	{
		segts[i + 1] = segts[i]->add(0, n, i, -1);
		segts[i + 1] = segts[i + 1]->add(0, n, a[i], 1);
	}

	for (k = 1; k <= n; ++k)
		printf("%d ", solve(k));
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