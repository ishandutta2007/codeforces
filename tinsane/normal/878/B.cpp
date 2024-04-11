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
#define dbg(x) cerr << #x << " : " << (x) << endl
#define dbga(arr, len) {cerr << #arr << " : "; for(int i = 0; i < len; ++i) cerr << arr[i] << ' '; cerr << endl;}
#define dbg2da(arr, len1, len2) {cerr << #arr << endl; for(int i = 0; i < len1; ++i, cerr << endl) for(int j = 0; j < len2; ++j) cerr << arr[i][j] << ' ';}
#define dbgi(i) {cerr << #i << " : "; for(auto e : i) cerr << e << ' '; cerr << endl;}
#else
#define eprintf(...) (void)0
#define dbg(x) (void)0
#define dbga(arr, len) {}
#define dbg2da(arr, len1, len2) {}
#define dbgi(i) {}
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int INF = (int)1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-8;
#pragma endregion

#ifdef LOCAL
#define ERR_CATCH
//#define NOERR
#endif

const int N = 4e5 + 10;
const int LOGN = 31;
int n, k, m;
int a[N];
vector<pii> ca[LOGN];
ll sec_out = 0;

vector<pii> merge(const vector<pii>& a, vector<pii> b)
{
	sec_out = 0;
	vector<pii> res = a;
	for(auto e : b)
	{
		if (!res.empty() && e.first == res.back().first)
		{
			res.back().second += e.second;
			if (res.back().second >= k)
			{
				res.back().second -= k;
				sec_out += e.second;
				if (res.back().second == 0)
					res.pop_back();
			}
		}
		else
			res.push_back(e);
	}
	return res;
}

ll calc(const vector<pii>& v)
{
	ll res = 0;
	for (auto e : v)
		res += e.second;
	return res;
}

void solve()
{
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		if (ca[0].empty() || ca[0].back().first != a[i])
			ca[0].emplace_back(a[i], 1);
		else if (++ca[0].back().second == k)
			ca[0].pop_back();
	}
	int i = 1;
	for(; i < LOGN; ++i)
	{
		ca[i] = merge(ca[i - 1], ca[i - 1]);
		if (ca[i].size() >= N)
			break;
	}
	--i;
	auto full = m / (1 << i);
	dbg(full);
	if (full < 2)
	{
		vector<pii> now;
		for (int j = LOGN - 1; j >= 0; --j)
			if (m & (1 << j))
				now = merge(now, ca[j]);
		printf("%lld\n", calc(now));
		return;
	}
	dbg("ME");
	ll diff = 2 * calc(ca[i]) - calc(ca[i + 1]);
	vector<pii> now;
	for (int j = i - 1; j >= 0; --j)
		if (m & (1 << j))
			now = merge(now, ca[j]);

	now = merge(now, ca[i]);
	
	--full;
	ll ans = (ll)full * (calc(ca[i]) - diff) + calc(now);
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
		dbg(e.what());
		puts("___________________________________________________________________________");
		exit(0);
	}
#endif
#ifdef LOCAL
	eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
#endif
}