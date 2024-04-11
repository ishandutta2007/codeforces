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
const int maxn = 1e5 + 5;
const int logn = 20;

int n, clk = 0, q;
int dep[maxn], tin[maxn], tout[maxn];
int par[maxn][logn];
vector<int> g[maxn];

inline void dfs(int u, int p){
//	printf("u = %d p = %d\n", u, p);
	par[u][0] = p;
	if(~p)
		dep[u] = dep[p] + 1;
	tin[u] = ++clk;
	FOR(i, 0, g[u].size()){
		int v = g[u][i];
		if(v == p)
			continue;
		dfs(v, u);
	}
	tout[u] = clk;
	return;
}

inline bool in(int u, int v){
//	printf("u = %d v = %d [%d %d] [%d %d]\n", u, v, tin[u], tout[u], tin[v], tout[v]);
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

inline int lca(int u, int v){
	if(dep[u] > dep[v])
		swap(u, v);
	for(int i = logn - 1; i >= 0; --i) if((dep[v] - dep[u]) >> i & 1){
		v = par[v][i];
	}
//	printf("u = %d v = %d\n", u, v);
	if(u == v)
		return u;
	for(int i = logn - 1; i >= 0; --i){
//		printf("i = %d %d %d\n", i, par[u][i], par[v][i]);
		if(par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}

inline int dis(int u, int v){
	int r = lca(u, v);
	return dep[u] + dep[v] - 2 * dep[r];
}

inline void getroot(int a, int b, int r, int x, int &rx){
	int ra, rb;
//	printf("r = %d\n", r);
	if(!in(r, x)){
		ra = r;
		rb = r;
	}
	else{
		if(in(r, x) && in(x, a))
			ra = x;
		else{
			ra = a;
			if(!in(ra, x)){
				for(int i = logn - 1; i >= 0; --i) if(~par[ra][i] && dep[par[ra][i]] >= dep[r]){
					if(!in(par[ra][i], x))
						ra = par[ra][i];
				}
				ra = par[ra][0];
				if(!in(ra, x))
					ra = r;
			}
		}
		if(in(r, x) && in(x, b))
			rb = x;
		else{
			rb = b;
			if(!in(rb, x)){
				for(int i = logn - 1; i >= 0; --i) if(~par[rb][i] && dep[par[rb][i]] >= dep[r]){
					if(!in(par[rb][i], x))
						rb = par[rb][i];
				}
				rb = par[rb][0];
				if(!in(rb, x))
					rb = r;
			}
		}
	}
//	printf("ra = %d rb = %d\n", ra, rb);
	rx = (dep[ra] > dep[rb] ? ra : rb);
	return;
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
	dfs(0, -1);
	FOR(i, 1, logn) FOR(u, 0, n){
		if(!~par[u][i - 1])
			par[u][i] = -1;
		else
			par[u][i] = par[par[u][i - 1]][i - 1];
	}
	scanf("%d", &q);
	FOR(i, 0, q){
		int a, b, x, y, k;
		scanf("%d%d%d%d%d", &a, &b, &x, &y, &k);
		--a; --b; --x; --y;
		int r = lca(a, b);
		int rx, ry;
		getroot(a, b, r, x, rx);
		getroot(a, b, r, y, ry);
		int cir = dep[a] + dep[b] - dep[r] * 2 + 1;
//		printf("x = %d y = %d rx = %d ry = %d\n", x, y, rx, ry);
		if(rx == ry){
			int res = dis(x, y);
			bool ans = 0;
			ans |= (res <= k && (k & 1) == (res & 1));
			ans |= (dis(x, rx) + dis(y, ry) + cir <= k && (dis(x, rx) + dis(y, ry) + cir & 1) == (k & 1));
			if(ans)
				puts("YES");
			else
				puts("NO");
		}
		else{
			int res = dis(x, rx) + dis(y, ry);
			int len = dis(rx, ry);
//			printf("res = %d cir = %d len = %d\n", res, cir, len);
			bool ans = 0;
			ans |= (res + len <= k && (res + len & 1) == (k & 1));
			ans |= (res + (cir - len) <= k && (res + cir - len & 1) == (k & 1));
			if(ans)
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}