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

const int N = 2e5 + 10;
int n, q;
int a[N], b[N];
int pos[N];
int p[N];
vector<int> wh[N];
bool used[N];

void solve()
{
	memset(pos, -1, sizeof pos);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &a[i], &b[i]);
		--a[i];
		pos[a[i]] = i;
		wh[a[i]].push_back(i);
	}
	for (int i = 0; i < n; ++i)
		p[i] = i;
	sort(p, p + n, [] (int a, int b) { return pos[a] > pos[b]; });
	p[n] = N - 1;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
	{
		int k;
		vector<int> out;
		scanf("%d", &k);
		out.resize(k);
		for(auto &e : out)
		{
			scanf("%d", &e);
			--e;
			used[e] = true;
		}
		int ind = 0;
		for (; ind < n && used[p[ind]]; ++ind);
		if (pos[p[ind]] == -1)
			puts("0 0");
		else
		{
			int g = p[ind];
			int ind1 = ind + 1;
			for (; ind1 < n && used[p[ind1]]; ++ind1);
			int w = *lower_bound(wh[g].begin(), wh[g].end(), pos[p[ind1]]);
			printf("%d %d\n", a[w] + 1, b[w]);
		}
		for (auto e : out)
			used[e] = false;
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
	{
		solve();
	}
#endif
#ifdef MULTITEST
	int t;
	scanf("%d", &t);
	while (t--)
#endif
		solve();

	eprintf("\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
}