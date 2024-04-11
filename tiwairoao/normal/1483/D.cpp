#include <bits/stdc++.h>

const int N = 600;
const int INF = int(1E9) + 5;

bool tag[N + 5][N + 5];
int G[N + 5][N + 5], d[N + 5][N + 5], l[N + 5][N + 5], n;

int main() {
	int m; scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		G[i][j] = (i == j ? 0 : INF);
	for(int i=1,u,v,w;i<=m;i++) {
		scanf("%d%d%d", &u, &v, &w);
		G[u][v] = G[v][u] = w;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		d[i][j] = G[i][j];
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		d[i][j] = std::min({d[i][j], d[i][k] + d[k][j], INF});
	
	int q; scanf("%d", &q);
	for(int i=1,u,v,w;i<=q;i++) {
		scanf("%d%d%d", &u, &v, &w);
		l[u][v] = l[v][u] = w;
	}
	
	for(int s=1;s<=n;s++) for(int v=1;v<=n;v++) {
		int mx = l[s][1] - d[v][1];
		for(int t=1;t<=n;t++) mx = std::max(mx, l[s][t] - d[v][t]);
		for(int u=1;u<=n;u++) if( d[s][u] + G[u][v] <= mx )
			tag[u][v] = tag[v][u] = true;
	}
	
	int ans = 0;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
		ans += tag[i][j];
	printf("%d\n", ans);
}