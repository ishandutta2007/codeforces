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

const int N = 3e5 + 10;
const int B = 550;
const int NB = N / B + 1;
int n, q;
int a[N];
int ans[N];
struct Query
{
	int l, r, k, id;
	void read(int id)
	{
		this->id = id;
		scanf("%d%d%d", &l, &r, &k);
		--l, --r;
	}
	int need() const
	{
		return (r - l + 1) / k;
	}
	bool operator< (const Query& q) const
	{
		return r < q.r;
	}
	void gen(int n)
	{
		l = rand() % n;
		r = rand() % n;
		if (l > r)
			swap(l, r);
		k = rand() % 4 + 2;
	}
};
vector<Query> bucks[NB];
const int K = 4;
struct Ord
{
	vector<int> was;
	int cnt[N];
	int best[K];
	Ord() : cnt(), was()
	{
		memset(best, -1, sizeof best);
	}
	void clear()
	{
		for (auto e : was)
			cnt[e] = 0;
		was.clear();
		memset(best, -1, sizeof best);
	}
	void safe_add(int x)
	{
		++cnt[x];
		bool in = false;
		for (auto e : best)
			in |= e == x;
		if (in)
			return;
		for (int i = 0; i < K; ++i)
			if (best[i] == -1 || cnt[best[i]] < cnt[x])
			{
				best[i] = x;
				break;
			}
	}
	void add(int x)
	{
		if (cnt[x] == 0)
			was.push_back(x);
		safe_add(x);
	}
} ord;

void set_ans(const Query& q)
{
	int res = INF;
	for (auto e : ord.best)
	{
		if (e == -1)
			continue;
		if (ord.cnt[e] > q.need() && e < res)
			res = e;
	}
	if (res != INF)
		ans[q.id] = res;
}

void stupid(const Query& q)
{
	ord.clear();
	for (int i = q.l; i <= q.r; ++i)
		ord.add(a[i]);
	set_ans(q);
}

void solve_b(int id)
{
	ord.clear();
	sort(bucks[id].begin(), bucks[id].end());
	int cur = (id + 1) * B;
	for(const auto& q : bucks[id])
	{
		while (cur <= q.r)
			ord.add(a[cur++]);
		int cur_best[K];
		memcpy(cur_best, ord.best, sizeof ord.best);
		for (int i = (id + 1) * B - 1; i >= q.l; --i)
			ord.safe_add(a[i]);
		set_ans(q);
		for (int i = (id + 1) * B - 1; i >= q.l; --i)
			--ord.cnt[a[i]];
		memcpy(ord.best, cur_best, sizeof cur_best);
	}
	bucks[id].clear();
}

#ifdef LOCAL
//#define ST
vector<Query> qs;
int sans[N];
void stupid1(Query q)
{
	map<int, int> cnt;
	for (int i = q.l; i <= q.r; ++i)
		++cnt[a[i]];
	int res = INF;
	for (auto p : cnt)
		if (p.second > q.need())
			res = min(res, p.first);
	sans[q.id] = res == INF ? -1 : res;
}
#endif

void solve()
{
#ifndef ST
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
#else
	n = rand() % 30 + 1;
	q = rand() % 50 + 1;
	for (int i = 0; i < n; ++i)
		a[i] = rand() % n;
	qs.clear();
#endif
	memset(ans, -1, sizeof ans);
	for(int i = 0; i < q; ++i)
	{
		Query qu;
#ifndef ST
		qu.read(i);
#else
		qu.gen(n);
		qu.id = i;
		qs.push_back(qu);
		stupid1(qu);
#endif
		if (qu.r - qu.l <= B)
			stupid(qu);
		else
			bucks[qu.l / B].push_back(qu);
	}
	for (int i = 0; i < NB; ++i)
		solve_b(i);
#ifndef ST
	for (int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);
#else
	for(int i = 0; i < q; ++i)
		if (ans[i] != sans[i])
		{
			eprintf("%d %d\n", n, q);
			for (int i = 0; i < n; ++i)
				eprintf("%d ", a[i]);
			eprintf("\n");
			for (auto q : qs)
				eprintf("%d %d %d\n", q.l + 1, q.r + 1, q.k);
			print_array(sans, q);
			print_array(ans, q);
			exit(0);
		}
#endif
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