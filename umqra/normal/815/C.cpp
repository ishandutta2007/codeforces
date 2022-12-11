#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const ll INF = (ll)1e18;
const int N = 5010;
int n, b;
vector <int> g[N];
int cost[N], disc[N];
ll dp[N][N][2];
ll inner_dp[N];
int sz[N];

void solve(int v)
{
	sz[v] = 1;
	for (int to : g[v])
	{
		solve(to);
		sz[v] += sz[to];
	}

	fill(inner_dp, inner_dp + sz[v] + 1, INF);
	inner_dp[0] = 0;
	inner_dp[1] = cost[v];
	int sum = 1;
	for (int to : g[v])
	{
		for (int s = sum; s >= 0; s--)
			for (int t = 1; t <= sz[to]; t++)
				inner_dp[s + t] = min(inner_dp[s + t], inner_dp[s] + dp[to][t][0]);
		sum += sz[to];
	}
	for (int i = 0; i <= sum; i++)
		dp[v][i][0] = inner_dp[i];

	fill(inner_dp, inner_dp + sz[v] + 1, INF);
	inner_dp[0] = 0;
	inner_dp[1] = cost[v] - disc[v];
	
	sum = 1;
	for (int to : g[v])
	{
		for (int s = sum; s >= 1; s--)
			for (int t = 1; t <= sz[to]; t++)
				inner_dp[s + t] = min(inner_dp[s + t], inner_dp[s] + min(dp[to][t][0], dp[to][t][1]));
		sum += sz[to];
	}
	for (int i = 0; i <= sum; i++)
		dp[v][i][1] = inner_dp[i];
}

int main()
{
	scanf("%d%d", &n, &b);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &cost[i], &disc[i]);
		if (i != 0)
		{
			int p;
			scanf("%d", &p);
			g[p - 1].push_back(i);
		}
	}
	solve(0);
	for (int i = 0; i <= n; i++)
	{
		if (min(dp[0][i][0], dp[0][i][1]) > b)
		{
			printf("%d\n", i - 1);
			return 0;
		}
	}
	printf("%d\n", n);
	return 0;
}