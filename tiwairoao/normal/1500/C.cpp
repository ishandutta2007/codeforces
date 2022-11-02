#include <bits/stdc++.h>

const int N = 1500;

std::vector<int>ans;

int a[N + 5][N + 5], b[N + 5][N + 5], n, m;

int f[N + 5][N + 5], g[N + 5][N + 5];

bool bc[N + 5]; int c[N + 5], t[N + 5], s;
void update(int x, int d) {
	for(int j=1;j<=m;j++) if( f[c[x] + 1][j] < c[x + 1] ) t[j] += d;
}
void add(int x) {
	if( bc[x] ) return ; bc[x] = true;
	
	for(int i=s;i>=0;i--) if( c[i] < x ) {
		update(i, -1);
		for(int j=s;j>i;j--) c[j + 1] = c[j];
		c[i + 1] = x, update(i, 1), update(i + 1, 1);
		break;
	}
	s++;
}

int tmp[N + 5], tmp2[N + 5];
std::vector<int>v[N + 5];
void msort(int x) {
	for(int i=1;i<=n;i++) v[i].clear();
	for(int i=1;i<=n;i++) v[a[tmp[i]][x]].push_back(i);
	
	int cnt = 0;
	for(int i=1;i<=n;i++) for(auto j : v[i])
		tmp2[++cnt] = tmp[j];
	for(int i=1;i<=n;i++) tmp[i] = tmp2[i];
}
bool check() {
	for(int i=1;i<=n;i++) tmp[i] = i;
	for(int k = (int)ans.size() - 1; k >= 0; k--)
		msort(ans[k]);
	
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		if( a[tmp[i]][j] != b[i][j] ) return false;
	return true;
}

bool vis[N + 5];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d", &a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d", &b[i][j]);
	for(int j=1;j<=m;j++) {
		f[n][j] = g[n][j] = n;
		for(int i=n-1;i>=1;i--) {
			if( b[i][j] == b[i + 1][j] ) g[i][j] = g[i + 1][j];
			else g[i][j] = i;
			
			if( b[i][j] <= b[i + 1][j] ) f[i][j] = f[i + 1][j];
			else f[i][j] = i;
		}
	}
	
	bc[c[0] = 0] = bc[c[s = 1] = n] = true, update(0, 1);
	
	while( true ) {
		int p = -1;
		for(int j=1;j<=m;j++) if( !vis[j] && !t[j] ) {
			p = j; break;
		}
		if( p == -1 ) break;
		
		ans.push_back(p), vis[p] = true;
		for(int q = 1; q <= n; q++)
			add(q = g[q][p]);
	}
	
	if( check() ) {
		printf("%d\n", (int)ans.size());
		for(int k = (int)ans.size() - 1; k >= 0; k--)
			printf("%d ", ans[k]);
	} else puts("-1");
}