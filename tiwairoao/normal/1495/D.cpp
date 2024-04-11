#include <bits/stdc++.h>

const int N = 400;
const int M = 600;
const int P = 998244353;

int G[N + 5][N + 5], a[M + 5], b[M + 5], n, m;

bool v[N + 5]; int d[N + 5];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) G[i][j] = (i == j ? 0 : n + 5);
	for(int i=1;i<=m;i++) scanf("%d%d", &a[i], &b[i]), G[a[i]][b[i]] = G[b[i]][a[i]] = 1;
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		G[i][j] = std::min(G[i][j], G[i][k] + G[k][j]);
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if( i == j ) {
				for(int k=1;k<=n;k++) d[k] = 0;
				for(int x=1;x<=m;x++) {
					if( G[i][a[x]] + 1 == G[i][b[x]] )
						d[b[x]]++;
					else if( G[i][b[x]] + 1 == G[i][a[x]] )
						d[a[x]]++;
				}
				int ans = 1;
				for(int k=1;k<=n;k++) if( k != i ) ans = 1ll * ans * d[k] % P;
				printf("%d ", ans);
			} else if( G[i][j] == 1 ) {
				for(int k=1;k<=n;k++) d[k] = 0;
				for(int x=1;x<=m;x++) {
					if( G[i][a[x]] + 1 == G[i][b[x]] && G[j][a[x]] + 1 == G[j][b[x]] )
						d[b[x]]++;
					else if( G[i][b[x]] + 1 == G[i][a[x]] && G[j][b[x]] + 1 == G[j][a[x]] )
						d[a[x]]++;
				}
				int ans = 1;
				for(int k=1;k<=n;k++) if( k != i && k != j ) ans = 1ll * ans * d[k] % P;
				printf("%d ", ans);
			} else {
				bool flag = true;
				for(int k=0;k<=n;k++) d[k] = 0, v[k] = false;
				for(int k=1;k<=n;k++) if( G[i][k] + G[k][j] == G[i][j] ) {
					if( v[G[i][k]] ) {
						flag = false; break;
					} else v[G[i][k]] = true;
				}
				if( flag ) {
					for(int x=1;x<=m;x++) {
						if( G[i][a[x]] + G[b[x]][j] == G[i][j] ) continue;
						if( G[i][b[x]] + G[a[x]][j] == G[i][j] ) continue;
						
						if( G[i][a[x]] + 1 == G[i][b[x]] && G[j][a[x]] + 1 == G[j][b[x]] )
							d[b[x]]++;
						else if( G[i][b[x]] + 1 == G[i][a[x]] && G[j][b[x]] + 1 == G[j][a[x]] )
							d[a[x]]++;
					}
					
					int ans = 1;
					for(int k=1;k<=n;k++) if( G[i][k] + G[k][j] != G[i][j] ) ans = 1ll * ans * d[k] % P;
					printf("%d ", ans);
				} else printf("%d ", 0);
			}
		}
		puts("");
	}
}