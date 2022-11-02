#include <bits/stdc++.h>

const int N = 100000;

std::vector<int>G[N + 5];
void adde(int u, int v) {G[u].push_back(v), G[v].push_back(u);}

int n, a, b, c[N + 5], d; bool vis[N + 5];
bool dfs(int x, int fa) {
	c[++d] = x, vis[x] = true; if( x == b ) return true;
	for(auto to : G[x]) if( to != fa && dfs(to, x) ) return true;
	c[d--] = 0, vis[x] = false; return false;
}

int mx[3][N + 5], mxd[N + 5]; bool tag[N + 5];
void dfs2(int x, int fa) {
	mxd[x] = mx[0][x] = mx[1][x] = mx[2][x] = 0;
	for(auto to : G[x]) if( to != fa ) {
		dfs2(to, x), mxd[x] = std::max(mxd[x], mxd[to] + 1);
		if( mxd[to] > mxd[mx[0][x]] ) mx[2][x] = mx[1][x], mx[1][x] = mx[0][x], mx[0][x] = to;
		else if( mxd[to] > mxd[mx[1][x]] ) mx[2][x] = mx[1][x], mx[1][x] = to;
		else if( mxd[to] > mxd[mx[2][x]] ) mx[2][x] = to;
	}
}
void dfs3(int x, int fa, int dis) {
	if( mxd[mx[0][x]] + 1 >= d - 1 && mxd[mx[1][x]] + 1 >= d - 1 && mxd[mx[2][x]] + 1 >= d - 1 )
		tag[x] = true;
	else if( mxd[mx[0][x]] + 1 >= d - 1 && mxd[mx[1][x]] + 1 >= d - 1 && dis >= d - 1 )
		tag[x] = true;
	else tag[x] = false;
	
	for(auto to : G[x]) if( to != fa )
		dfs3(to, x, std::max(dis, (to == mx[0][x] ? mxd[mx[1][x]] : mxd[mx[0][x]]) + 1) + 1);
}
void dfs4(int x, int fa) {
	mxd[x] = 0;
	for(auto to : G[x]) if( to != fa && !vis[to] )
		dfs4(to, x), mxd[x] = std::max(mxd[x], mxd[to] + 1), tag[x] |= tag[to];
}


void solve() {
	scanf("%d%d%d", &n, &a, &b), d = 0;
	for(int i=1;i<=n;i++) G[i].clear(), vis[i] = false;
	for(int i=1,u,v;i<n;i++) scanf("%d%d", &u, &v), adde(u, v);
	mxd[0] = -1, dfs(a, 0), dfs2(1, 0), dfs3(1, 0, 0);
	for(int i=1;i<=d;i++) dfs4(c[i], 0);
	
	int l = 1, r = d, l1 = 0, r1 = d + 1;
	while( l1 < l || r1 > r ) {
		while( l1 < l ) {
			l1++; if( tag[c[l1]] ) {puts("YES"); return ;}
			r = std::min(d - mxd[c[l1]] + (l1 - 1), r), r = std::max(1, r);
		}
		while( r1 > r ) {
			r1--; if( tag[c[r1]] ) {puts("YES"); return ;}
			l = std::max(1 + mxd[c[r1]] - (d - r1), l), l = std::min(d, l);
		}
	}
	puts("NO");
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}