#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef pair<int, int> pii;
typedef long long ll;

#define X first
#define Y second
#define mp make_pair

const int INF = (int)1e9 + 10;
const int N = (int)1e3 + 100;
vector <int> comp;

bool used[N];
int dist[N];
vector <int> g[N];
int q[N];
int n;

void dfs(int v)
{
	comp.push_back(v);
	used[v] = 1;
	for (int to : g[v])
	{
		if (!used[to])
			dfs(to);
	}
}

int bfs(int u)
{
	fill(dist, dist + n + 1, INF);
	dist[u] = 0;
	int topQ = 0;
	q[topQ++] = u;
	for (int i = 0; i < topQ; i++)
	{
		int v = q[i];
		for (int to : g[v])
		{
			if (dist[to] == dist[v])
				return -1;
			if (dist[to] > dist[v] + 1)
			{
				dist[to] = dist[v] + 1;
				q[topQ++] = to;
			}
		}
	}
	return dist[q[topQ - 1]];
}

int solve(int v)
{
	comp.clear();
	dfs(v);
	int d = 0;
	for (int u : comp)
	{
		int k = bfs(u);
		if (k == -1)
		{
			puts("-1");
			exit(0);
		}
		d = max(d, k);
	}
	return d;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			ans += solve(i);
		}
	}
	cout << ans;
	return 0;
}