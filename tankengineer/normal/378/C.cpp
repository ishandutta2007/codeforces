#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

int n, m, k;
char map[505][505];

int dis[505][505];

void bfs(int sx, int sy) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dis[i][j] = 1000000000;
		}
	}
	dis[sx][sy] = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(sx, sy));
	while (q.size()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '.') {
				if (dis[nx][ny] > dis[x][y] + 1) {
					dis[nx][ny] = dis[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
	}
	int sx = 0, sy = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == '.') {
				sx = i, sy = j;
			}
		}
	}
	bfs(sx, sy);
	vector<pair<int, pair<int, int> > > v;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == '.') {
				v.push_back(make_pair(dis[i][j], make_pair(i, j)));
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= v.size() - k; --i) {
		map[v[i].second.first][v[i].second.second] = 'X';
	}
	for (int i = 0; i < n; ++i) {
		puts(map[i]);
	}
	return 0;
}