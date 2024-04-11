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
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#define mp make_pair
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define print_var(x) cout << #x << " : " << (x) << endl
#define print_array(arr, len) {cout << #arr << " : "; for(int i = 0; i < len; ++i) cout << arr[i] << ' '; cout << endl;}
#define print_2d_array(arr, len1, len2) {cout << #arr << endl; for(int i = 0; i < len1; ++i, cout << endl) for(int j = 0; j < len2; ++j) cout << arr[i][j] << ' ';}
#define print_iterable(i) {cout << #i << " : "; for(auto e : i) cout << e << ' '; cout << endl;}
#define print_new_line() cout << endl
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

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-7;
const ld EPS = 1e-11;

#pragma endregion


const int P = 1e9 + 7;
int sum(int a, int b)
{
	a += b;
	return a >= P ? a - P : a;
}
int mul(int a, int b)
{
	return (ll) a * b % P;
}
int bpow(int x, int p)
{
	int res = 1;
	for (; p > 0; p /= 2, x = mul(x, x))
		if (p % 2 == 1)
			res = mul(res, x);
	return res;
}
const int N = 1e6 + 50;
int fact[N], rfact[N], f[N], tmp[N], rev[N];
int p[N], psi;
int d[N];

int cnk(int n, int k)
{
	return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int r;
vector<pii> factor;

int solve(int n)
{
	if (r == 0)
		return f[n];
	--r;
	factor.clear();
	for (; n > 1; n /= d[n])
		if (factor.empty() || factor.back().first != d[n])
			factor.emplace_back(d[n], 1);
		else
			++factor.back().second;
	int ans = 1;
	for(auto f : factor)
	{
		int cnt = f.second;
		int mult = cnk(cnt + r, r);
		for (int i = 0; i < cnt; ++i)
			mult = sum(mult, mul(2, cnk(i + r, r)));
		ans = mul(ans, mult);
	}
	return ans;
}

void prec()
{
	int p = P - 2;
	for (int i = 0; i < N; ++i)
		tmp[i] = fact[i];
	fill(rfact, rfact + N, 1);
	for (; p > 0; p /= 2)
	{
		if (p % 2 == 1)
			for (int i = 1; i < N; ++i)
				rfact[i] = mul(rfact[i], tmp[i]);
		for (int i = 1; i < N; ++i)
			tmp[i] = mul(tmp[i], tmp[i]);
	}
}

void solve()
{
	rfact[0] = fact[0] = 1;
	for (int i = 1; i < N; ++i)
		fact[i] = mul(fact[i - 1], i);
	prec();
	for (int i = 2; i < N; ++i)
	{
		if (d[i] == 0)
		{
			d[i] = i;
			p[psi++] = i;
		}
		for (int j = 0; j < psi && p[j] <= d[i] && p[j] * i < N; ++j)
			d[i * p[j]] = p[j];
	}
	f[1] = 1;
	for (int i = 2; i < N; ++i)
		if (d[i / d[i]] == d[i])
			f[i] = f[i / d[i]];
		else
			f[i] = 2 * f[i / d[i]];
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int n;
		scanf("%d%d", &r, &n);
		printf("%d\n", solve(n));
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
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
	}
#else
		solve();
#endif

	eprintf("\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
}