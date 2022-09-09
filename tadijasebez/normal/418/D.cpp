#include <bits/stdc++.h>
using namespace std;
#define pb push_back
void ckmx(int &x,int y){x=max(x,y);}
const int N=100050;
const int L=17;
const int M=2*N;
int root,ls[M],rs[M],tsz,mx[M],lzy[M];
void Build(int &c,int ss,int se,int a[]){
	c=++tsz;lzy[c]=0;
	if(ss==se){mx[c]=a[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid,a);
	Build(rs[c],mid+1,se,a);
	mx[c]=max(mx[ls[c]],mx[rs[c]]);
}
void Add(int c,int ss,int se,int qs,int qe,int f){
	if(qs>qe || qs>se || ss>qe)return;
	if(qs<=ss && qe>=se){lzy[c]+=f;mx[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
}
int Get(int c,int ss,int se,int qs,int qe){
	if(qs>qe || qs>se || ss>qe)return -1e9;
	if(qs<=ss && qe>=se)return mx[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe))+lzy[c];
}
vector<int> E[N];
int dep[N],par[N][L],lid[N],rid[N],tid,h[N],ans[N];
void DFS(int u,int p){
	par[u][0]=p;
	dep[u]=dep[p]+1;
	lid[u]=++tid;
	h[lid[u]]=dep[u];
	for(int i=1;i<L;i++)par[u][i]=par[par[u][i-1]][i-1];
	for(int v:E[u])if(v!=p)DFS(v,u);
	rid[u]=tid;
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=L-1;~i;i--)if(dep[par[u][i]]>=dep[v])u=par[u][i];
	for(int i=L-1;~i;i--)if(par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
int Dist(int u,int v){return dep[u]+dep[v]-2*dep[LCA(u,v)];}
int Up(int u,int k){for(int i=0;i<L;i++)if(k>>i&1)u=par[u][i];return u;}
struct Query{int id,l,r;};
vector<Query> Qs[N];
void Solve(int u,int p){
	Add(root,1,tid,lid[u],rid[u],-2);
	for(Query Q:Qs[u])ckmx(ans[Q.id],Get(root,1,tid,Q.l,Q.r)+dep[u]);
	for(int v:E[u])if(v!=p)Solve(v,u);
	Add(root,1,tid,lid[u],rid[u],2);
}
int main(){
	int n,m;
	scanf("%i",&n);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	Build(root,1,n,h);
	scanf("%i",&m);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%i %i",&u,&v);
		if(dep[u]<dep[v])swap(u,v);
		int w=Up(u,(Dist(u,v)-1)/2);
		Qs[u].pb((Query){i,lid[w],rid[w]});
		Qs[v].pb((Query){i,1,lid[w]-1});
		Qs[v].pb((Query){i,rid[w]+1,n});
	}
	Solve(1,0);
	for(int i=1;i<=m;i++)printf("%i\n",ans[i]);
	return 0;
}