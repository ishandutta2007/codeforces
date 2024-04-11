#include <bits/stdc++.h>

const int N = 20*20;
const int M = 4*N;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int pre[M + 5]; bool vis[M + 5];
std::vector<int>G[M + 5];
void adde(int u, int v) {G[u].push_back(v);}

int fa[N + 5], siz[N + 5], cnt;
int find(int x) {return fa[x] = (fa[x] == x ? x : find(fa[x]));}
void unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if( fx != fy ) fa[fx] = fy, siz[fy] += siz[fx];
}
bool check(int x, int y) {
	int fx = find(x), fy = find(y);
	return (fx != fy) && (siz[fx] + siz[fy] == cnt);
}

int u[M + 5], v[M + 5], tot;

int tag[N + 5], lim[N + 5];
std::vector<int>vec[2][N + 5];
bool aug() {
	for(int i=0;i<=tot+1;i++) pre[i] = -1, G[i].clear();
	for(int i=1;i<=cnt;i++) if( tag[i] ) 
		vec[0][i].clear(), vec[1][i].clear();
	for(int i=1;i<=tot;i++) {
		if( tag[u[i]] ) vec[vis[i]][u[i]].push_back(i);
		else if( tag[v[i]] ) vec[vis[i]][v[i]].push_back(i);
		else adde(i, tot + 1);
	}
	for(int i=1;i<=cnt;i++) if( tag[i] ) {
		if( (int)vec[1][i].size() < lim[i] ) {
			for(auto x : vec[0][i]) adde(x, tot + 1);
		} else {
			for(auto x : vec[0][i]) for(auto y : vec[1][i])
				adde(x, y);
		}
	}
	
	for(int i=1;i<=tot;i++) if( !vis[i] ) {
		for(int j=1;j<=cnt;j++) fa[j] = j, siz[j] = 1;
		for(int j=1;j<=tot;j++) if( !vis[j] && j != i )
			unite(u[j], v[j]);
		if( siz[find(1)] == cnt ) {
			adde(0, i);
			if( !G[i].empty() && G[i][0] == tot + 1 ) {vis[i] = true; return true;}
		}
		else {
			for(int j=1;j<=tot;j++) if( vis[j] && check(u[j], v[j]) )
				adde(j, i);
		}
	}
	
	std::queue<int>que; que.push(0);
	while( !que.empty() ) {
		int f = que.front(); que.pop();
		for(auto to : G[f]) if( pre[to] == -1 ) {
			pre[to] = f, que.push(to);
			if( to == tot + 1 ) break;
		}
		if( pre[tot + 1] != -1 ) break;
	}
	
	if( pre[tot + 1] == -1 ) return false;
	int nw = pre[tot + 1];
	while( nw ) vis[nw] ^= 1, nw = pre[nw];
	return true;
}

char ans[50][50]; int x[M + 5], y[M + 5];
char s[25][25]; int id[25][25], n, m;
void solve() {
	scanf("%d%d", &n, &m), cnt = tot = 0;
	for(int i=1;i<=n;i++) {
		scanf("%s", s[i] + 1);
		for(int j=1;j<=m;j++) {
			if( s[i][j] == 'O' ) {
				id[i][j] = (++cnt);
				if( (i + j) % 2 == 0 && !(i == 1 && j == 1) )
					tag[cnt] = true;
				else tag[cnt] = false;
			}
		}
	}
	
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if( s[i][j] == 'O' ) {
		if( i < n && s[i + 1][j] == 'O' ) {
			tot++, u[tot] = id[i][j], v[tot] = id[i + 1][j];
			x[tot] = 2*i, y[tot] = 2*j - 1, vis[tot] = false;
		}
		if( j < m && s[i][j + 1] == 'O' ) {
			tot++, u[tot] = id[i][j], v[tot] = id[i][j + 1];
			x[tot] = 2*i - 1, y[tot] = 2*j, vis[tot] = false;
		}
		if( tag[id[i][j]] ) {
			int x = id[i][j]; lim[x] = 0;
			for(int o=0;o<4;o++) {
				int p = i + dx[o], q = j + dy[o];
				if( p >= 1 && q >= 1 && p <= n && q <= m && s[p][q] == 'O' )
					lim[x]++;
			}
			lim[x] -= 2;
			if( lim[id[i][j]] < 0 ) {puts("NO"); return ;}
		}
	}
	
	int sum = 0; while( aug() ) sum++;
	if( tot - sum != cnt - 1 ) {puts("NO"); return ;}
	else puts("YES");
	
	memset(ans, 0, sizeof ans);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans[2*i - 1][2*j - 1] = s[i][j];
	for(int i=1;i<=tot;i++) if( !vis[i] ) ans[x[i]][y[i]] = 'O';
	for(int i=1;i<=2*n-1;i++) for(int j=1;j<=2*m-1;j++) {
		putchar(ans[i][j] ? ans[i][j] : ' ');
		if( j == 2*m - 1 ) puts("");
	}
}
int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}