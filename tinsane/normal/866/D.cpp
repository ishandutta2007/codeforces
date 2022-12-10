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

template <typename T, typename Q>
ostream& operator<<(ostream& os, pair<T, Q> p)
{
	return (os << '(' << p.first << ", " << p.second << ')');
}

#define mp make_pair
#define rand govno_ebanoe
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

const int N = 3e5 + 10;
int n;
int p[N];

#ifdef LOCAL
const int SN = 400;
const int SX = 1e6;
ll dp[SN + 1][SN + 1];
ll slow()
{
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for(int j = 0; j <= i; ++j)
		{
			dp[i][j] = dp[i - 1][j];
			if (j > i - 1)
				dp[i][j] = -LINF;
			if (j > 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - p[i - 1]);
			if (j + 1 <= i - 1)
				dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + p[i - 1]);
		}
	return dp[n][0];
}
mt19937 rnd(100500);
//#define ST
#endif

struct Segt
{
	int arr[4 * N];
	int to_p[4 * N];
	void clear(int ind, int l, int r)
	{
		to_p[ind] = arr[ind] = 0;
		if (l == r)
			return;
		auto m = (l + r) / 2;
		clear(ind * 2, l, m);
		clear(ind * 2 + 1, m + 1, r);
	}
	void clear(int len)
	{
		clear(1, 0, len - 1);
	}
	void apply(int p, int v)
	{
		to_p[p] += v;
		arr[p] += v;
	}
	void push(int ind)
	{
		if (to_p[ind] == 0)
			return;
		apply(ind * 2, to_p[ind]);
		apply(ind * 2 + 1, to_p[ind]);
		to_p[ind] = 0;
	}
	void add(int ind, int l, int r, int L, int R, int v)
	{
		if (L <= l && r <= R)
		{
			apply(ind, v);
			return;
		}
		if (R < l || r < L)
			return;
		push(ind);
		auto m = (l + r) / 2;
		add(ind * 2, l, m, L, R, v);
		add(ind * 2 + 1, m + 1, r, L, R, v);
		arr[ind] = min(arr[ind * 2], arr[ind * 2 + 1]);
	}
	void add(int l, int r, int v)
	{
		add(1, 0, n - 1, l, r, v);
	}
	int get(int ind, int l, int r, int L, int R)
	{
		if (L <= l && r <= R)
			return arr[ind];
		if (R < l || r < L)
			return INF;
		push(ind);
		auto m = (l + r) / 2;
		return min(get(ind * 2, l, m, L, R),
			get(ind * 2 + 1, m + 1, r, L, R));
	}
	int get(int l, int r)
	{
		return get(1, 0, n - 1, l, r);
	}
} segt;

void solve()
{
#ifndef ST
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &p[i]);
#else
	n = rnd() % (SN - 1) + 1;
	for (int i = 0; i < n; ++i)
		p[i] = rnd() % SX;
#endif
	segt.clear(n);
	for (int i = n - 1; i >= 0; --i)
		segt.add(0, i, 1);
	set<pii> poses;
	for (int i = 0; i < n; ++i)
		poses.emplace(p[i], -i);
	ll ans = 0;
	//print_array(p, n);
	for(auto e : poses)
	{
		auto pos = -e.second;
		auto v = e.first;
		auto bal = segt.get(0, pos);
		if (bal >= 2)
		{
			ans -= v;
			segt.add(0, pos, -2);
		}
		else if (bal == 1)
			segt.add(0, pos, -1);
		else
			ans += v;
	}

	//bool used[SN] = {};
	//bool grab[SN] = {};
	//int bal[SN] = {};
	//for(int it = 0; it < n; ++it)
	//{
	//	int id = -1;
	//	for (int i = n - 1; i >= 0; --i)
	//		if (!used[i] && (id == -1 || p[id] > p[i]))
	//			id = i;
	//	if (id == -1)
	//		break;
	//	used[id] = true;
	//	int mi = 3;
	//	for (int i = 0; i <= id; ++i)
	//		mi = min(mi, n - i - bal[i]);
	//	if (mi >= 2)
	//	{
	//		for (int i = 0; i <= id; ++i)
	//			bal[i] += 2;
	//		grab[id] = true;
	//		ans -= p[id];
	//	}
	//	else if (mi != 0)
	//		for (int i = 0; i <= id; ++i)
	//			bal[i] += 1;
	//	else
	//		ans += p[id];
	//}
	//priority_queue<int> q;
	//for (int i = n - 1; i >= 0; --i)
	//	if (!grab[i])
	//		q.push(p[i]);
	//	else
	//	{
	//		auto t = q.top();
	//		q.pop();
	//		ans += t - p[i];
	//	}
#ifdef ST
	auto sans = slow();
	print_var(ans);
	if (ans != sans)
	{
		print_var(ans);
		print_var(sans);
		printf("%d\n", n);
		for (int i = 0; i < n; ++i)
			printf("%d ", p[i]);
		exit(0);
	}
#else
	printf("%lld\n", ans);
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
#ifdef LOCAL
	eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
#endif
}