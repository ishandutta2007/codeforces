#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 105, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int n, m;

char map[N][N];

bool vis[N][N];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%s", map[i]);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				vis[i][j] = false;
			}
		}
		bool valid = true;
		for (int i = 0; i < n && valid; ++i) {
			for (int j = 0; j < m && valid; ++j) {
				if (!vis[i][j] && map[i][j] == '1') {
					int size = 0, minx = i, maxx = i, miny = j, maxy = j;
					queue<pair<int, int> > q;
					q.push(make_pair(i, j));
					vis[i][j] = true;
					while (q.size()) {
						int x = q.front().first, y = q.front().second;
						minx = min(minx, x);
						maxx = max(maxx, x);
						miny = min(miny, y);
						maxy = max(maxy, y);
						++size;
						q.pop();
						for (int d = 0; d < 4; ++d) {
							int tx = x + dx[d], ty = y + dy[d];
							if (0 <= tx && tx < n && 0 <= ty && ty < m) {
								if (map[tx][ty] == '1' && !vis[tx][ty]) {
									vis[tx][ty] = true;
									q.push(make_pair(tx, ty));
								}
							}
						}
					}
					if (size != (maxx - minx + 1) * (maxy - miny + 1)) {
						valid = false;
					}
				}
			}
		}
		printf("%s\n", valid ? "YES" : "NO");
	}
	return 0;
}