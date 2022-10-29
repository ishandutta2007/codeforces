#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
#define F first
#define S second
#define VI vector<int>
#define PB push_back
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned int ui;
int n, m, now, k, stamp, path[MAXN * 2];
vector<int> g[MAXN];
bool visit[MAXN];
void dfs(int x) {
	path[++stamp] = x;
	visit[x] = true;
	for (auto v : g[x])
		if (!visit[v]) {
			dfs(v);
			path[++stamp] = x;
		}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1);
	now = 0;
	for (int i = 1; i <= k; ++i) {
		int r = min((stamp - now) - (k - i), (n * 2 + k - 1) / k);
		printf("%d ", r);
		for (int j = 0; j < r; ++j)
			printf("%d ", path[++now]); 
		printf("\n");
	}
}