#include <bits/stdc++.h>
using namespace std;

const int N = 2111111;
const int M = N * 2;

int fir[N] , ne[M] , to[M] , cnt , scc[N] , S[N] , col , dfs_clock , u[N][2] , C[N] , dfn[N] , low[N] , x , y;

void add(int x , int y) {
	ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y;
}

void link(int x , int y) {
	add(x , y); add(y , x);
}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

int stk[N] , top , n , m , h;

vector <int> G[N];

void dfs(int x) {
	dfn[x] = low[x] = ++ dfs_clock;
	int now = top;
	stk[++ top] = x;
	Foreachson(i , x) {
		int V = to[i];
		if(scc[V]) continue;
		if(!dfn[V]) dfs(V);
		low[x] = min(low[x] , low[V]); 
	}
	if(low[x] != dfn[x]) return;
	++ col;
	while(top > now) {
		scc[stk[top]] = col;
		G[col].push_back(stk[top]);
		-- top; ++ S[col];
	}
}

vector <int> E[M];

void init(void) {
	for(int i = 1;i <= n;++ i) {
		Foreachson(j , i) {
			int V = to[j];
			if(scc[V] != scc[i]) {
				E[scc[i]].push_back(scc[V]);
			}
		}
	}
}

main(void) {
	scanf("%d%d%d" , &n , &m , &h);
	for(int i = 1;i <= n; ++ i) scanf("%d" , &C[i]);
	for(int i = 1;i <= m;++ i) {
		scanf("%d%d" , &x , &y);
		if((C[y] + 1) % h == C[x]) {
			add(y , x);
		}
		if((C[x] + 1) % h == C[y]) {
			add(x , y);
		}
	}
	for(int i = 1;i <= n;++ i) if(!dfn[i]) dfs(i);
	init();
	int ans = 0;
	for(int i = 1;i <= col;++ i) if(!E[i].size()){
		if(!ans) ans = i;
		else if(G[i].size() < G[ans].size()) {
			ans = i;
		}
	}
	cout << G[ans].size() << endl;
	for(auto V : G[ans]) cout << V <<" ";
}