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

const int N = 14e3 + 10;
int n;
int k1, k2;
int a1[N], a2[N];
int t[N];
int deg[N];
int wave[N], wsi;
bool in_wave[N];
bool to_l[N];

int sub(int a, int b)
{
	a -= b;
	return a >= 0 ? a : a + n;
}

string res[] = { "Loop", "Win", "Lose" };

void add(int v)
{
	if (in_wave[v])
		return;
	in_wave[v] = true;
	wave[wsi++] = v;
}

void upd(int v)
{
	t[v] = to_l[v] ? 1 : 2;
	int pos = v / 2;
	bool pl = v & 1;
	if (pl)
	{
		for (int i = 0; i < k1; ++i)
		{
			int npos = sub(pos, a1[i]);
			int nv = npos * 2;
			if (t[v] == 1)
			{
				--deg[nv];
				if (deg[nv] == 0)
					add(nv);
			}
			else
			{
				to_l[nv] = true;
				add(nv);
			}
		}
	}
	else
	{
		for (int i = 0; i < k2; ++i)
		{
			int npos = sub(pos, a2[i]);
			int nv = npos * 2 + 1;
			if (t[v] == 1)
			{
				--deg[nv];
				if (deg[nv] == 0)
					add(nv);
			}
			else
			{
				to_l[nv] = true;
				add(nv);
			}
		}
	}
}

void solve()
{
	scanf("%d", &n);
	scanf("%d", &k1);
	for (int i = 0; i < k1; ++i)
		scanf("%d", &a1[i]);
	scanf("%d", &k2);
	for (int i = 0; i < k2; ++i)
		scanf("%d", &a2[i]);
	for (int i = 1; i < n; ++i)
	{
		deg[2 * i] = k1;
		deg[2 * i + 1] = k2;
	}
	add(0);
	add(1);
	for (int i = 0; i < wsi; ++i)
		upd(wave[i]);
	for (int i = 1; i < n; ++i)
		printf("%s ", res[t[2 * i]].c_str());
	puts("");
	for (int i = 1; i < n; ++i)
		printf("%s ", res[t[2 * i + 1]].c_str());
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