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
const double eps = 1e-8;
const ld EPS = 1e-12;

const int N = 2e5 + 10;
int n, m;
bool var_used[N];
bool values[N];
bool dis_used[N];
vector< pair<int, bool> > vars[N];
vector< pair<int, bool> > disjuncts[N];
vector<pii> edges[N];
bool used[N];

void solve(int v)
{
	if (dis_used[v])
		return;
	dis_used[v] = true;
	for(auto var : disjuncts[v])
	{
		auto who = var.first;
		if (var_used[who])
			continue;
		var_used[who] = true;
		auto val = true;
		if (v != vars[who][0].first)
			val = vars[who][0].second;
		else if (vars[who].size() > 1)
			val = vars[who][1].second;
		values[who] = val;
		for (auto d : vars[who])
			solve(d.first);
	}
}

void cleanup()
{
	for (int i = 0; i < m; ++i)
	{
		if (vars[i].size() == 2 && vars[i][0].second != vars[i][1].second || var_used[i])
			continue;
		var_used[i] = true;
		if (vars[i].size() != 0)
			values[i] = vars[i][0].second;
		for (auto var : vars[i])
			solve(var.first);
	}
}

int find_cycle(int v, int p)
{
	used[v] = true;
	for(auto e : edges[v])
	{
		if (e.second == p)
			continue;
		if (used[e.first])
			return e.second;
		auto res = find_cycle(e.first, e.second);
		if (res != -1)
			return res;
	}
	return -1;
}

bool solvecc(int v)
{
	auto var = find_cycle(v, -1);
	if (var == -1)
		return false;
	var_used[var] = true;
	values[var] = vars[var][0].second;
	solve(vars[var][0].first);
	return true;
}

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j)
		{
			int x;
			auto pos = true;
			scanf("%d", &x);
			if (x < 0)
				pos = false;
			x = abs(x) - 1;
			vars[x].emplace_back(i, pos);
			disjuncts[i].emplace_back(x, pos);
		}
	}
	cleanup();
	for (int i = 0; i < n; ++i)
	{
		if (dis_used[i])
			continue;
		for (auto var : disjuncts[i])
			edges[i].emplace_back(vars[var.first][0].first == i ? vars[var.first][1].first : vars[var.first][0].first, var.first);
	}
	for (int i = 0; i < n; ++i)
	{
		if (dis_used[i])
			continue;
		if (!solvecc(i))
		{
			printf("NO");
			return;
		}
	}
	printf("YES\n");
	for (int i = 0; i < m; ++i)
		printf("%d", values[i]);
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