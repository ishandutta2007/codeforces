#include <bits/stdc++.h>

const int S = 640;
const int N = 100000;
const int INF = (1 << 30);

int fa[S + 5][N + 5], f[N + 5][S + 5];
int find(int o, int x) {return fa[o][x] = (fa[o][x] == x ? x : find(o, fa[o][x]));}

int l[N + 5], v[N + 5], m; bool vis[S + 5];
int solve() {
	for(int i=0;i<=S;i++) vis[i] = false;
	for(int j=0;j<=S;j++) for(int i=1;i<=m+1;i++) fa[j][i] = i, f[i][j] = -INF;
	for(int i=1;i<=m;i++) fa[0][i] = i + 1, f[i][0] = INF;
	
	for(int i=m;i>=1;i--) {
		l[i] = 0;
		while( f[i][l[i]] != -INF ) l[i]++;
		vis[--l[i]] = true;
		
		for(int j=0;j<=l[i];j++) f[i][j] = (v[i] << 1) - f[i][j];
		for(int j=1;j<=l[i];j++) f[i][j] = std::max(f[i][j], f[i][j - 1]);
		for(int j=0;j<=l[i];j++) f[i][j] = std::upper_bound(v + 1, v + m + 1, f[i][j]) - v;
		
		for(int j=0;j<l[i];j++) {
			int le = f[i][j], ri = f[i][j + 1] - 1;
			for(int p=find(j+1,le);p<=ri;p=find(j+1,le))
				f[p][j + 1] = v[i], fa[j + 1][p] = p + 1;
		}
		
		int le = f[i][l[i]], ri = m;
		for(int p=find(l[i]+1,le);p<=ri;p=find(l[i]+1,le))
			f[p][l[i] + 1] = v[i], fa[l[i] + 1][p] = p + 1;
	}
	
	int ret = 0; while( vis[ret] ) ret++; return ret;
}

int main() {
	int ans = 0, n; scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", &m);
		for(int j=1;j<=m;j++) scanf("%d", &v[j]);
		ans ^= solve();
	}
	puts(ans ? "YES" : "NO");
}