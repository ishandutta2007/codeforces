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
#endif

const int N = 1e5 + 10;
const int P = 45;
int n;
int p2[P];
int rem[P];
int tp2[P];
int tmp[P];
int chains;

bool is_p2(ll x)
{
	return !(x & (x - 1));
}

bool can(int cnt)
{
	memcpy(tp2, p2, sizeof p2);
	memcpy(tmp, rem, sizeof rem);
	int cur = chains;
	for (int i = 0; i < P; ++i)
	{
		int d = min(tp2[i], cur - cnt);
		tp2[i] -= d;
		for (int j = 0; j <= i; ++j)
			tmp[j] += d;
		cur -= d;
	}
	int tit = P - 1;
	for (int i = P - 1; i >= 0;)
	{
		for (; tit >= 0 && tmp[tit] == 0; --tit);
		if (tit > i)
			return false;
		if (tit == -1)
			break;
		int d = min(tmp[tit], tp2[i]);
		tmp[tit] -= d;
		tp2[i] -= d;
		if (tp2[i] == 0)
			--i;
	}
	for (; tit >= 0 && tmp[tit] == 0; --tit);
	return tit == -1;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		ll a;
		scanf("%lld", &a);
		int hb = 0;
		for (ll ta = a; ta > 1; ta >>= 1)
			++hb;
		if (is_p2(a))
			++p2[hb];
		else
			++rem[hb];
	}
	for (int i = 1; i < P; ++i)
		if (p2[i] > p2[i - 1])
		{
			rem[i] += p2[i] - p2[i - 1];
			p2[i] = p2[i - 1];
		}
	print_iterable(rem);
	chains = p2[0];
	for (int i = 1; i < P; ++i)
		p2[i - 1] -= p2[i];
	print_iterable(p2);
	if (!can(chains))
	{
		puts("-1");
		return;
	}
	int mx = chains;
	int l = 0;
	int r = mx;
	while(r - l > 1)
	{
		int m = (l + r) / 2;
		if (can(m))
			r = m;
		else
			l = m;
	}
	for (; r <= mx; ++r)
		printf("%d ", r);
	puts("");
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