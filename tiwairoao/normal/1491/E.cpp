#include <bits/stdc++.h>

const int N = 200000;

int f[N + 5], id[N + 5], c;
void init() {
	f[0] = f[1] = 1;
	for(int i=2;i<=N;i++) id[i] = -1;
	for(c=2;;c++) {
		f[c] = f[c - 1] + f[c - 2];
		if( f[c] > N ) break; else id[f[c]] = c;
	}
	c--;
}

bool tag[N + 5];
struct edge{int t, i;};
std::vector<edge>G[N + 5];
void adde(int u, int v, int i) {
	G[u].push_back((edge){v, i}), G[v].push_back((edge){u, i});
}

std::vector<int>v; int fa[N + 5], siz[N + 5], d1;
void dfs(int x, int fat) {
	fa[x] = fat, siz[x] = 1;
	for(auto to : G[x]) if( !tag[to.i] && to.t != fat )
		dfs(to.t, x), siz[x] += siz[to.t];
	if( siz[x] == f[d1 - 1] || siz[x] == f[d1 - 2] )
		v.push_back(x);
}

bool check(int x, int d) {
	if( d <= 2 ) return true;
	
	v.clear(), d1 = d, dfs(x, 0);
	if( v.empty() ) return false;
	else if( v.size() == 1 ) {
		int y = v[0], z = fa[y];
		for(auto to : G[z]) if( to.t == y ) tag[to.i] = true;
		if( siz[y] == f[d - 1] ) return check(y, d - 1) && check(z, d - 2);
		else return check(y, d - 2) && check(z, d - 1);
	} else {
		int y1 = v[0], z1 = fa[y1], y2 = v[1], z2 = fa[y2];
		for(auto to : G[z1]) if( to.t == y1 ) tag[to.i] = true;
		for(auto to : G[z2]) if( to.t == y2 ) tag[to.i] = true;
		if( siz[y1] == f[d - 2] && siz[y2] == f[d - 2] )
			return check(y1, d - 2) && check(y2, d - 2) && check(z1, d - 3);
		else if( siz[y1] == f[d - 2] )
			return check(y1, d - 2) && check(z2, d - 2) && check(y2, d - 3);
		else
			return check(y2, d - 2) && check(z1, d - 2) && check(y1, d - 3);
	}
}

int main() {
	init(); int n; scanf("%d", &n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d", &u, &v), adde(u, v, i);
	if( id[n] != -1 && check(1, id[n]) ) puts("yES"); else puts("no");
}