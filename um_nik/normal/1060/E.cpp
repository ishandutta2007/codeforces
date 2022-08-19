#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200200;
int n;
vector<int> g[N];
ll dp[N][2][2];
ll ans = 0;

void dfs(int v, int par) {
	ll cur[2][2];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			cur[i][j] = 0;
	cur[0][1] = 1;
	for (int u : g[v]) {
		if (u == par) continue;
		dfs(u, v);
		for (int x = 0; x < 2; x++)
			for (int y = 0; y < 2; y++) {
				ans += cur[x][0] * dp[u][y][1] + cur[x][1] * dp[u][y][0];
				ans += cur[x][1] * dp[u][y][1];
				if (x == y) ans += cur[x][1] * dp[u][y][1];
			}
		for (int y = 0; y < 2; y++) {
			cur[y ^ 1][1] += dp[u][y][1];
			cur[y ^ 1][0] += dp[u][y][0] + dp[u][y][1];
		}
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			dp[v][i][j] = cur[i][j];
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
	printf("%lld\n", ans / 2);

	return 0;
}