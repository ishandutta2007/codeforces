#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

using ll = long long;
using pii = pair<int, int>;

const int N = (int)2e5 + 10;
int n, m, k;

int value[N];
int used[N];
int initial[N];
vector <int> g[N], gt[N];
vector <int> top_sort;
set<int> with_rank[N];

void fail()
{
	puts("-1");
	exit(0);
}

bool has_cycle(int v)
{
	used[v] = 1;
	for (int to : g[v])
	{
		if (!used[to] && has_cycle(to))
			return true;
		else if (used[to] == 1)
			return true;
	}
	used[v] = 2;
	return false;
}

bool has_cycle()
{
	fill(used, used + n, 0);
	for (int i = 0; i < n; i++)
	{
		if (!used[i] && has_cycle(i))
			return true;
	}
	return false;
}

void build_top(int v)
{
	used[v] = 1;
	for (int to : g[v])
	{
		if (!used[to])
			build_top(to);
	}
	top_sort.push_back(v);
}

void build_top()
{
	fill(used, used + n, 0);
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
			build_top(i);
	}
	reverse(top_sort.begin(), top_sort.end());
}

void put_ranks()
{
	for (int v : top_sort)
	{
		int max_value = k;
		for (int from : gt[v])
			max_value = min(max_value, value[from] - 1);
		if (max_value <= 0 || (value[v] != 0 && value[v] > max_value))
			fail();
		if (value[v] == 0)
			value[v] = max_value;
	}
}

bool cmp(int a, int b)
{
	if (value[a] != value[b])
		return value[a] < value[b];
	return a < b;
}

set <int, bool(*)(int, int)> keksi(cmp);
int out_deg[N];

void try_add_to_keksi(int v)
{
	if (out_deg[v] > 0 || initial[v] != 0)
		return;
	keksi.insert(v);
}

void find_keks(int level)
{
	auto best = keksi.begin();
	if (best == keksi.end())
		return;
	int best_id = *best;
	keksi.erase(best);

	with_rank[value[best_id]].erase(best_id);
	value[best_id] = level;
	with_rank[level].insert(best_id);
}

void decrease_deg(int v)
{
	out_deg[v]--;
	try_add_to_keksi(v);
}

void solve()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &value[i]);
		initial[i] = value[i];
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].push_back(b);
		gt[b].push_back(a);
		out_deg[a]++;
	}
	if (has_cycle())
		fail();
	build_top();
	put_ranks();
	for (int i = 0; i < n; i++)
	{
		with_rank[value[i]].insert(i);
		try_add_to_keksi(i);
	}

	for (int i = 1; i <= k; i++)
	{
		if (with_rank[i].size() == 0)
			find_keks(i);
		for (auto v : with_rank[i])
		{
			keksi.erase(v);
			for (auto from : gt[v])
				decrease_deg(from);
		}
		if (with_rank[i].size() == 0)
			fail();
	}

	for (int i = 0; i < n; i++)
		printf("%d ", value[i]);
	puts("");
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif

	solve();

	eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}