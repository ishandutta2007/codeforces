#include<queue>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

char s[3], t[3];

int sx, sy, tx, ty;

int dis[8][8], dir[8][8];

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1},
	      dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

const char str[8][3] = {"LD", "L", "LU", "D", "U", "RD", "R", "RU"};

int main() {
	scanf("%s%s", s, t);
	sx = s[0] - 'a', sy = s[1] - '1';
	tx = t[0] - 'a', ty = t[1] - '1';
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			dis[i][j] = -1;
		}
	}
	queue<pair<int, int> > q;
	dis[sx][sy] = 0;
	q.push(make_pair(sx, sy));
	while (q.size() > 0) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int d = 0; d < 8; ++d) {
			int nx = x + dx[d], ny = y + dy[d];
			if (0 <= nx && nx < 8 && 0 <= ny && ny < 8 && dis[nx][ny] == -1) {
				dis[nx][ny] = dis[x][y] + 1;
				dir[nx][ny] = d;
				q.push(make_pair(nx, ny));
			}
		}
	}
	printf("%d\n", dis[tx][ty]);
	vector<int> path;
	{
		int x = tx, y = ty;
		while (x != sx || y != sy) {
			int d = dir[x][y];
			path.push_back(d);
			x -= dx[d];
			y -= dy[d];	
		}	
	}
	reverse(path.begin(), path.end());
	for (int i = 0; i < (int)path.size(); ++i) {
		printf("%s\n", str[path[i]]);
	}
	return 0;
}