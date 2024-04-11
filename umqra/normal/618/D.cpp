/*
	Team: Dandelion
	Room: 258
*/

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

const int INF = (int)1e9;
const int N = (int)2e5 + 100;
int deg[N];
int dp[N][2];
int used[N];
vector <int> g[N];

void solve(int v)
{
	used[v] = 1;
	vector <int> childs = {};
	for (int to : g[v])
	{
		if (used[to])
			continue;
		childs.push_back(to);
		solve(to);
	}
	int sum = 0;
	int minD1 = INF, minD2 = INF;
	for (int to : childs)
	{
		sum += dp[to][0];
		if (minD1 > dp[to][1] - dp[to][0])
		{
			minD2 = minD1;
			minD1 = dp[to][1] - dp[to][0];
		}
		else if (minD2 > dp[to][1] - dp[to][0])
			minD2 = dp[to][1] - dp[to][0];
	}
	dp[v][0] = 1 + sum;
	if (minD2 != INF)
		dp[v][0] = min(dp[v][0], sum + minD1 + minD2 + 1);
	if (minD1 != INF)
		dp[v][0] = min(dp[v][0], sum + minD1 + 1);
	dp[v][1] = min(sum, sum + minD1);
//	eprintf("v:%d, %d %d\n", v, dp[v][0], dp[v][1]);
}

int main()
{
	ll n, x, y;
	scanf("%lld%lld%lld", &n, &x, &y);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		deg[a]++;
		deg[b]++;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if (x > y)
	{
		bool badCase = false;
		for (int i = 0; i < n; i++)
		{
			if (deg[i] == n - 1)
				badCase = true;
		}
		if (!badCase)
			printf("%lld\n", y * (n - 1));
		else
			printf("%lld\n", y * (n - 2) + x);
	}
	else
	{
		solve(0);
		ll cnt = min(dp[0][0], dp[0][1] + 1);
		printf("%lld\n", y * (cnt - 1) + x * (n - 1 - (cnt - 1)));
	}
	return 0;
}