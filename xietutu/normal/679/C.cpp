#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef unsigned int ui;
#define PB push_back
#define MP make_pair
#define X first
#define Y second
const int xy[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
typedef pair<int, int> pii;
const int maxn = 505 * 505;
int n, m, k, ans, ret, tot;
int in[maxn], cnt[maxn], now[maxn];
char s[505][505];
int no[505][505];
queue<pii> Q;
void BFS(int color, pii st) {
	Q.push(st);
	no[st.X][st.Y] = color;
	while (Q.size()) {
		int x = Q.front().X, y = Q.front().Y;
		++cnt[color];
		Q.pop();
		for (int k = 0; k < 4; ++k) {
			int xx = x + xy[k][0], yy = y + xy[k][1];
			if (s[xx][yy] == '.' && !no[xx][yy]) {
				no[xx][yy] = color;
				Q.push(pii(xx, yy));
			}
		}
	}
}
inline void add(int x, int y) {
	if ((++in[no[x][y]]) == 1) tot += cnt[no[x][y]], ret += now[no[x][y]];
}
inline void sub(int x, int y) {
	if ((--in[no[x][y]]) == 0) tot -= cnt[no[x][y]], ret -= now[no[x][y]];
}
void solve(int R) {
	tot = ret = 0;
	memset(in, 0, sizeof in);
	memset(now, 0, sizeof now);
	
	for (int i = R; i < R + k; ++i) 
		for (int j = 1; j <= k; ++j)
			if (s[i][j] == '.') 
				++now[no[i][j]];
				
	for (int j = 1; j <= k; ++j) {
		if (s[R - 1][j] == '.') add(R - 1, j);
		if (s[R + k][j] == '.') add(R + k, j);
	}
	
	for (int i = R; i < R + k; ++i) 
		if (s[i][k + 1] == '.') add(i, k + 1);
	ans = max(ans, tot + k * k - ret);
	
	//printf("%d 1 %d\n", R, tot + k * k - ret);
	
	for (int c = 1; c <= n - k; ++c) {
		for (int i = R; i < R + k; ++i) 
			if (s[i][c] == '.') {
				--now[no[i][c]];
				if (in[no[i][c]]) --ret;
			}
		
		for (int i = R; i < R + k; ++i) {
			if (s[i][c + k] == '.') sub(i, c + k);
			if (s[i][c - 1] == '.') sub(i, c - 1);
			if (s[i][c] == '.') add(i, c);
			if (s[i][c + k + 1] == '.') add(i, c + k + 1);
		}
		
		if (s[R - 1][c] == '.') sub(R - 1, c);
		if (s[R + k][c] == '.') sub(R + k, c);
		if (s[R - 1][c + k] == '.') add(R - 1, c + k);
		if (s[R + k][c + k] == '.') add(R + k, c + k);
		
		for (int i = R; i < R + k; ++i)
			if (s[i][c + k] == '.') {
				++now[no[i][c + k]];
				if (in[no[i][c + k]]) ++ret;
			} 
		//printf("%d %d %d\n", R, c + 1, tot + k * k - ret);
		ans = max(ans, tot + k * k - ret);
	}
}
int main() {
	scanf("%d%d", &n, &k);
	if (k == n) {
		printf("%d\n", n * n);
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (s[i][j] == '.' && !no[i][j]) BFS(++m, pii(i, j));
	
	for (int i = 1; i <= n - k + 1; ++i)
		solve(i);
	
	printf("%d\n", ans);
}