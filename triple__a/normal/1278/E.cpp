#include <bits/stdc++.h>
using namespace std;
 
const int N = 500007;
 
int st[N], en[N], c;
vector<int> g[N];
 
void dfs (int u, int from) {
	int z = en[u] = (c += g[u].size() + 1 - (u != from));
	for (int & v : g[u]) if (v != from) {
		st[v] = (-- z);
		dfs(v, u);
	}
}
 
int main () {
	int n;
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
 
	c = st[1] = 1;
	dfs(1, 1);
 
	for (int i = 1; i <= n; i++)
		printf("%d %d\n", st[i], en[i]);
}