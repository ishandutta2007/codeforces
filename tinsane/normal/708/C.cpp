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
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef vector<int>::iterator vint_iter;

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-13;

#pragma endregion

const int N = 4e5 + 10;
int n;
vector<int> edges[N];
int sz[N];
bool ans[N];

void dfs(int v, int p)
{
	sz[v] = 1;
	for(auto e : edges[v])
		if (e != p)
		{
			dfs(e, v);
			sz[v] += sz[e];
		}
}

int find_c(int v)
{
	int p = -1;
	while (true)
	{
		bool ok = true;
		for (auto e : edges[v])
			if (e != p && sz[e] * 2 > n)
			{
				p = v;
				v = e;
				ok = false;
				break;
			}
		if (ok)
			return v;
	}
}

void color(int v, int p, int kill)
{
	if (p != -1)
	{
		int psz = n - sz[v] - sz[kill];
		if (psz * 2 <= n)
			ans[v] = true;
	}
	for (auto e : edges[v])
		if (e != p && e != kill)
			color(e, v, kill);
}

void solve()
{
	scanf("%d", &n);
	if (n <= 3)
	{
		for (int i = 0; i < n; ++i)
			printf("1 ");
		return;
	}
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0, -1);
	int c = find_c(0);
	ans[c] = true;
	dfs(c, -1);
	int best = -1;
	for (auto e : edges[c])
		if (best == -1 || sz[best] < sz[e])
			best = e;
	if (best != -1)
		color(c, -1, best);
	int best2 = -1;
	for (auto e : edges[c])
		if (e != best && (best2 == -1 || sz[best2] < sz[e]))
			best2 = e;
	if (best2 != -1)
		color(c, -1, best2);
	if (sz[best] * 2 == n)
		color(best, c, best);
	for (int i = 0; i < n; ++i)
		printf("%c ", '0' + ans[i]);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("bandits.in", "r", stdin);
	//freopen("bandits.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
#endif
}