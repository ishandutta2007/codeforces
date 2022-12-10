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

struct Edge
{
	int l, r, cost;
	Edge(int l, int r, int cost) : l(l), r(r), cost(cost) {}
};
#ifdef LOCAL
const int N = 1e3;
#else
const int N = 4e5 + 10;
#endif
int n, q, s;

struct Segt
{
	ll val[N];
	ll f[N];
	bool used[N];
	vector<Edge> edges[N];

	Segt() : used()
	{
		fill(val, val + N, LINF);
		fill(f, f + N, LINF);
	}

	void apply(int ind, ll v)
	{
		if (used[ind])
			return;
		f[ind] = min(f[ind], v);
		val[ind] = min(val[ind], v);
	}

	void push(int ind)
	{
		apply(ind * 2, f[ind]);
		apply(ind * 2 + 1, f[ind]);
		f[ind] = LINF;
	}

	void upd(int ind)
	{
		if (used[ind * 2] && used[ind * 2 + 1])
		{
			used[ind] = true;
			val[ind] = LINF;
			return;
		}
		val[ind] = LINF;
		if (!used[ind * 2])
			val[ind] = min(val[ind], val[ind * 2]);
		if (!used[ind * 2 + 1])
			val[ind] = min(val[ind], val[ind * 2 + 1]);
	}

	void add_edge(int ind, int l, int r, int L, int R, const Edge& e)
	{
		if (L <= l && r <= R)
		{
			edges[ind].push_back(e);
			return;
		}
		if (r < L || R < l)
			return;
		int m = (l + r) / 2;
		add_edge(ind * 2, l, m, L, R, e);
		add_edge(ind * 2 + 1, m + 1, r, L, R, e);
	}

	void add_edge(int l, int r, const Edge& e)
	{
		add_edge(1, 0, n - 1, l, r, e);
	}

	pli getmi(int ind, int l, int r)
	{
		if (l == r)
		{
			ll res = val[ind];
			val[ind] = LINF;
			used[ind] = true;
			return { res, l };
		}
		push(ind);
		int m = (l + r) / 2;
		pli res;
		if (used[ind * 2])
			res = getmi(ind * 2 + 1, m + 1, r);
		else if (used[ind * 2 + 1])
			res = getmi(ind * 2, l, m);
		else if (val[ind * 2] == val[ind])
			res = getmi(ind * 2, l, m);
		else
			res = getmi(ind * 2 + 1, m + 1, r);
		upd(ind);
		return res;
	}

	pli getmi()
	{
		return getmi(1, 0, n - 1);
	}

	void minize(int ind, int l, int r, int L, int R, ll v)
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
		minize(ind * 2, l, m, L, R, v);
		minize(ind * 2 + 1, m + 1, r, L, R, v);
		upd(ind);
	}

	void minize(int l, int r, ll v)
	{
		minize(1, 0, n - 1, l, r, v);
	}

	void go(int ind, int l, int r, int p, ll cost)
	{ 
		for (; !edges[ind].empty(); edges[ind].pop_back())
		{
			auto& e = edges[ind].back();
			minize(e.l, e.r, cost + e.cost);
		}
		if (l == r)
			return;
		int m = (l + r) / 2;
		if (p <= m)
			go(ind * 2, l, m, p, cost);
		else
			go(ind * 2 + 1, m + 1, r, p, cost);
	}

	void go(int p, ll cost)
	{
		go(1, 0, n - 1, p, cost);
	}
} segt;

void scan_q()
{
	int t;
	scanf("%d", &t);
	int lf, rf, lt, rt, w;
	switch (t)
	{
	case 1:
		scanf("%d%d%d", &lf, &lt, &w);
		--lf, --lt;
		segt.add_edge(lf, lf, Edge(lt, lt, w));
		break;
	case 2:
		scanf("%d%d%d%d", &lf, &lt, &rt, &w);
		--lf, --lt, --rt;
		segt.add_edge(lf, lf, Edge(lt, rt, w));
		break;
	case 3:
		scanf("%d%d%d%d", &lt, &lf, &rf, &w);
		--lf, --rf, --lt;
		segt.add_edge(lf, rf, Edge(lt, lt, w));
		break;
	default:
		throw;
	}
}

ll ans[N];

void solve()
{
	scanf("%d%d%d", &n, &q, &s);
	memset(ans, -1, sizeof ans);
	--s;
	for (int i = 0; i < q; ++i)
		scan_q();
	segt.minize(s, s, 0);
	while(true)
	{
		auto mi = segt.getmi();
		if (mi.first == LINF)
			break;
		int v = mi.second;
		ll cost = mi.first;
		ans[v] = cost;
		segt.go(v, cost);
	}
	for (int i = 0; i < n; ++i)
		printf("%lld ", ans[i]);
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