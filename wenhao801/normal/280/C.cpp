#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

vector <int> E[100100];
int dep[101000];
void dfs (int x, int f) { dep[x] = dep[f] + 1; for (auto i: E[x]) if (i != f) dfs(i, x); }

int main () {
	int n; scanf("%d", &n);
	int i, j;
	for (i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		E[u].push_back(v), E[v].push_back(u);
	}
	dfs(1, 0);
	double ans = 0;
	for (i = 1; i <= n; i++) ans += 1.0 / dep[i];
	printf("%.7lf\n", ans);
	return 0;
}