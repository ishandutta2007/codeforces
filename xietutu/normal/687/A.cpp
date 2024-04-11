#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int color[maxn];
int n, m;
vector<int> V[2], G[maxn];
bool dfs(int x) {
	V[color[x] - 1].push_back(x);
	for (int& v : G[x]) 
		if (!color[v]) {
			color[v] = 3 - color[x];
			if (!dfs(v)) return false;	
		}
		else if (color[v] != 3 - color[x]) return false;
	return true;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool flag = true;
	for (int i = 1; i <= n; ++i)
		if (!color[i]) {
			color[i] = 1;
			flag &= dfs(i);
		}
	if (flag) {
		for (int k = 0; k < 2; ++k) {
			cout <<  V[k].size() << endl;
			for (unsigned int i = 0; i < V[k].size(); ++i)
				printf("%d ", V[k][i]);
			printf("\n");
		}
	}
	else puts("-1");
}