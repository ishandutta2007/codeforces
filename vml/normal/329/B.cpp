#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAXN = 1010;
char v[MAXN][MAXN];
int ans[MAXN][MAXN];

struct pos {
	int x;
	int y;
	int d;
	pos(int x, int y, int d): x(x), y(y), d(d) {}
};

int main() {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			ans[i][j] = -1;
		}
	}
	int n, m;
	scanf("%d %d", &n, &m);
	int x, y;
	int beg_x, beg_y;
	for (int i = 0; i < n; i++) {
		scanf("\n");
		for (int j = 0; j < m; j++) {
			scanf("%c", &v[i][j]);
			if (v[i][j] == 'E') {
				x = i;
				y = j;
			}
			if (v[i][j] == 'S') {
				beg_x = i;
				beg_y = j;
			}
		}
	}
	queue <pos> q;
	q.push(pos(x, y, 0));
	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		if (now.x < 0 || now.x >= n || now.y < 0 || now.y >= m || v[now.x][now.y] == 'T') {
			continue;
		}
		if (ans[now.x][now.y] != -1) {
			continue;
		}
		ans[now.x][now.y] = now.d;
		q.push(pos(now.x + 1, now.y, now.d + 1));
		q.push(pos(now.x - 1, now.y, now.d + 1));
		q.push(pos(now.x, now.y + 1, now.d + 1));
		q.push(pos(now.x, now.y - 1, now.d + 1));
	}
	int start = ans[beg_x][beg_y];
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ('0' <= v[i][j] && v[i][j] <= '9' && ans[i][j] != -1) {
				if (ans[i][j] <= start) {
					res += v[i][j] - '0';
				}
			}
		}
	}
	printf("%d", res);
	return 0;
}