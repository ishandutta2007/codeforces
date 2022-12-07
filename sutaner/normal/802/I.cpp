#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define pb push_back
#define maxn 200020
#define maxsig 26
#define ll long long int  
using namespace std;

int mxl[maxn], go[maxn][maxsig], par[maxn], siz[maxn], last = 1, ct = 1;
void extend(int ch) {
	int p = last, np = last = ++ct; mxl[np] = mxl[p] + 1, siz[np] = 1;
	while (p && !go[p][ch]) go[p][ch] = np, p = par[p];
	if (p) {
		int q = go[p][ch];
		if (mxl[q] == mxl[p] + 1) par[np] = q;
		else {
			int nq = ++ct;
			par[nq] = par[q], par[q] = par[np] = nq, mxl[nq] = mxl[p] + 1;
			srep(i, 0, maxsig) go[nq][i] = go[q][i];
			while (p && go[p][ch] == q) go[p][ch] = nq, p = par[p];
		}
	}else par[np] = 1;
}
vector<int> g[maxn];
void dfs(int x){
	int si = g[x].size();
	srep(i, 0, si) { int op = g[x][i]; dfs(op); siz[x] += siz[op]; }
}
void update_parent_tree(){
	rep(i, 1, ct) g[par[i]].pb(i); dfs(1);
} 

char s[maxn]; int n;

int main(){
	int T; scanf("%d", &T);
	while (T--){
		ll res = 0; scanf("%s", s + 1); n = strlen(s + 1);
		rep(i, 1, n) extend(s[i] - 'a'); update_parent_tree();
		rep(i, 1, ct) res += 1ll * siz[i] * siz[i] * (mxl[i] - mxl[par[i]]);
		printf("%lld\n", res);
		rep(i, 0, ct) rep(j, 0, 25) go[i][j] = 0;
		rep(i, 0, ct) siz[i] = par[i] = mxl[i] = 0;
		rep(i, 0, ct) g[i].clear();
		last = ct = 1;
	} 
	return 0;
}