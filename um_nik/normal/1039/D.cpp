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

const int B = 1000;
//const int B = 1;
const int N = 100100;
vector<int> g[N];
vector<int> a[N];
int t[N];
int T;
int dp[N][3];
int ans[N];
bool used[N];
int n;

void dfs(int v) {
	used[v] = 1;
	for (int u : g[v])
		if (!used[u])
			dfs(u);
	t[v] = T++;
}

int solve(int k) {
	for (int v = 0; v < n; v++) {
		dp[v][0] = dp[v][1] = dp[v][2] = 0;
		for (int u : a[v]) {
			dp[v][0] += dp[u][0];
			int x = dp[u][1];
			for (int i = 1; i < 3; i++) {
				if (x > dp[v][i])
					swap(x, dp[v][i]);
			}
		}
		if (dp[v][1] + dp[v][2] >= k - 1) {
			dp[v][0]++;
			dp[v][1] = dp[v][2] = 0;
		} else {
			dp[v][1]++;
			dp[v][2]++;
		}
	}
	return dp[n - 1][0];
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
	dfs(0);
	for (int v = 0; v < n; v++)
		for (int u : g[v]) {
			int vv = t[v], uu = t[u];
			if (vv < uu) continue;
			a[vv].push_back(uu);
		}
	for (int k = 1; k <= min(n, B); k++)
		ans[k] = solve(k);
	if (n > B) {
		int lst = B + 1;
		for (int res = ans[B]; res > 0; res--) {
			int l = lst - 1, r = n + 1;
			while(r - l > 1) {
				int m = (l + r) / 2;
				if (solve(m) < res)
					r = m;
				else
					l = m;
			}
			while(lst < r) ans[lst++] = res;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);

	return 0;
}