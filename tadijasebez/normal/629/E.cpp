#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ldb double
const int N=100050;
const int L=17;
ll sz[N],up[N],dw[N],all[N];
int dep[N],par[N][L],n;
vector<int> E[N];
void DFS1(int u,int p){
	par[u][0]=p;
	dep[u]=dep[p]+1;
	for(int i=1;i<L;i++)par[u][i]=par[par[u][i-1]][i-1];
	sz[u]=1;dw[u]=1;
	for(int v:E[u])
		if(v!=p)
			DFS1(v,u),
			sz[u]+=sz[v],
			dw[u]+=dw[v]+sz[v];
}
void DFS2(int u,int p){
	if(!p)up[u]=0,all[u]=dw[u];
	else up[u]=all[p]-dw[u]-sz[u];
	all[u]=dw[u]+up[u]+n-sz[u];
	for(int v:E[u])if(v!=p)DFS2(v,u);
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=L-1;~i;i--)if(dep[par[u][i]]>=dep[v])u=par[u][i];
	for(int i=L-1;~i;i--)if(par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
int Dist(int u,int v){return dep[u]+dep[v]-2*dep[LCA(u,v)];}
int Kth(int u,int k){for(int i=0;i<L;i++)if(k>>i&1)u=par[u][i];return u;}
int main(){
	int m;
	scanf("%i %i",&n,&m);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS1(1,0);
	DFS2(1,0);
	for(int i=1,u,v;i<=m;i++){
		scanf("%i %i",&u,&v);
		int lca=LCA(u,v);
		ldb ans;
		if(lca!=u && lca!=v){
			ans=(ldb)(dw[u]*sz[v]+dw[v]*sz[u])/(sz[u]*sz[v])+Dist(u,v)-1;
		}else{
			if(v==lca)swap(u,v);
			int w=Kth(v,dep[v]-dep[lca]-1);
			ans=(ldb)(dw[v]*(n-sz[w])+up[w]*sz[v])/((n-sz[w])*sz[v])+Dist(u,v)-1;
		}
		printf("%.12f\n",ans);
	}
	return 0;
}