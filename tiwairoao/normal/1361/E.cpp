#include <bits/stdc++.h>

const int N = 100000;
const int M = 200000;

std::vector<int>G[N + 5]; int n, m;
void adde(int u, int v) {G[u].push_back(v);}

bool tag[N + 5], flag;
int dfn[N + 5], low[N + 5], dcnt;
void dfs(int x) {
	dfn[x] = low[x] = (++dcnt), tag[x] = true;
	for(auto to : G[x]) {
		if( !dfn[to] ) dfs(to), low[x] = std::min(low[x], low[to]);
		else {
			if( !tag[to] ) flag = false;
			low[x] = std::min(low[x], dfn[to]);
		}
	}
	tag[x] = false;
}
bool check(int x) {
	for(int i=1;i<=n;i++) dfn[i] = low[i] = 0;
	
	flag = true, dfs(x);
	if( flag ) {
		for(int i=1;i<=n;i++)
			if( !dfn[i] ) return false;
		return true;
	} else return false;
}

namespace heap{
	int ch[2][M + 5], dis[M + 5], key[M + 5], ncnt;
	int newnode(int k) {
		int p = (++ncnt);
		key[p] = k, dis[p] = 1, ch[0][p] = ch[1][p] = 0;
		return p;
	}
	void pushup(int x) {
		if( dis[ch[0][x]] < dis[ch[1][x]] )
			std::swap(ch[0][x], ch[1][x]);
		dis[x] = dis[ch[1][x]] + 1;
	}
	int merge(int x, int y) {
		if( !x || !y ) return x + y;
		if( dfn[key[x]] < dfn[key[y]] ) std::swap(x, y);
		ch[1][x] = merge(ch[1][x], y);
		pushup(x); return x;
	}
	void erase(int &x) {x = merge(ch[0][x], ch[1][x]);}
}

int rt[N + 5], lnk[N + 5];
void dfs2(int x) {
	rt[x] = 0;
	for(auto to : G[x]) {
		if( dfn[to] > dfn[x] )
			dfs2(to), rt[x] = heap::merge(rt[x], rt[to]);
		else rt[x] = heap::merge(rt[x], heap::newnode(to));
	}
	
	while( rt[x] && dfn[heap::key[rt[x]]] >= dfn[x] )
		heap::erase(rt[x]);
	if( rt[x] && !heap::ch[0][rt[x]] && !heap::ch[1][rt[x]] ) {
		lnk[x] = heap::key[rt[x]];
	} else lnk[x] = -1;
}

bool vis[N + 5];
void dfs3(int x) {
	if( lnk[x] != -1 ) vis[x] = vis[lnk[x]];
	for(auto to : G[x]) if( dfn[to] > dfn[x] ) dfs3(to);
}
void solve2(int root) {
	heap::ncnt = 0, dfs2(root);
	for(int i=1;i<=n;i++) vis[i] = false;
	vis[root] = true; dfs3(root);
	
	std::vector<int>ans;
	for(int i=1;i<=n;i++) if( vis[i] )
		ans.push_back(i);
	
	if( (int)ans.size() * 5 >= n ) {
		for(auto x : ans) printf("%d ", x);
		puts("");
	} else puts("-1");
}

std::mt19937 gen(20041112);
void solve() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1,u,v;i<=m;i++) scanf("%d%d", &u, &v), adde(u, v);
	
	std::uniform_int_distribution<int> func(1, n);
	for(int i=1;i<=40;i++) {
		int x = func(gen);
		if( check(x) ) {solve2(x); return ;}
	}
	puts("-1");
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}