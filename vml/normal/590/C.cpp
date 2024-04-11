//#pragma comment(linker, "/STACK:mod00000000")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <ctime>
#include <memory.h>
#include <cstring>
#include <map>
#include <string>
#include <cassert>
#include <cmath>
#define sin sss
#define ll long long 

using namespace std;

const int maxn = (int)1e3 + 10, inf = (int)1e8 + 7;
char c[maxn][maxn];
int dst[3][maxn][maxn];
int n, m;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(char p) {
	int num = p - '0' - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dst[num][i][j] = inf;
		}
	}

	queue <pair <int, int> > q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == p) {
				dst[num][i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && dst[num][nx][ny] == inf && c[nx][ny] != '#') {
				dst[num][nx][ny] = dst[num][x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int dd[3][3];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", c[i]);
	}

	bfs('1');
	bfs('2');
	bfs('3');

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			dd[i][j] = inf;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == '1') {
				dd[1][0] = min(dd[1][0], dst[1][i][j]);
				dd[2][0] = min(dd[2][0], dst[2][i][j]);
			} else if (c[i][j] == '2') {
				dd[0][1] = min(dd[0][1], dst[0][i][j]);
				dd[2][1] = min(dd[2][1], dst[2][i][j]);
			} else if (c[i][j] == '3') {
				dd[0][2] = min(dd[0][2], dst[0][i][j]);
				dd[1][2] = min(dd[1][2], dst[1][i][j]);
			}
		}
	}

	int ans = inf;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = min(ans, dst[0][i][j] + dst[1][i][j] + dst[2][i][j] - 2);
		}
	}

	ans = min(ans, dd[0][1] + dd[2][1] - 2);
	ans = min(ans, dd[1][0] + dd[2][0] - 2);
	ans = min(ans, dd[0][2] + dd[1][2] - 2);

	if (ans <= (int)1e6) {
		cout << ans << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}