#include<algorithm>
#include<cstdio>

using namespace std;

char M[100][100];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

char code[120];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", M + i);
	}
	scanf("%s", code);
	int sx, sy;
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
		if (M[i][j] == 'S') {
			sx = i; sy = j;
		}
	}

	int map[4] = { 0, 1, 2, 3 };
	int ans = 0;

	do {
		int x, y;
		x = sx, y = sy;
		for (int i = 0; code[i]; i++) {
			int d = map[code[i] - '0'];
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) break;
			if (M[xx][yy] == '#') break;
			if (M[xx][yy] == 'E') {
				ans++;
				break;
			}
			x = xx;
			y = yy;
		}
	} while (next_permutation(map, map + 4));
	printf("%d\n", ans);
	return 0;
}