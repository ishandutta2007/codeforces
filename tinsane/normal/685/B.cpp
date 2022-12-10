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
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;

#pragma endregion

const int N = 3e5 + 10;
int si[N];
vector<int> edges[N];
int ans[N];
int par[N];
int q, n;

int lift(int v, int big)
{
	for (; 2 * (big - si[v]) > big; v = par[v]);
	return v;
}

void dfs(int v)
{
	si[v] = 1;
	for(auto e : edges[v])
	{
		dfs(e);
		si[v] += si[e];
	}
	if (si[v] == 1)
	{
		ans[v] = v;
		return;
	}
	int best = 0;
	int bsi = 0;
	for(auto e : edges[v])
		if (si[e] > bsi)
		{
			bsi = si[e];
			best = e;
		}
	ans[v] = lift(ans[best], si[v]);
}

void solve()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		--a;
		edges[a].push_back(i);
		par[i] = a;
	}

	dfs(0);

	for (int i = 0; i < q; ++i)
	{
		int a;
		scanf("%d", &a);
		printf("%d\n", ans[a - 1] + 1);
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
	return 0;
}