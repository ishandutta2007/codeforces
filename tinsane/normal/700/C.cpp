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
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-13;

#pragma endregion

struct Road
{
	int to, w, ind;
	Road() {}
	Road(int to, int w, int ind) : to(to), w(w), ind(ind) {}
};

const int N = 1e3 + 10;
int n, m;
int s, t;
vector< Road > edges[N];
bool used[N];
int anc[N];
int timer;
int tin[N], tout[N];
int ban = -1;
int ans = INF * 2;
int af = -1, as = -1;
vector<int> way;

void dfs1(int v)
{
	used[v] = true;
	for (auto& e : edges[v])
		if (!used[e.to] && e.ind != ban)
		{
			anc[e.to] = v;
			dfs1(e.to);
		}
}

void dfs2(int v, int ai)
{
	if (tin[v] != -1)
		return;
	tout[v] = tin[v] = timer++;
	for(auto e : edges[v])
	{
		if (e.ind == ban || e.ind == ai)
			continue;
		dfs2(e.to, e.ind);
		if (tin[e.to] < tin[v])
			tout[v] = min(tout[v], tin[e.to]);
		else
			tout[v] = min(tout[v], tout[e.to]);
	}
}

void solve()
{
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	--s, --t;
	for (int i = 0; i < m; ++i)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		--a, --b;
		edges[a].emplace_back(b, w, i);
		edges[b].emplace_back(a, w, i);
	}
	anc[s] = -1;
	dfs1(s);
	if (!used[t])
	{
		printf("0\n0\n");
		return;
	}
	for (int v = t; v != -1; v = anc[v])
		way.push_back(v);
	for (int i = 1; i < way.size(); ++i)
	{
		int bv = way[i];
		int bnum = -1;
		for (int j = 0; j < edges[bv].size(); ++j)
			if (edges[bv][j].to == way[i - 1] && (bnum == -1 || edges[bv][j].w < edges[bv][bnum].w))
				bnum = j;
		ban = edges[bv][bnum].ind;
		memset(used, 0, sizeof used);
		dfs1(s);
		if (!used[t] && ans > edges[bv][bnum].w)
		{
			ans = edges[bv][bnum].w;
			as = -1;
			af = ban;
		}
		timer = 0;
		memset(tin, -1, sizeof tin);
		dfs2(s, -1);
		for (int now = t, prev = anc[t]; prev != -1; now = prev, prev = anc[now])
		{
			if (tout[now] <= tin[prev])
				continue;
			for(auto e : edges[prev])
				if (e.ind != ban && e.to == now && ans > edges[bv][bnum].w + e.w)
				{
					ans = edges[bv][bnum].w + e.w;
					af = ban;
					as = e.ind;
				}
		}
	}
	if (as == -1 && af == -1)
	{
		puts("-1");
		return;
	}
	printf("%d\n", ans);
	if (as == -1)
		printf("1\n%d\n", af + 1);
	else
		printf("2\n%d %d\n", af + 1, as + 1);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("editor.in", "r", stdin);
	//freopen("intersection.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
}