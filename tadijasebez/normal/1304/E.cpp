#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int L=17;
vector<int> E[N];
int par[N][L],dep[N];
void DFS(int u,int p){
	par[u][0]=p;
	dep[u]=dep[p]+1;
	for(int i=1;i<L;i++)par[u][i]=par[par[u][i-1]][i-1];
	for(int v:E[u])if(v!=p)DFS(v,u);
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=L-1;~i;i--)if(dep[par[u][i]]>=dep[v])u=par[u][i];
	for(int i=L-1;~i;i--)if(par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
	return v==u?v:par[v][0];
}
int Dist(int u,int v){return dep[u]+dep[v]-2*dep[LCA(u,v)];}
int Solve(int u,int v,int a,int b,int k){
	int mn[2]={(int)1e9+7,(int)1e9+7};
	auto Add=[&](int d){mn[d&1]=min(mn[d&1],d);};
	Add(Dist(u,v));
	Add(Dist(u,a)+1+Dist(b,v));
	Add(Dist(u,b)+1+Dist(a,v));
	if(mn[k&1]<=k)return 1;
	else return 0;
}
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	int q;
	scanf("%i",&q);
	while(q--){
		int u,v,a,b,k;
		scanf("%i %i %i %i %i",&a,&b,&u,&v,&k);
		if(Solve(u,v,a,b,k))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}