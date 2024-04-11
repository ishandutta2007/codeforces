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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}

const int N = 100100;
const int M = 11;
int n, m;
vector<int> g[N];
int dp[N][M][3];
int p, q;

void dfs(int v, int par) {
	int inner[M][3];
	for (int i = 0; i <= m; i++)
		for (int j = 0; j < 3; j++)
			dp[v][i][j] = 0;
	dp[v][0][0] = p;
	dp[v][1][1] = 1;
	dp[v][0][2] = q;
	for (int u : g[v]) {
		if (u == par) continue;
		dfs(u, v);
		for (int x = 0; x <= m; x++)
			for (int t = 0; t < 3; t++)
				inner[x][t] = 0;
		for (int x = 0; x <= m; x++)
			for (int y = 0; x + y <= m; y++)
				for (int t1 = 0; t1 < 3; t1++)
					for (int t2 = 0; t2 < 3; t2++) {
						if ((t1 == 1 || t2 == 1) && (t1 + t2) != 1) continue;
						inner[x + y][t1] = add(inner[x + y][t1], mult(dp[v][x][t1], dp[u][y][t2]));
					}
		for (int x = 0; x <= m; x++)
			for (int t = 0; t < 3; t++)
				dp[v][x][t] = inner[x][t];
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	scanf("%d%d", &p, &m);
	q -= p;
	p--;
	dfs(0, -1);
	int ans = 0;
	for (int i = 0; i <= m; i++)
		for (int j = 0; j < 3; j++)
			ans = add(ans, dp[0][i][j]);
	printf("%d\n", ans);

	return 0;
}