#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000 + 1;
int n, m;
char map[N][N];

const int NN = 1000 * 1000, M = NN * 4;
int top, head[NN], to[M], next[M], dgr[NN];

void addedge(int u, int v) {
	to[top] = v, next[top] = head[u], head[u] = top++;
}

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

inline int ch(char a) {
	if (a == 'D') {
		return 0;
	} else if (a == 'I') {
		return 1;
	} else if (a == 'M') {
		return 2;
	} else if (a == 'A') {
		return 3;
	}
	return -1;
}

int dis[NN];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
	}
	top = 0;
	memset(head, -1, sizeof(head));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int u = i * m + j;
			for (int d = 0; d < 4; ++d) {
				int tx = i + dx[d], ty = j + dy[d];
				if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
					continue;
				}
				if (ch(map[tx][ty]) != (ch(map[i][j]) + 1) % 4) {
					continue;
				}
				int v = tx * m + ty;
				addedge(u, v);
				++dgr[v];
			}
		}
	}
	vector<int> q;
	for (int i = 0; i < n * m; ++i) {
		if (dgr[i] == 0) {
			q.push_back(i);
		}
	}
	for (int i = 0; i < (int)q.size(); ++i) {
		int u = q[i];
		for (int j = head[u]; ~j; j = next[j]) {
			int v = to[j];
			if ((--dgr[v]) == 0) {
				q.push_back(v);
			}
		}
	}
	if (q.size() < n * m) {
		printf("Poor Inna!\n");
	} else {
		int ans = 0;
		for (int i = n * m - 1; i >= 0; --i) {
			int u = q[i];
			dis[u] = 1;
			for (int j = head[u]; ~j; j = next[j]) {
				int v = to[j];
				dis[u] = max(dis[u], dis[v] + 1);
			}
			if (map[i / m][i % m] == 'D') {
				ans = max(ans, dis[u]);
			}
		}
		ans /= 4;
		if (ans == 0) {
			printf("Poor Dima!\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}