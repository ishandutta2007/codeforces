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

const int N = 1e6 + 10;
const int T = 100;
int n, k;
int odd;
vector<int> cycs;
int p[N];
bool dp1[N];
bitset<N> dp2;

void solve_mi()
{
	sort(cycs.begin(), cycs.end());
	vector<pii> ps;
	for (auto c : cycs)
		if (ps.empty() || ps.back().second != c)
			ps.emplace_back(1, c);
		else
			++ps.back().first;
	sort(ps.begin(), ps.end());
	reverse(ps.begin(), ps.end());
	dp1[0] = true;
	for (int it = 0; it < min(T, (int)ps.size()); ++it)
	{
		int cnt = ps[it].first;
		int val = ps[it].second;
		for (int i = n - 1; i >= 0; --i)
		{
			if (!dp1[i])
				continue;
			int v = i + val;
			for (int j = 0; j < cnt && v <= n; ++j, v += val)
				if (dp1[v])
					break;
				else
					dp1[v] = true;
		}
	}
	dp2[0] = 1;
	for (int it = T; it < ps.size(); ++it)
	{
		int cnt = ps[it].first;
		int val = ps[it].second;
		for (int i = 0; i < cnt; ++i)
			dp2 = dp2 | (dp2 << val);
	}
	for (int i = 0; i <= k; ++i)
		if (dp1[i]  && dp2[k - i])
		{
			printf("%d ", k);
			return;
		}
	printf("%d ", k + 1);
}

void solve_ma()
{
	int ps = (n - odd) / 2;
	if (k <= ps)
		printf("%d\n", k * 2);
	else
		printf("%d\n", min(n, k + ps));
}

void solve()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &p[i]);
		--p[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if (p[i] == -1)
			continue;
		int v = i;
		int len = 0;
		while(v != -1)
		{
			int to = p[v];
			p[v] = -1;
			v = to;
			++len;
		}
		cycs.push_back(len - 1);
	}
	for (auto c : cycs)
		odd += c % 2;
	solve_mi();
	solve_ma();
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