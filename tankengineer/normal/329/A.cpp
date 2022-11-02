#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, row[105], col[105];
char map[105][105];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%s", map[i] + 1);
	int r = 0, c = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (map[i][j] == '.') {
				if (row[i] == 0) {
					row[i] = j;
					++r;
				}
				if (col[j] == 0) {
					col[j] = i;
					++c;
				}
			}
		}
	}
	if (r != n && c != n) {
		printf("-1\n");
	} else if (r == n) {
		for (int i = 1; i <= n; ++i) printf("%d %d\n", i, row[i]);
	} else {
		for (int i = 1; i <= n; ++i) printf("%d %d\n", col[i], i);
	}
	return 0;
}