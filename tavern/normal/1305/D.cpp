#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int maxn = 1e3 + 5;

int n;
int vis[maxn], dep[maxn];
vector<int> g[maxn];

inline void dfs(int u, int p, int &l){
	if(~p)
		dep[u] = dep[p] + 1;
	else
		dep[u] = 0;
	if(!~l || dep[u] > dep[l])
		l = u;
	FOR(i, 0, g[u].size()){
		int v = g[u][i];
		if(v == p || vis[v])
			continue;
		dfs(v, u, l);
	}
	return;
}

inline void calc(int u, int p, int l1, int l2){
	if(u == l1 || u == l2){
		vis[u] = 1;
	}
	FOR(i, 0, g[u].size()){
		int v = g[u][i];
		if(v == p || vis[v])
			continue;
		calc(v, u, l1, l2);
		vis[u] |= vis[v];
	}
	return;
}

inline bool check(int u){
	FOR(i, 0, g[u].size()) if(!vis[g[u][i]])
		return false;
	return true;
}

int main(){
	scanf("%d", &n);
	FOR(i, 1, n){
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		g[u].PB(v);
		g[v].PB(u);
	}
	int w = 0;
	while(true){
		int u = -1, v = -1;
		dfs(w, -1, u);
		dfs(u, -1, v);
		printf("? %d %d\n", u + 1, v + 1);
		fflush(stdout);
		scanf("%d", &w);
		--w;
		calc(w, -1, u, v);
		vis[w] = 0;
		if(check(w)){
			printf("! %d\n", w + 1);
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}