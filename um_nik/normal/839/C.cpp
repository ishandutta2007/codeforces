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

const int N = 100100;
double dp[N];
vector<int> g[N];
int n;

void dfs(int v, int par)
{
	int cnt = 0;
	dp[v] = 0;
	for (int u : g[v]) {
		if (u == par) continue;
		dfs(u, v);
		dp[v] += dp[u];
		cnt++;
	}
	if (cnt == 0) return;
	dp[v] /= cnt;
	dp[v] += 1;
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
	printf("%.13lf\n", dp[0]);

	return 0;
}