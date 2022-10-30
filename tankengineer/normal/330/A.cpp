#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, m, row[10], col[10];
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	char map[11][11];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 'S') {
				++row[i];
				++col[j];
			}
		}
	}
	int ans, cntrow = n, cntcol = m;
	for (int i = 0; i < n; ++i) {
		if (row[i]) {
			--cntrow;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (col[i]) {
			--cntcol;
		}
	}
	ans = cntrow * m + n * cntcol - cntrow * cntcol;
	printf("%d\n", ans);

	return 0;
}