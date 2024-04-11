#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int P = 998244353;
const int INF = 1e9;
const int N = 2e5+5;
const double pi = acos(-1);
mt19937 rng(time(0));

int T, n, m, k, dti=0, x, y;
int a[N], ds[N], dep[N];
ar2 dt[19][N<<1];
vector<int> g[N];

void dfs(int u, int fa, int d){
	dep[u] = d;
	ds[u]=++dti;
	dt[0][dti]={d,u};
	for(int v:g[u]) if (v!=fa)
		dfs(v, u, d+1), dt[0][++dti]={d,u};
}

int lca(int u, int v) {
	if((u=ds[u])>(v=ds[v])) swap(u, v);
	int k=31-__builtin_clz(v-u+1);
	return min(dt[k][u], dt[k][v-(1<<k)+1])[1];
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%d%d",&n,&m);
	rep(i,2,n) scanf("%d%d",&x,&y),g[x].PB(y),g[y].PB(x);
	dfs(1, 0, 1);
	rep(i,1,18) rep(j,1,2*n-(1<<i))
		dt[i][j]=min(dt[i-1][j], dt[i-1][j+(1<<i-1)]);
	
	while(m--){
		scanf("%d",&k);
		int maxi = 1;
		rep(i,1,k){
			scanf("%d",a+i);
			if(dep[a[i]]>dep[a[maxi]]) maxi = i;
		}
		bool flag = true;
		rep(i,1,k){
			int u = a[maxi], v = a[i];
			if(dep[lca(u,v)]+1 < dep[v]){
				flag = false; break;
			}
		}
		printf(flag?"YES\n":"NO\n");
	}
	return 0;
}