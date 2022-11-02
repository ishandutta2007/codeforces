#include <bits/stdc++.h>

const int N = 1500;

int a[N + 5][N + 5], n, q;

int nx, ny;
struct node{
	int x[10], y[10], c, k;
}f[N + 5][N + 5];

int dis(int x, int y) {
	return std::max(x - nx + 1, y - ny + 1);
}

int x1[20], y1[20], x2[20], y2[20], b[N + 5];
node merge(const node &s, const node &t) {	
	int p = 0, ps = 0, pt = 0;
	while( ps < s.c && pt < t.c ) {
		if( a[s.x[ps]][s.y[ps]] < a[t.x[pt]][t.y[pt]] )
			x1[p] = s.x[ps], y1[p] = s.y[ps], p++, ps++;
		else x1[p] = t.x[pt], y1[p] = t.y[pt], p++, pt++;
	}
	while( ps < s.c ) x1[p] = s.x[ps], y1[p] = s.y[ps], p++, ps++;
	while( pt < t.c ) x1[p] = t.x[pt], y1[p] = t.y[pt], p++, pt++;
	
	int p2 = 0;
	for(int i=0,j=0;i<p;i=j) {
		int c = a[x1[i]][y1[i]];
		while( j < p && c == a[x1[j]][y1[j]] ) j++;
		
		int mn = i, mnk = dis(x1[i], y1[i]);
		for(int k=i;k<j;k++) {
			int d = dis(x1[k], y1[k]);
			if( mnk > d ) mnk = d, mn = k;
		}
		
		x2[p2] = x1[mn], y2[p2] = y1[mn], p2++;
	}
	
	int k = std::min(s.k, t.k) + 1;
	
	p = 0;
	for(int i=0;i<p2;i++) {
		int d = dis(x2[i], y2[i]);
		if( d <= k ) x1[p] = x2[i], y1[p] = y2[i], b[d]++, p++;
	}
	
	for(int tp = p; tp > q; tp -= b[k--]) ;
	
	p2 = 0;
	for(int i=0;i<p;i++) {
		int d = dis(x1[i], y1[i]); b[d]--;
		if( d <= k ) x2[p2] = x1[i], y2[p2] = y1[i], p2++;
	}
	
	node ret = {{}, {}, 0, 0}; ret.c = p2, ret.k = k - 1;
	for(int i=0;i<p2;i++) ret.x[i] = x2[i], ret.y[i] = y2[i];
	return ret;
}


int ans[N + 5];
int main() {
	scanf("%d%d", &n, &q);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d", &a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		f[i][j].c = 1, f[i][j].k = n, f[i][j].x[0] = i, f[i][j].y[0] = j;
	
	for(int i=1;i<=n;i++) f[i][n].k = f[n][i].k = 1;
	
	for(int i=n-1;i>=1;i--) for(int j=n-1;j>=1;j--) {
		nx = i, ny = j;
		f[i][j] = merge(merge(f[i + 1][j], f[i][j + 1]), merge(f[i + 1][j + 1], f[i][j]));
		f[i][j].k++;
	}
	
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans[f[i][j].k]++;
	for(int i=n;i>=1;i--) ans[i - 1] += ans[i];
	for(int i=1;i<=n;i++) printf("%d\n", ans[i]);
}