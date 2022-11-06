#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;
vector<int> d[100001], map[100001];
int st[100001];
int v[100001];
void fail() {
	printf("No\n");
	exit(0);
}
void dfs(int x) {
	v[x] = 1;
	if (st[x] == 2) fail();
	st[x] = 1;
	for (auto xx : map[x]) {
		if (v[xx] == 0) dfs(xx);
	}
}
int main() {
	int n, m, s, t;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &s);
		for (int j = 1; j <= s; j++) {
			scanf("%d", &t);
			d[i].push_back(t);
		}
	}
	for (int i = 1; i < m; i++) {
		int j;
		for (j = 0; j < d[i].size() && j < d[i + 1].size() && d[i][j] == d[i + 1][j]; j++);
		if (d[i].size() == j) continue;
		if (d[i + 1].size() == j) fail();
		if (d[i][j] < d[i + 1][j]) {
			map[d[i + 1][j]].push_back(d[i][j]);
		}
		else {
			if (st[d[i][j]] == 2 || st[d[i + 1][j]] == 1) fail();
			st[d[i][j]] = 1;
			st[d[i + 1][j]] = 2;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (st[i] == 1 && v[i] == 0) dfs(i);
	}
	int c = 0;
	for (int i = 1; i <= n; i++) if (st[i] == 1) c++;
	printf("Yes\n%d\n", c);
	for (int i = 1; i <= n; i++) if (st[i] == 1) printf("%d ", i);
	return 0;
}