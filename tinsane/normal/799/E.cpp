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

#ifdef LOCAL
#define ERR_CATCH
//#define NOERR
#endif

const int N = 2e5 + 10;
int n, m, k;
int cost[N];
bool in_a[N];
bool in_b[N];
ll ans = LINF;
vector<pii> inter, a, b, out;
set<pii> bad, need;
ll ncost;

void add_need(int id)
{
	bad.erase({cost[id], id});
	need.emplace(cost[id], id);
	ncost += cost[id];
}

void del_need(int id)
{
	need.erase({ cost[id], id });
	bad.emplace(cost[id], id);
	ncost -= cost[id];
}

void balance()
{
	if (bad.empty() || need.empty())
		return;
	while (true)
	{
		auto b = *bad.begin();
		auto e = *prev(need.end());
		if (b.first < e.first)
		{
			del_need(e.second);
			add_need(b.second);
		}
		else
			break;
	}
}

void add_win(int id)
{
	auto p = mp(cost[id], id);
	if (bad.count(p))
	{
		bad.erase(p);
		ncost += cost[id];
	}
	else
		need.erase(p);
}

void del_win(int id)
{
	int x = cost[id];
	ncost -= x;
	bad.emplace(x, id);
}

void scan_fill(bool a[])
{
	int cnt;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; ++i)
	{
		int x;
		scanf("%d", &x);
		--x;
		a[x] = true;
	}
}

void solve()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &cost[i]);

	scan_fill(in_a);
	scan_fill(in_b);

	for (int i = 0; i < n; ++i)
	{
		if (in_a[i] && in_b[i])
			inter.emplace_back(cost[i], i);
		else if (in_a[i])
			a.emplace_back(cost[i], i);
		else if (in_b[i])
			b.emplace_back(cost[i], i);
		else
			out.emplace_back(cost[i], i);
	}

	sort(inter.begin(), inter.end());
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(out.begin(), out.end());

	int ita = 0;
	int itb = 0;
	for (auto e : a)
		bad.insert(e);
	for (auto e : b)
		bad.insert(e);
	for (auto e : out)
		bad.insert(e);
	for (auto e : inter)
		ncost += e.first;
	for (int i = inter.size(); i >= 0; --i)
	{
		if (i != inter.size())
		{
			auto x = inter[i];
			del_win(x.second);
		}
		if (i > m || i + min(a.size(), b.size()) < k)
			continue;
		for (; i + ita < k; ++ita)
			add_win(a[ita].second);
		for (; i + itb < k; ++itb)
			add_win(b[itb].second);

		int has = i + ita + itb;
		if (has > m)
			continue;
		while(need.size() > m - has)
		{
			auto e = *prev(need.end());
			del_need(e.second);
		}
		while(need.size() < m - has)
		{
			auto e = *bad.begin();
			add_need(e.second);
		}
		balance();

		if (has + need.size() == m)
			ans = min(ans, ncost);
	}
	
	if (ans == LINF)
		puts("-1");
	else
		printf("%lld\n", ans);
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
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
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

	eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
}