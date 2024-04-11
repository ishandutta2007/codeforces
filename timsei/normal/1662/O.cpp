#include<bits/stdc++.h>
using namespace std;
const int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int T, n, vis[25][365][4], in[25][365];
char ty[2];
inline int Nxt(int x) {
	return (x + 1) % 360;
}
inline int Pre(int x) {
	return (x + 359) % 360;
}
queue<pair<int, int> > q;
int main() {
	for(scanf("%d", &T); T --; ) {
		scanf("%d", &n);
		memset(vis, 0, sizeof vis);
		memset(in, 0, sizeof in);
		for(int i = 1, a, b, c; i <= n; ++ i) {
			scanf("%s%d%d%d", ty + 1, &a, &b, &c);
			if(ty[1] == 'C') {
				for(int l = b; l != c; l = Nxt(l))
					vis[a - 1][l][2] = 1, vis[a][l][3] = 1;
			}
			else {
				for(int i = a; i < b; ++ i)
					vis[i][Pre(c)][0] = 1, vis[i][c][1] = 1;
			}
		}
		while(!q.empty())
			q.pop();
		q.push({0, 0});
		in[0][0] = 1;
		int flg = 0;
		while(!q.empty()) {
			int a = q.front().first, b = q.front().second;
			q.pop();
			if(a > 20) {
				flg = 1;
				break;
			}
			for(int k = 0; k < 4; ++ k) {
				if(vis[a][b][k])
					continue;
				int na = a + step[k][0], nb = b + step[k][1];
				nb = (nb + 360) % 360;
				if(na >= 0 && na < 25 && !in[na][nb])
					in[na][nb] = 1, q.push({na, nb});
			}
		}
		puts(flg ? "YES" : "NO");
	}
}