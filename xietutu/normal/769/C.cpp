#include <bits/stdc++.h>
using namespace std;
const int xy[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}}; //D L R U
const char str[5] = "DLRU";
#define X first
#define Y second
typedef pair<int, int> pii;
int n, k, m, dis[1005][1005];
char s[1005][1005];
pii st;
queue<pii> Q;
void BFS(pii st) {
	memset(dis, 255, sizeof dis);
	Q.push(st);
	dis[st.X][st.Y] = 0;
	while (Q.size()) {
		pii now = Q.front();
		Q.pop();
		int x = now.X, y = now.Y;
		for (int i = 0; i < 4; ++i) {
			int xx = x + xy[i][0], yy = y + xy[i][1];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && s[xx][yy] == '.' && dis[xx][yy] == -1) {
				dis[xx][yy] = dis[x][y] + 1;
				Q.push(pii(xx, yy));
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; ++j)
			if (s[i][j] == 'X') st = pii(i, j);
	}
	bool flag = false;
	for (int i = 0; i < 4; ++i) {
		int x = st.X + xy[i][0], y = st.Y + xy[i][1];
		if (x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] == '.') flag = true;
	}
	if (k % 2) flag = false;
	if (flag) {
		BFS(st);
		int x = st.X, y = st.Y;
		for (int t = 1; t <= k; ++t) {
			for (int i = 0; i < 4; ++i) {
				int xx = x + xy[i][0], yy = y + xy[i][1];
				if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && s[xx][yy] != '*' && dis[xx][yy] != -1 && dis[xx][yy] <= k - t) {
					x = xx; y = yy; 
					putchar(str[i]);
					break;
				}
			}
		}
	}
	else puts("IMPOSSIBLE");
}