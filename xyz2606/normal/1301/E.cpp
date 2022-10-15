#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int di[4] = {1, 1, -1, -1};
int dj[4] = {1, -1, 1, -1};
const int N = 505;
int col[4] = {'R', 'G', 'Y', 'B'};
char a[N][N];
int mx[N][N], f[N][N];
const int inf = 1e9;
int n, m, Q;
const int LG = 9;
int sgt[N][LG][N][LG];
void build2(int i1, int j1) {
	for(int i = 0; i < LG; i++) {
		for(int j = 1; j + (1 << i) - 1 <= m; j++) {
			if(i == 0) {
				sgt[i1][j1][j][i] = j1 == 0 ? f[i1][j] : max(sgt[i1][j1 - 1][j][0], sgt[i1 + (1 << (j1 - 1))][j1 - 1][j][0]);
			}else {
				sgt[i1][j1][j][i] = max(sgt[i1][j1][j][i - 1], sgt[i1][j1][j + (1 << (i - 1))][i - 1]);
			}
		}
	}
}

void build1() {
	for(int i(0); i < LG; i++) {
		for(int j = 1; j + (1 << i) - 1 <= n; j++) {
			build2(j, i);
		}
	}
}
__inline int query(int ql, int qr, int l2, int r2) {
	
	int len = qr - ql + 1;
	int lg = ilogb(len);
	int len2 = r2 - l2 + 1;
	int lg2 = ilogb(len2);
	return max(max(sgt[ql][lg][l2][lg2], sgt[ql][lg][r2 - (1 << lg2) + 1][lg2]), max(sgt[qr - (1 << lg) + 1][lg][l2][lg2],sgt[qr - (1 << lg) + 1][lg][r2 - (1 << lg2) + 1][lg2]));
}
const int M = 300011;
int ans[300011], r2[M], c2[M], r1[M], c1[M];
int main() {
	scanf("%d%d%d", &n, &m, &Q);
	//n = 500, m = 500, Q = 300000;
	int bg[3] = {500, 0, 1};
	int ed[3] = {1, 0, 500};
	
	for(int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
	}
	for(int i = 1; i <= Q; i++) {
		scanf("%d%d%d%d", &r1[i], &c1[i], &r2[i], &c2[i]);
	}
	for(int _ = 0; _ < 1; _++) {
		for(int i = 1; i < n; i++) for(int j = 1; j < m; j++) f[i][j] = inf;
		for(int d = 0; d < 4; d++) {
			for(int i(bg[di[d] + 1]); i >= 1 && i <= 500; i += di[d]) {
				for(int j(bg[dj[d] + 1]); j >= 1 && j <= 500; j += dj[d]) {
					if(a[i][j] != col[d]) {
						mx[i][j] = 0;
					}else {
						mx[i][j] = 1;
						if(i != bg[di[d] + 1] && a[i - di[d]][j] == col[d] && j != bg[dj[d] + 1] && a[i][j - dj[d]] == col[d]) {
							mx[i][j] = min(mx[i - di[d]][j], mx[i][j - dj[d]]);
							if(a[i - di[d] * mx[i][j]][j - dj[d] * mx[i][j]] == col[d]) mx[i][j]++;
						}
					}
					int I = di[d] == 1 ? i : i - 1;
					int J = dj[d] == 1 ? j : j - 1;
					//printf("%c %d %d: %d\n", col[d], i, j, mx[i][j]);
					if(I >= 1 && J >= 1) {
						f[I][J] = min(f[I][J], mx[i][j]);
					}
				}
			}
		}

		//for(int i = 1; i < n; i++) for(int j = 1; j < m; j++) printf("f[%d][%d] = %d\n", i, j, f[i][j]);
		build1();
		//cerr << clock() << endl;
		for(int i(1); i <= Q; i++) {
			int x1(r1[i]), y1(c1[i]), x2(r2[i]), y2(c2[i]);
			//printf("%d\n", i);
			//x1 = 1, y1 = 1, x2 = n, y2 = m;
			if(x1 > x2) swap(x1, x2);
			if(y1 > y2) swap(y1, y2);
			int le = 0, ri = (min(y2 - y1, x2 - x1) + 1) / 2;
			while(le != ri) {
				int mid = (le + ri + 1) / 2;			
				if(query(x1 + mid - 1, x2 - mid, y1 + mid - 1, y2 - mid) >= mid) {
					le = mid;
				}else ri = mid - 1;
			}
			ans[i] = max(ans[i], le * le * 4);
		}
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
			a[i][j] = a[i][j] == 'Y' ? 'R' : a[i][j] == 'R' ? 'G' : a[i][j] == 'B' ? 'Y' : 'B';
		}
	}
	for(int i = 1; i <= Q; i++) {
		printf("%d\n", ans[i]);
	}
	//	cerr << clock() << endl;
}