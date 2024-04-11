#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
vector<pair<int, char> >a[1000020];
int f[120][120];
int g[120][120];
int n, c;
void dfs(int x, int y) {
	if (g[x][y] > x) {
		dfs(x + 1, g[x][y]);
	}
	printf("%d ", x);
	if (g[x][y] < y) {
		dfs(g[x][y] + 1, y);
	}
	return;
}
int main() {
	scanf("%d%d", &n, &c);
	for (int i = 0; i < c; i++) {
		int x, y;
		char s[10];
		scanf("%d %d %s", &x, &y, s);
		if (y <= x) {
			printf("IMPOSSIBLE\n");
			return 0;
		}
		a[x].push_back(make_pair(y, s[0]));
	}
	for (int i = 1; i <= n + 2; i++) {
		f[i][i - 1] = 1;
	}
	memset(g, -1, sizeof g);
	for (int l = 1; l <= n; l++) {
		for (int i = 1; i + l - 1 <= n; i++) {
			for (int d = i; d <= i + l - 1; d++) {
				if (f[i + 1][d] && f[d + 1][i + l - 1]) {
					int flag = true;
					for (int k = i + 1; k <= d; k++) {
						for (vector<pair<int, char> >::iterator it = a[k].begin(); it != a[k].end(); it++) {
							if (it -> first > d && it -> first < i + l) {
								flag = false;
								break;
							}
						}
					}
					for (int k = d + 1; k <= i + l - 1; k++) {
						for (vector<pair<int, char> >::iterator it = a[k].begin(); it != a[k].end(); it++) {
							if (it -> first > i && it -> first <= d) {
								flag = false;
								break;
							}
						}
					}
					for (vector<pair<int, char> >::iterator it = a[i].begin(); it != a[i].end(); it++) {
						if (it -> second == 'L') {
							if (it -> first == i || (d < it -> first && it -> first < i + l)) {
								flag = false;
								break;
							}
						} else {
							if (it -> first == i || (i < it -> first && it -> first <= d)) {
								flag = false;
								break;
							}
						}
					}
					if (flag) {
						f[i][i + l - 1] = 1;
						g[i][i + l - 1] = d;
					}
				}
			}
		}
	}
	if (f[1][n] == 0) {
		printf("IMPOSSIBLE\n");
	} else {
		dfs(1, n);
		printf("\n");
	}
	return 0;
}