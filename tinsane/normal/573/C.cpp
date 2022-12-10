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
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;

const int N = 1e5 + 10;
vector<int> edges[N];
bool del[N];
int legs[N];

void dfs(int i, int p = -1)
{
	if (edges[i].size() > 2)
		return;
	del[i] = true;
	for (int j : edges[i]) 
		if (j != p) 
			dfs(j, i);
}

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
		if (edges[i].size() == 1)
			dfs(i);
	for (int i = 0; i < n; ++i)
		for (auto j : edges[i]) 
			if (del[j])
				legs[i] = min(legs[i] + 1, 2);
	for (int i = 0; i < n; ++i)
	{
		if (del[i])
			continue;
		int cnt = 0;
		for (auto j : edges[i])
			if (!del[j] && edges[j].size() - legs[j] > 1)
				++cnt;
		if (cnt > 2)
		{
			puts("No");
			return;
		}
	}
	puts("Yes");
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("chocolate.in", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
	return 0;
}