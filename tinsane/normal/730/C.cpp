#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

typedef long long ll;

struct Storage
{
	int cost, cnt, city;
	void read()
	{
		scanf("%d%d%d", &city, &cnt, &cost);
		--city;
	}
	bool operator< (const Storage& s) const
	{
		return cost < s.cost;
	}
};

const int N = 5e3 + 10;
int n, m, s, q;
Storage st[N];
vector<int> edges[N];
int dist[N];
int wave[N], wsi;

pair<int, ll> grab(int dst, int demand)
{
	ll cost = 0;
	int lost = demand;
	for(int i = 0; i < s; ++i)
		if (dist[st[i].city] != -1 && dist[st[i].city] <= dst)
		{
			int delta = min(lost, st[i].cnt);
			cost += (ll)st[i].cost * delta;
			lost -= delta;
		}
	return {lost, cost};
}

void solve_query()
{
	int now, demand;
	ll money;
	scanf("%d%d%lld", &now, &demand, &money);
	--now;
	memset(dist, -1, sizeof dist);
	dist[now] = 0;
	wave[0] = now;
	wsi = 1;
	for (int i = 0; i < wsi; ++i)
	{
		int v = wave[i];
		for(auto e : edges[v])
			if (dist[e] == -1)
			{
				dist[e] = dist[v] + 1;
				wave[wsi++] = e;
			}
	}
	auto g = grab(n, demand);
	if (g.first > 0 || g.second > money)
	{
		puts("-1");
		return;
	}
	g = grab(0, demand);
	if (g.first == 0 && g.second <= money)
	{
		puts("0");
		return;
	}
	int l = 0;
	int r = n;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		g = grab(m, demand);
		if (g.first == 0 && g.second <= money)
			r = m;
		else
			l = m;
	}
	printf("%d\n", r);
}

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	scanf("%d", &s);
	for (int i = 0; i < s; ++i)
		st[i].read();
	sort(st, st + s);
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
		solve_query();
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif

	solve();

	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

	return 0;
}