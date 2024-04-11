#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
const char dir[] = "UDRL";

const int BAR = 105, N = 275, INF = 200000000;
int vx, vy, sx, sy, m;
char map[N][N];

int dis[N][N];
char fa[N][N];

int lbar, rbar, ubar, dbar;

bool outside(int x, int y) {
	return (x < lbar - 1) && (y < dbar - 1);
}

void BFS(int sx, int sy, int ex = -1, int ey = -1) {
	memset(dis, -1, sizeof(dis));
	queue<pair<int, int> > q;
	q.push(make_pair(sx, sy));
	dis[sx][sy] = 0;
	while (q.size()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int d = 0; d < 4; ++d) {
			int tx = x + dx[d], ty = y + dy[d];
			if (tx >= 0 && tx < N && ty >= 0 && ty < N && map[tx][ty] != '#' && dis[tx][ty] == -1) {
				dis[tx][ty] = dis[x][y] + 1;
				fa[tx][ty] = d ^ 1;
				if (tx == ex && ty == ey) {
					break;
				}
				q.push(make_pair(tx, ty));
			}
		}
	}
}

string s;

void go(int d, int step) {
	for (int i = 0; i < step; ++i) {
		s += dir[d];
		vx += dx[d], vy += dy[d];
		sx += dx[d], sy += dy[d];
		if (sx >= 0 && sx < N && sy >= 0 && sy < N && map[sx][sy] == '#') {
			sx -= dx[d], sy -= dy[d];
		}
	}
}

int main() {
	scanf("%d%d%d%d%d", &vx, &vy, &sx, &sy, &m);
	vx += BAR, vy += BAR, sx += BAR, sy += BAR;
	if (m == 0) {
		printf("-1\n");
		return 0;
	}
	pair<int, int> left, right, up, down;
	left.first = N;
	right.first = -N;
	up.second = -N;
	down.second = N;
	for (int i = 0; i < m; ++i) {
		int tx, ty;
		scanf("%d%d", &tx, &ty);
		tx += BAR, ty += BAR;
		if (tx < left.first) {
			left = make_pair(tx, ty);
		}
		if (tx > right.first) {
			right = make_pair(tx, ty);
		}
		if (ty > up.second) {
			up = make_pair(tx, ty);
		}
		if (ty < down.second) {
			down = make_pair(tx, ty);
		}
		map[tx][ty] = '#';
	}
	lbar = left.first;
	rbar = right.first;
	dbar = down.second;
	ubar = up.second;
	BFS(vx, vy);
	if (dis[sx][sy] == -1) {
		printf("-1\n");
		return 0;
	}
	int type = 0;
	int orix = lbar - 2, oriy = dbar - 2;
	if (dis[orix][oriy] == -1) {
		type = 1;
		memset(fa, -1, sizeof(fa));
		while (sx != vx || sy != vy) {
			int ans = fa[vx][vy];
			if (ans == -1) {
				memset(fa, -1, sizeof(fa));
				BFS(sx, sy, vx, vy);
				ans = fa[vx][vy];
			}
			go(ans, 1);
		}
	} else {
		if(!outside(vx, vy)) {
			BFS(orix, oriy, vx, vy);
		}
		while (!outside(vx, vy)) {
			int ans = fa[vx][vy];
			go(ans, 1);
		}
		go(1, 205);
		go(3, 205);
		if (!outside(sx, sy)) {
			if (sx >= 0 && sx < N && sy >= 0 && sy < N) {
				BFS(orix, oriy, sx, sy);
				while (!outside(sx, sy)) {
					int ans = fa[sx][sy];
					go(ans, 1);
				}
			} else {
				go(3, 205);
			}
		}
		go(1, 205);
		go(3, 205);
		if (vx < sx) {
			//use the left tree
			while (sx > 0 || vx > 0) {
				go(3, 1);
			}
			while (sy != left.second) {
				int d = sy > left.second ? 1 : 0;
				go(d, 1);
			}
			while (vx < sx) {
				go(2, 1);
			}
			go(1, 405);
			go(3, 205);
		} else if (sx < vx) {
			//use the right tree
			while (sx < N || vx < N) {
				go(2, 1);
			}
			while (sy != right.second) {
				int d = sy > right.second ? 1 : 0;
				go(d, 1);
			}
			while (sx < vx) {
				go(3, 1);
			}
			go(1, 405);
			go(3, 805);
		}
		if (vy < sy) {
			//use the down tree
			while (sy > 0 || vy > 0) {
				go(1, 1);
			}
			while (sx != down.first) {
				int d = sx < down.first ? 2 : 3;
				go(d, 1);
			}
			while (vy < sy) {
				go(0, 1);
			}
		} else if (sy < vy) {
			//use the up tree
			while (sy < N || vy < N) {
				go(0, 1);
			}
			while (sx != up.first) {
				int d = sx < up.first ? 2 : 3;
				go(d, 1);
			}
			while (sy < vy) {
				go(1, 1);
			}
		}
	}
if (vx != sx || vy != sy) {
	printf("WA %d\n", type);
} else {
	printf("%s\n", s.c_str());
}
	return 0;
}