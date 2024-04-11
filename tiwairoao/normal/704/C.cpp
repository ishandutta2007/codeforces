#include <map>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int MAXN = 100000;
const int MOD = 1000000007;

inline int add(int x, int y) {x += y; return x >= MOD ? x - MOD : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + MOD : x;}
inline int mul(int x, int y) {return 1LL * x * y % MOD;}

int deg[MAXN + 5]; vector<pii>G[MAXN + 5];
void addedge(int u, int v, int c) {
	deg[u]++, deg[v]++;
	G[u].push_back(mp(v, c));
	G[v].push_back(mp(u, c));
	
//	printf("! %d %d %d\n", u, v, c);
}

int ans[2];
void update(int a0, int a1) {
	int p0 = ans[0], p1 = ans[1];
	ans[0] = add(mul(a0, p0), mul(a1, p1));
	ans[1] = add(mul(a0, p1), mul(a1, p0));
}

int k[MAXN + 5], n, m;

int f[2][2][MAXN + 5]; bool vis[MAXN + 5];
void dfs1(int x, int lst) {
	vis[x] = true;
	
	for(int i=0;i<G[x].size();i++) {
		int to = G[x][i].fi;
		if( to == lst ) continue;
		
		if( G[x][i].se == 0 ) {
			for(int o=0;o<=1;o++) {
				f[o][0][to] = add(f[o][0][x], f[o][1][x]);
				f[o^1][1][to] = add(f[o^1][0][x], f[o][1][x]);
			}
		}
		else {
			for(int o=0;o<=1;o++) {
				f[o][0][to] = add(f[o^1][0][x], f[o][1][x]);
				f[o^1][1][to] = add(f[o][0][x], f[o][1][x]);
			}
		}
		dfs1(to, x);
		
		return ;
	}
	
	if( k[x] == 2 ) {
		for(int o=0;o<=1;o++)
			f[o][1][x] = add(f[o^1][0][x], mul(f[o][1][x], 2));
	}
	update(add(f[0][0][x], f[0][1][x]), add(f[1][0][x], f[1][1][x]));
}
int tmp[2], st; bool t;
void dfs2(int x, int lst) {
	vis[x] = t;
	
	pii to = G[x][0];
	if( to.fi == lst ) to = G[x][1];
	
	if( to.fi == st ) {
		if( (to.se ^ t) == 0 ) {
			tmp[0] = add(tmp[0], add(f[0][0][x], f[0][1][x]));
			tmp[1] = add(tmp[1], add(f[1][0][x], f[1][1][x]));
		}
		else {
			tmp[0] = add(tmp[0], add(f[1][0][x], f[0][1][x]));
			tmp[1] = add(tmp[1], add(f[0][0][x], f[1][1][x]));
		}
		
		return ;
	}
		
	for(int o1=0;o1<=1;o1++)
		for(int o2=0;o2<=1;o2++)
			f[o1][o2][to.fi] = 0;
		
	if( to.se == 0 ) {
		for(int o=0;o<=1;o++) {
			f[o][0][to.fi] = add(f[o][0][x], f[o][1][x]);
			f[o^1][1][to.fi] = add(f[o^1][0][x], f[o][1][x]);
		}
	}
	else {
		for(int o=0;o<=1;o++) {
			f[o][0][to.fi] = add(f[o^1][0][x], f[o][1][x]);
			f[o^1][1][to.fi] = add(f[o][0][x], f[o][1][x]);
		}
	}
	dfs2(to.fi, x);

	return ;
}

map<int, int>A;
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) {
		scanf("%d", &k[i]);
		for(int j=0,x;j<k[i];j++) {
			scanf("%d", &x);
			if( A.count(x) ) addedge(A[x], i, 0);
			else if( A.count(-x) ) addedge(A[-x], i, 1);
			else A[x] = i;
		}
	}
	
	ans[0] = 1, ans[1] = 0;
	for(int i=1;i<=m;i++)
		if( !A.count(i) && !A.count(-i) )
			ans[0] = mul(2, ans[0]);
	for(int i=1;i<=n;i++) {
		if( vis[i] ) continue;
		
		if( deg[i] == 0 )
			update(1, k[i] == 1 ? 1 : 3), vis[i] = true;
		else if( deg[i] == 1 ) {
			if( k[i] == 1 ) f[0][0][i] = 1;
			else f[0][0][i] = f[1][1][i] = 1;
			
			dfs1(i, -1);
		}
		else {
			if( G[i][0].fi == i ) {
				if( G[i][0].se == 0 ) update(1, 1);
				else update(0, 2);
				
				vis[i] = true;
			}
		}
	}
	for(int i=1;i<=n;i++) {
		if( !vis[i] ) {
			st = i, tmp[0] = tmp[1] = 0;
			f[0][0][i] = 1, t = 0, dfs2(i, -1), f[0][0][i] = 0;
			f[1][1][i] = 1, t = 1, dfs2(i, -1), f[1][1][i] = 0;
			update(tmp[0], tmp[1]);
		}
	}
	
	printf("%d\n", ans[1]);
}