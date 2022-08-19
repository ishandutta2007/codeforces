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

const ll INF = (ll)1e18;
const int N = (int)2e5 + 100;
vector <int> g[N];
long long dp[N][2];
int value[N];
long long cur_dp[2][2];
long long new_dp[2][2];

void solve(int v)
{
	dp[v][1] = value[v];
	dp[v][0] = 0;
	for (int to : g[v])
	{
		solve(to);
	}
	cur_dp[0][0] = 0;
	cur_dp[0][1] = -INF;
	cur_dp[1][0] = -INF;
	cur_dp[1][1] = value[v];
	for (int to : g[v])
	{
		for (int a = 0; a < 2; a++)
			for (int b = 0; b < 2; b++)
				new_dp[a][b] = cur_dp[a][b];
		for (int on_off = 0; on_off < 2; on_off++)
		{
			for (int a = 0; a < 2; a++)
				for (int b = 0; b < 2; b++)
				{
					new_dp[on_off][a ^ b] = max(new_dp[on_off][a ^ b], cur_dp[on_off][a] + dp[to][b]);
				}
		}
		for (int a = 0; a < 2; a++)
			for (int b = 0; b < 2; b++)
				cur_dp[a][b] = new_dp[a][b];
	}
	dp[v][0] = cur_dp[0][0];
	dp[v][1] = max(cur_dp[0][1], cur_dp[1][1]);
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int par;
		scanf("%d%d", &par, &value[i]);
		par--;
		if (par >= 0)
			g[par].push_back(i);
	}
	solve(0);
	cout << max(dp[0][0], dp[0][1]);

	return 0;
}