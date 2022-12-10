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

const int LEN = 13;
const int L = (1 << LEN);
const int N = 210;
int n, m;
int as[N], bs[N];
string s[N];
int ans[N];

struct Str
{
	string pref, suff;
	bitset<L> has;
	Str() {}
	Str(string s, int len) : has()
	{
		if (s.size() >= len)
		{
			pref = s.substr(0, len - 1);
			suff = s.substr(s.size() - len + 1, len - 1);
			int x = 0;
			for (int i = 0; i < len; ++i)
				x = (x << 1) | (s[i] - '0');
			has[x] = true;
			for(int i = len; i < s.size(); ++i)
			{
				x = (x << 1) | (s[i] - '0');
				if (x & (1 << len))
					x ^= (1 << len);
				has[x] = true;
			}
		}
		else
			pref = suff = s;
	}
	Str conc(const Str& s, int len)
	{
		Str res;
		res.pref = pref + s.pref;
		res.suff = suff + s.suff;
		if (res.pref.size() >= len)
		{
			res.pref = res.pref.substr(0, len - 1);
			res.suff = res.suff.substr(res.suff.size() - len + 1, len - 1);
		}
		res.has = has | s.has;
		auto mid = suff + s.pref;
		if (mid.size() >= len)
		{
			int x = 0;
			for (int i = 0; i < len; ++i)
				x = (x << 1) | (mid[i] - '0');
			res.has[x] = true;
			for(int i = len; i < mid.size(); ++i)
			{
				x = (x << 1) | (mid[i] - '0');
				if (x & (1 << len))
					x ^= 1 << len;
				res.has[x] = true;
			}
		}
		return res;
	}
};
Str strs[N];

void solve(int len)
{
	for (int i = 0; i < n; ++i)
		strs[i] = Str(s[i], len);
	for (int i = 0; i < m; ++i)
	{
		strs[n + i] = strs[as[i]].conc(strs[bs[i]], len);
		if (strs[n + i].has.count() == (1 << len))
			ans[i] = len;
	}
}

char buf[N];

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", buf);
		s[i] = buf;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
	{
		scanf("%d%d", &as[i], &bs[i]);
		--as[i], --bs[i];
	}
	for (int len = 1; len <= LEN; ++len)
		solve(len);
	for (int i = 0; i < m; ++i)
		printf("%d\n", ans[i]);
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