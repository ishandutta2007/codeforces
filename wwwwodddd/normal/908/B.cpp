#include <bits/stdc++.h>
using namespace std;
pair<int, int> d[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int n, m;
char s[500][500];
char o[1000];
bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}
bool check() {
//	printf("%d %d\n", d[0].first, d[0].second);
	int sx = -1, sy = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
//			printf("%d %d %c\n", i, j, s[i][j]);
			if (s[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	}
	assert(sx != -1);
//	printf("%d %d\n", sx, sy);
	for (int i = 0; o[i]; i++) {
		sx += d[o[i] - '0'].first;
		sy += d[o[i] - '0'].second;
		if (!in(sx, sy)) {
			return false;
		}
		if (s[sx][sy] == '#') {
			return false;
		}
		if (s[sx][sy] == 'E') {
			return true;
		}
	}
//	printf("%d %d\n", sx, sy);
	return s[sx][sy] == 'E';
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	scanf("%s", o);
	int z = 0;
	do {
		if (check()) {
			z++;
		}
	} while (next_permutation(d, d + 4));
	printf("%d\n", z);
	return 0;
}