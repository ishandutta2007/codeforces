#include "bits/stdc++.h"
#define pb push_back 

using namespace std;

const int N = 200005;
int n,m,k,R[N<<1],len;
bool vis[N];
vector<int> e[N];

void dfs (int x){
	R[++len] = x; vis[x] = true;
	for (int i = 0, v; i < e[x].size(); i ++){
		if (!vis[v = e[x][i]]) {
			dfs(v); 
			R[++len] = x;
		}
	}
}

int main(){
	cin >> n >> m >> k; int u, v;
	for (int i = 1; i <= m; i ++){
		scanf ("%d%d", &u, &v);
		e[u].pb(v), e[v].pb(u);
	}
	dfs (1);
	int lim = ceil(2.0*n/k);
	for (int i = 1; i <= k; i ++){
		int l = (i-1)*lim+1, r = min(i*lim, len);
		l = min(l, r);
		printf ("%d ", r-l+1);
		for (int i = l; i <= r; i ++)
			printf ("%d%c", R[i], " \n"[i==r]);
	}
	return 0;
}