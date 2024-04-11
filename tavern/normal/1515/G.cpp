#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (int)(x); i < (int)(y); ++i)
#define REP(i, x, y) for(int i = (int)(x); i <= (int)(y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
#define y0 y2226700
#define y1 y2226701
#define y2 y2226702
typedef double lf;
typedef long double Lf;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 2e5 + 5;

int n, m, q;
int col[maxn];
ll ans[maxn], dep[maxn];
vector<pii> g[maxn];

namespace Tarjan{
	int clk, top, tot;
	int low[maxn], dfn[maxn], ins[maxn], stk[maxn];
	
	inline void dfs(int u){
		low[u] = dfn[u] = clk++;
		stk[++top] = u, ins[u] = true;
		
		FOR(i, 0, g[u].size()){
			int v = g[u][i].fst, w = g[u][i].snd;
			//printf("u = %d v = %d w = %d\n", u, v, w);
			if(!~dfn[v]){
				dep[v] = dep[u] + w;
				dfs(v);
				low[u] = min(low[u], low[v]);
			}
			else if(ins[v])
				low[u] = min(low[u], dfn[v]);
		}
		
		if(low[u] >= dfn[u]){
			//printf("u = %d low = %d dfn = %d\n", u, low[u], dfn[u]);
			for(int v = stk[top]; v != u; v = stk[--top])
				col[v] = tot, ins[v] = false;
			col[u] = tot, ins[u] = false;
			--top, ++tot;
		}
		
		return;
	}
	
	inline void work(){
		memset(dfn, -1, sizeof(dfn));
		clk = top = tot = 0;
		FOR(i, 0, n) if(!~dfn[i])
			dfs(i);
		return;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	
	FOR(i, 0, m){
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		--u, --v;
		g[u].PB(MP(v, w));
	}
	
	Tarjan::work();
	
/*	FOR(u, 0, n)
		printf("%d ", dep[u]); puts("");
	FOR(u, 0, n)
		printf("%d ", col[u]); puts("");
*/	
	FOR(u, 0, n){
		FOR(i, 0, g[u].size()){
			int v = g[u][i].fst, w = g[u][i].snd;
			if(col[u] != col[v])
				continue;
			ans[col[u]] = __gcd(ans[col[u]], w + dep[u] - dep[v]);
		}
	}
	
	scanf("%d", &q);
	FOR(i, 0, q){
		int u, s, t; scanf("%d%d%d", &u, &s, &t); --u;
		//printf("ans = %d\n", ans[col[u]]);
		puts(((t - s) % __gcd(ans[col[u]], 1ll * t) == 0) ? "YES" : "NO");
	}
	return 0;
}