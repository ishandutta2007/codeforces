#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int N = (int)1e5 + 10;

struct Edge
{
	int a, b, count;
	Edge() : a(), b(), count() {}
	Edge(int _a, int _b, int _count) : a(_a), b(_b), count(_count) {}
};

vector<Edge> edges;
vector<int> g[N];
bool used[N];
int n;

vector<int> top_sort_list;
int top_sort_pos[N];

void top_sort(int v)
{
	used[v] = true;
	for (int to : g[v])
	{
		if (!used[to])
			top_sort(to);
	}
	top_sort_list.push_back(v);
}

vector<int> to_reverse;
bool check(int bound)
{
	for (int i = 0; i < n; i++)
	{
		g[i].clear();
		used[i] = false;
	}
	for (auto &&e : edges)
	{
		if (e.count > bound) {
			g[e.a].push_back(e.b);
		}
	}
	top_sort_list.clear();
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
			top_sort(i);
	}
	reverse(top_sort_list.begin(), top_sort_list.end());
	for (int i = 0; i < n; i++)
		top_sort_pos[top_sort_list[i]] = i;

	to_reverse.clear();
	for (int i = 0; i < (int)edges.size(); i++)
	{
		auto e = edges[i];
		if (e.count > bound && top_sort_pos[e.a] > top_sort_pos[e.b]) {
			return false;
		} else if (e.count <= bound) {
			if (top_sort_pos[e.a] > top_sort_pos[e.b]) {
				to_reverse.push_back(i);
			}
		}
	}
	return true;
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		scanf("%d%d%d", &a, &b, &cost);
		a--, b--;
		edges.push_back(Edge(a, b, cost));
	}
	int l = -1, r = (int)1e9 + 10;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	check(r);
	printf("%d %d\n", r, (int)to_reverse.size());
	for (int x : to_reverse)
		printf("%d ", x + 1);
	puts("");
	return 0;
}