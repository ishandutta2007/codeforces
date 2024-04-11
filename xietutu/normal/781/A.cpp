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
VI G[MAXN];
int n, m, st, color[MAXN], d[MAXN];
void dfs(int x, int fa) {
	int m = 0;
	for (auto v : G[x])
		if (!color[v]) {
			++m;
			while (color[x] == m || color[fa] == m) ++m;
			color[v] = m; 
			dfs(v, x);		
		}
}
int main() {
	ios::sync_with_stdio(false);
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].PB(v);
		G[v].PB(u);
		++d[u]; ++d[v];
	}
	st = 1;
	for (int i = 2; i <= n; ++i)
		if (d[i] > d[st]) st = i;
	printf("%d\n", d[st] + 1);
	color[st] = m = 1;
	for (auto v : G[st]) {
		color[v] = ++m;
		dfs(v, st);
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", color[i]);
}