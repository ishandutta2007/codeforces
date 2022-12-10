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
const int N = 1e6 + 10;
int n, m;
int gsi = 1;
int gnum[N];
int a[N], cnt[N], fact[N];

void solve()
{
	fact[0] = 1;
	for (int i = 1; i < N; ++i)
		fact[i] = mul(fact[i - 1], i);
	scanf("%d%d", &n, &m);
	while(n--)
	{
		int si;
		scanf("%d", &si);
		for (int i = 0; i < si; ++i)
		{
			int pok;
			scanf("%d", &pok);
			--pok;
			++cnt[pok];
			a[i] = pok;
		}
		map< int, vector<int> > div;
		for (int i = 0; i < si; ++i)
		{
			if (cnt[a[i]] == 0)
				continue;
			div[cnt[a[i]]].push_back(a[i]);
			cnt[a[i]] = 0;
		}
		for(auto it : div)
		{
			auto& group = it.second;
			map< int, vector<int> > ng;
			for(auto pok : group)
				ng[gnum[pok]].push_back(pok);
			for(auto it1 : ng)
			{
				for (auto pok : it1.second)
					gnum[pok] = gsi;
				++gsi;
			}
		}
	}
	int ans = 1;
	map<int, int> gs;
	for (int i = 0; i < m; ++i)
		++gs[gnum[i]];
	for (auto g : gs)
		ans = mul(ans, fact[g.second]);
	printf("%d\n", ans);
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