#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[1005][1005], b[1005][1005], vis[1005][1005];

int ok(int x, int y)
{
	if(x < 0 || x >= n - 1 || y < 0 || y >= m - 1 || vis[x][y] == 1) return -2;
	int col = -1;
	rep(dx, 2) rep(dy, 2) {
		int nx = x + dx, ny = y + dy;
		if(a[nx][ny] != -1 && (a[nx][ny] != col && col != -1)) return -2;
		if(col == -1) col = a[nx][ny];
	}
	return col;
}
int main()
{
	scanf("%d%d", &n, &m);
	rep(i, n) rep(j, m) scanf("%d", &a[i][j]), b[i][j] = a[i][j];
	vector<PII> que;
	vector<int> cc;
	rep(i, n) rep(j, m) if(ok(i, j) != -2) {
		cc.push_back(ok(i, j));
		que.push_back(MP(i, j)), vis[i][j] = 1;
		rep(dx, 2) rep(dy, 2) a[i + dx][j + dy] = -1;
	}
	rep(i, que.size()) {
		int x = que[i].first, y = que[i].second;
		rep(i, 2) rep(j, 2) a[x + i][y + j] = -1;
		for(int i = -2; i <= 2; i ++) for(int j = -2; j <= 2; j ++) {
			int nx = x + i, ny = y + j;
			if(ok(nx, ny) != -2) {
				cc.push_back(ok(nx, ny));
				que.push_back(MP(nx, ny));
				vis[nx][ny] = 1;
			}
		}
	}
	bool is = true;
	rep(i, n) rep(j, m) is &= (a[i][j] == -1);
	if(!is) {
		printf("-1"); return 0;
	}
	printf("%d\n", que.size());
	reverse(que.begin(), que.end());
	reverse(cc.begin(), cc.end());
	rep(i, que.size()) {
		int pc = cc[i];
		if(pc == -1) pc = 1;
		printf("%d %d %d\n", que[i].first + 1, que[i].second + 1, pc);
	}
	return 0;
}