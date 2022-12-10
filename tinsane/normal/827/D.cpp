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

struct Edge
{
	int to, w, id;
	bool used;
	Edge() : to(), w(), id(), used() {}
	Edge(int to, int w, int id) : to(to), w(w), id(id), used() {}
};
const int N = 2e5 + 10;
const int LOGN = 18;
vector<Edge> go[N];
int n, m;
int ans[N];
int pare[N];
int jumps[N][LOGN];
int give[N][LOGN];
int mx[N][LOGN];
bool used[N];
int h[N];
int tans[N];
struct Comp
{
	bool operator() (const pii& a, const pii& b) const
	{
		return go[a.first][a.second].w > go[b.first][b.second].w;
	}
};

int get_lca(int a, int b)
{
	for(int i = LOGN - 1; i >= 0; --i)
	{
		if (h[jumps[a][i]] >= h[b])
			a = jumps[a][i];
		if (h[jumps[b][i]] >= h[a])
			b = jumps[b][i];
	}
	if (a == b)
		return a;
	for(int i = LOGN - 1; i >= 0; --i)
	{
		if (jumps[a][i] != jumps[b][i])
		{
			a = jumps[a][i];
			b = jumps[b][i];
		}
	}
	return jumps[a][0];
}

int lift(int v, int finh, int w)
{
	int res = -1;
	for(int i = LOGN - 1; i >= 0; --i)
	{
		auto jump = jumps[v][i];
		if (h[jump] >= finh)
		{
			res = max(res, mx[v][i]);
			give[v][i] = min(give[v][i], w);
			v = jump;
		}
	}
	return res;
}

void solve(int root)
{
	used[root] = true;
	priority_queue < pii, vector<pii>, Comp > q;
	for (int i = 0; i < go[root].size(); ++i)
		q.emplace(root, i);
	vector<int> comp;
	vector<pii> backe;
	for (int i = 0; i < LOGN; ++i)
		jumps[root][i] = root;
	while(!q.empty())
	{
		auto t = q.top();
		q.pop();
		int v = t.first;
		auto& e = go[v][t.second];
		if (used[e.to])
		{
			if (e.to > v)
				backe.push_back(t);
			continue;
		}
		used[e.to] = true;
		h[e.to] = h[v] + 1;
		comp.push_back(e.to);
		for (int i = 0; i < go[e.to].size(); ++i)
		{
			if (go[e.to][i].to == v)
			{
				pare[e.to] = i;
				mx[e.to][0] = e.w;
				jumps[e.to][0] = v;
				for (int i = 1; i < LOGN; ++i)
				{
					int jump = jumps[e.to][i - 1];
					jumps[e.to][i] = jumps[jump][i - 1];
					mx[e.to][i] = max(mx[e.to][i - 1], mx[jump][i-1]);
				}
			}
			else
				q.emplace(e.to, i);
		}
	}
	for(auto eid : backe)
	{
		int v = eid.first;
		auto& e = go[v][eid.second];
		auto u = e.to;
		auto w = e.w;
		int lca = get_lca(u, v);
		ans[e.id] = max(lift(u, h[lca], w), lift(v, h[lca], w)) - 1;
	}
	reverse(comp.begin(), comp.end());
	for (auto v : comp)
	{
		for(int i = LOGN - 1; i > 0; --i)
		{
			give[v][i - 1] = min(give[v][i - 1], give[v][i]);
			give[jumps[v][i - 1]][i - 1] = min(give[jumps[v][i - 1]][i - 1], give[v][i]);
		}
		int id = go[v][pare[v]].id;
		if (give[v][0] == INF)
			ans[id] = -1;
		else
			ans[id] = give[v][0] - 1;
	}
}

#ifdef LOCAL
//#define ST
struct Edge1
{
	int a, b, w, id;
	Edge1(int a, int b, int w, int id) : a(a), b(b), w(w), id(id) {}
};
vector<Edge1> edges;
#endif

void slow()
{
	for(int i = 0; i < m; ++i)
	{
		int lb = 0;
		int rb = INF;
		while(rb - lb > 1)
		{
			
		}
		if (rb == INF)
			tans[i] = -1;
		else
			tans[i] = rb;
	}
}

void solve()
{
	memset(pare, -1, sizeof pare);
	memset(used, false, sizeof used);
	memset(h, 0, sizeof h);
#ifndef ST
	scanf("%d%d", &n, &m);
#else
	n = 4;
	m = rand() % min(10LL, (ll)n * (n - 1) / 2) + 1;
	set<pii> has;
	for (int i = 0; i < n; ++i)
		go[i].clear();
#endif
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < LOGN; ++j)
		{
			mx[i][j] = -1;
			give[i][j] = INF;
		}
	for(int i = 0; i < m; ++i)
	{
		int a, b, w;
#ifndef ST
		scanf("%d%d%d", &a, &b, &w);
#else
		while(true)
		{
			a = rand() % n + 1;
			b = rand() % n + 1;
			if (a >= b || has.count({ a, b }))
				continue;
			has.emplace(a, b);
			break;
		}
		w = rand() % 10 + 1;
#endif
		--a, --b;
#ifdef ST
		edges.emplace_back(a, b, w, i);
#endif
		go[a].emplace_back(b, w, i);
		go[b].emplace_back(a, w, i);
	}
	for (int i = 0; i < n; ++i)
		if (!used[i])
			solve(i);
#ifndef ST
	for (int i = 0; i < m; ++i)
		printf("%d ", ans[i]);
	puts("");
#else
	slow();
	for(int i = 0; i < m; ++i)
	{
		if (ans[i] != tans[i])
		{
			print_array(ans, m);
			print_array(tans, m);
			printf("%d %d\n", n, m);
			vector<int> a(m), b(m), w(m);
			for (int i = 0; i < n; ++i)
				for (auto e : go[i])
				{
					a[e.id] = i;
					b[e.id] = e.to;
					w[e.id] = e.w;
				}
			for (int i = 0; i < m; ++i)
				printf("%d %d %d\n", a[i] + 1, b[i] + 1, w[i] + 1);
			exit(0);
		}
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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
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