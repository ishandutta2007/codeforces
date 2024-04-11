#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 100010;
vector<int> g[maxn]; 
int n, siz[maxn];
double f[maxn];
queue<int> Q;
void solve() {
	f[1] = 1;
	Q.push(1);
	while (Q.size()) {
		int x = Q.front(); Q.pop();
		int len = g[x].size();
		for (int j = 0; j < len; ++j) {
			int v = g[x][j];
			f[v] = f[x] + 1 + 1.0 * (siz[x] - 1 - siz[v]) / 2.0; 
			Q.push(v);
		}
	}
}
void dfs(int x) {
	siz[x] = 1;
	for (unsigned int j = 0; j < g[x].size(); ++j) {
		dfs(g[x][j]);
		siz[x] += siz[g[x][j]];
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		g[p].push_back(i);
	}
	dfs(1);
	solve();
	for (int i = 1; i <= n; ++i)
		printf("%.12lf ", f[i]); 
}