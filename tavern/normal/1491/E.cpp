#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define PB push_back
#define MP make_pair
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double Lf;
typedef pair<int, int> pii;

const int maxn = 2e5 + 5;

int n, m;
int sz[maxn], p[maxn], f[105];
set<int> g[maxn];

inline void find(int u, int par, int x, int &w){
	sz[u] = 1;
	p[u] = par;
	for(set<int>::iterator it = g[u].begin(); it != g[u].end(); ++it){
		int v = *it;
		if(v == par)
			continue;
		find(v, u, x, w);
		sz[u] += sz[v];
	}
	if(sz[u] == f[x] || sz[u] == f[x - 1])
		w = u;
	return;
}

inline void solve(int u, int x){
	if(x <= 1)
		return;
	int v = -1;
	find(u, -1, x - 1, v);
	if(!~v){
		puts("NO");
		exit(0);
	}
	int w = p[v];
	g[v].erase(w);
	g[w].erase(v);
	if(sz[v] == f[x - 1]){
		solve(v, x - 1);
		solve(w, x - 2);
	}
	else{
		solve(v, x - 2);
		solve(w, x - 1);
	}
	return;
}

int main(){
	scanf("%d", &n);
	FOR(i, 1, n){
		int u, v; scanf("%d%d", &u, &v);
		--u; --v;
		g[u].insert(v);
		g[v].insert(u);
	}
	
	
	f[0] = f[1] = 1;
	for(m = 2; (f[m] = f[m - 1] + f[m - 2]) <= n; ++m);
	--m;
	
	if(f[m] != n){
		puts("NO");
		return 0;
	}
	solve(0, m);
	puts("YES");
	return 0;
}