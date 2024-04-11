#include <bits/stdc++.h>
using namespace std;
int n, m, z;
vector<int> a[50001];
int f[50001][501];
void dfs(int x, int y) {
	f[x][0] = 1;
	for (int i: a[x]) {
		if (i != y) {
			dfs(i, x);
			for (int j = m; j > 0; j--) {
				z += f[x][j-1] * f[i][m-j];
				f[x][j] += f[i][j-1];
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	printf("%d\n", z);
	return 0;
}