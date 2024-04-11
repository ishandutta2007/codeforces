#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 300 * 1000 + 5;
const int MAX_Q = 300 * 1000 + 5;

int n, q;
vector<int> graph[MAX_N];
int size_of[MAX_N];
int prev_of[MAX_N];
int big_subtree[MAX_N];
int centroid[MAX_N];

bool is_centroid_of_subtree(int v, int c)
{
	return ((size_of[v] - size_of[c]) * 2 <= size_of[v] && big_subtree[c] * 2 <= size_of[v]);
}

void dfs_calc(int v, int p)
{
	big_subtree[v] = 0;
	size_of[v] = 1;
	prev_of[v] = p;

	for (int i = 0; i < graph[v].size(); ++i)
	{
		dfs_calc(graph[v][i], v);
		size_of[v] += size_of[graph[v][i]];
		big_subtree[v] = max(big_subtree[v], size_of[graph[v][i]]);
	}
}

void dfs_centroid(int v)
{
	if (size_of[v] == 1)
	{
		centroid[v] = v;
	}
	else
	{
		int ptr = 0;
		for (int i = 0; i < graph[v].size(); ++i)
		{
			dfs_centroid(graph[v][i]);
			if (size_of[graph[v][ptr]] < size_of[graph[v][i]])
			{
				ptr = i;
			}
		}

		int c = centroid[graph[v][ptr]];

		while (!is_centroid_of_subtree(v, c))
		{
			c = prev_of[c];
		}

		centroid[v] = c;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &q);

	int v;
	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d", &v);
		graph[v - 1].push_back(i + 1);
	}

	dfs_calc(0, 0);
	dfs_centroid(0);

	for (int i = 0; i < q; ++i)
	{
		scanf("%d", &v);
		printf("%d\n", centroid[v - 1] + 1);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}