#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > a[100020];
int f[100020][17];
int d[100020];
int s[100020];
int z[100020];
void dfs(int x, int y) {
	f[x][0] = y;
	d[x] = d[y] + 1;
	for (int i = 1; i < 17; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (pair<int, int> i: a[x]) {
		if (i.first != y) {
			dfs(i.first, x);
		}
	}
}
int dfs2(int x, int y) {
	int re = s[x];
	for (pair<int, int> i: a[x]) {
		if (i.first != y) {
			z[i.second] = dfs2(i.first, x);
			re += z[i.second];
		}
	}
	return re;
}
int lca(int x, int y) {
	if (d[x] < d[y]) {
		swap(x, y);
	}
	int dd = d[x] - d[y];
	for (int i = 0; i < 17; i++) {
		if (dd >> i & 1) {
			x = f[x][i];
		}
	}
	if (x == y) {
		return x;
	}
	for (int i = 17 - 1; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(make_pair(y, i));
		a[y].push_back(make_pair(x, i));
	}
	dfs(1, 0);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		int l = lca(x, y);
		s[x]++;
		s[y]++;
		s[l]--;
		s[l]--;
	}
	dfs2(1, 0);
	for (int i = 1; i < n; i++)
	{
		printf("%d%c", z[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}