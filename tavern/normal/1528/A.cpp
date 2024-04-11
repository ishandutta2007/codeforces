#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (int)(x); i < (int)(y); ++i)
#define REP(i, x, y) for(int i = (int)(x); i <= (int)(y); ++i)
#define PB push_back
typedef long long ll;

const int maxn = 1e5 + 5;

int n;
int a[maxn][2];
ll f[maxn][2];
vector<int> g[maxn];

inline void dfs(int u, int p){
	f[u][0] = f[u][1] = 0; 
	FOR(i, 0, g[u].size()){
		int v = g[u][i];
		if(v == p)
			continue;
		dfs(v, u);
		FOR(s, 0, 2){
			ll res = 0;
			FOR(t, 0, 2)
				res = max(res, f[v][t] + abs(a[u][s] - a[v][t]));
			f[u][s] += res;
		}
	}
	return;
}

inline void solve(){
	scanf("%d", &n);
	FOR(u, 0, n)
		g[u].clear();
	FOR(i, 0, n)
		scanf("%d%d", &a[i][0], &a[i][1]);
	FOR(i, 1, n){
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		g[u].PB(v), g[v].PB(u);
	}
	dfs(0, -1);
	printf("%lld\n", max(f[0][0], f[0][1]));
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());	
	return 0;
}