#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int mult(int a, int b) { return (1LL*a*b)%MOD; }
int binpow(int x, int p) {
	int ans = 1;
	while (p) {
		if (p&1) ans = mult(ans,x);
		p>>=1;
		x = mult(x,x);
	}
	return ans;
}
int inv(int x) { return binpow(x,MOD-2); }

int n;
int rev[4];
int grid[1013][1013];
int prod[1013][1013][8], revp[1013][1013][8];
double prodl[1013][1013][8];
int len[1013][1013][8];

int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

void process(int d) {
	int si = 1, ei = n, di = dx[d]+(dx[d]==0);
	if (dx[d]==-1) swap(si,ei);
	int sj = 1, ej = n, dj = dy[d]+(dy[d]==0);
	if (dy[d]==-1) swap(sj,ej);
	for (int i=si;i!=ei+di;i+=di) {
		for (int j=sj;j!=ej+dj;j+=dj) {
			if (grid[i][j]==0) continue;
			int pi = i-dx[d], pj = j-dy[d];
			if (grid[pi][pj]==0) {
				prod[i][j][d] = grid[i][j];
				revp[i][j][d] = rev[grid[i][j]];
				prodl[i][j][d] = log(grid[i][j]);
				len[i][j][d] = 1;
			} else {
				prod[i][j][d] = mult(prod[pi][pj][d],grid[i][j]);
				revp[i][j][d] = mult(revp[pi][pj][d],rev[grid[i][j]]);
				prodl[i][j][d] = prodl[pi][pj][d]+log(grid[i][j]);
				len[i][j][d] = len[pi][pj][d]+1;
			}
		}
	}
}

int main() {
	for (int i=0;i<4;i++) rev[i] = inv(i);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			char c;
			scanf(" %c",&c);
			grid[i][j] = c-'0';
		}
	}
	for (int i=0;i<=n+1;i++) {
		for (int j=0;j<=n+1;j++) {
			for (int d=0;d<8;d++) {
				prod[i][j][d] = revp[i][j][d] = 1;
			}
		}
	}
	for (int d=0;d<8;d++) process(d);
	double best = -1;
	int ans = 0;
	for (int r=0;r<2;r++) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				if (grid[i][j]==0) continue;
				int l = 1e9;
				for (int d=r;d<8;d+=2) l = min(l,len[i][j][d]);
				double cur = 0;
				int res = 1;
				for (int d=r;d<8;d+=2) {
					int pi = i-dx[d]*l, pj = j-dy[d]*l;
					cur+=prodl[i][j][d]-prodl[pi][pj][d];
					res = mult(res,mult(prod[i][j][d],revp[pi][pj][d]));
				}
				for (int w=0;w<3;w++) {
					cur-=log(grid[i][j]);
					res = mult(res,rev[grid[i][j]]);
				}
				if (cur>best) {
					best = cur;
					ans = res;
				}
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}