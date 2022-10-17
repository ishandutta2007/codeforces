#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[300020];
int d[300020];
int f[300020];
char s[300020];
int dfs(int x, char c) {
	if (f[x] != -1) {
		return f[x];
	}
	f[x] = -2;
	int re = 0;
	for (int i: a[x]) {
		int u = dfs(i, c);
		if (u == -2) {
			return -2;
		}
		re = max(re, u);
	}
	re += (s[x] == c);
	return f[x] = re;
}
int top(char c) {
	int re = 0;
	for (int i = 1; i <= n; i++) {
		if (f[i] == -1) {
			int u = dfs(i, c);
			if (u == -2) {
				return -1;
			}
			re = max(re, u);
		}
	}
	return re;
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
	}
	memset(f, -1, sizeof f);
	if (top('!') == -1) {
		printf("-1\n");
	} else {
		int v = 0;
		for (char c = 'a'; c <= 'z'; c++) {
			memset(f, -1, sizeof f);
			v = max(v, top(c));
		}
		printf("%d\n", v);
	}
}