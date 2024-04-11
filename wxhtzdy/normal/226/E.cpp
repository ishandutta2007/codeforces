#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int L=20;
vector<int> E[N];
int par[N][L],dep[N];
int lid[N],rid[N],tid;
void DFS(int u,int p){
    lid[u]=++tid;
    par[u][0]=p;
    dep[u]=dep[p]+1;
    for(int i=1;i<L;i++)par[u][i]=par[par[u][i-1]][i-1];
	for(int v:E[u])if(v!=p)DFS(v,u);
	rid[u]=++tid;
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
    for(int i=L-1;~i;i--)if(dep[par[u][i]]>=dep[v])u=par[u][i];
	for(int i=L-1;~i;i--)if(par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
    return u==v?v:par[v][0];
}
int Dist(int u,int v){return dep[u]+dep[v]-2*dep[LCA(u,v)];}
int Lift(int u,int k){for(int i=0;i<L;i++)if(k>>i&1)u=par[u][i];return u;}
int Kth(int u,int v,int k){
    int lca=LCA(u,v);
    if(dep[u]-dep[lca]>=k)return Lift(u,k);
    else return Lift(v,Dist(u,v)-k);
}
const int M=N*20;
int root[N],st[M],ls[M],rs[M],tsz;
void Set(int p,int&c,int ss,int se,int qi,int x){
    c=++tsz;ls[c]=ls[p];rs[c]=rs[p];st[c]=st[p]+x;
    if(ss==se)return;
    int mid=ss+se>>1;
    if(qi<=mid)Set(ls[p],ls[c],ss,mid,qi,x);
    else Set(rs[p],rs[c],mid+1,se,qi,x);
}
int Get(int c,int p,int ss,int se,int qs,int qe){
    if(ss>se||ss>qe||se<qs)return 0;
    if(qs<=ss&&se<=qe)return st[c]-st[p];
    int mid=ss+se>>1;
    return Get(ls[c],ls[p],ss,mid,qs,qe)+Get(rs[c],rs[p],mid+1,se,qs,qe);
}
int Get(int u,int i,int y){return Get(root[i],root[y],1,tid,1,lid[u]);}
int Get(int u,int v,int i,int y){
    int lca=LCA(u,v);
    return Get(u,i,y)+Get(v,i,y)-Get(lca,i,y)-Get(par[lca][0],i,y);
}
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++){
        int p;scanf("%i",&p);
        E[p].push_back(i);
    }
	DFS(0,0);
	int q;scanf("%i",&q);
    for(int i=1;i<=q;i++){
        int t;scanf("%i",&t);
        root[i]=root[i-1];
        if(t==1){
            int c;scanf("%i",&c);
            Set(root[i],root[i],1,tid,lid[c],1);
            Set(root[i],root[i],1,tid,rid[c],-1);
        }else{
            int a,b,k,y;scanf("%i%i%i%i",&a,&b,&k,&y);
            int aa=Get(a,a,i,y);
            int bot=1,top=Dist(a,b)-1,ans=0;
            while(bot<=top){
                int mid=bot+top>>1;
                int u=Kth(a,b,mid);
                if(mid-Get(a,u,i,y)+aa>=k)ans=mid,top=mid-1;
                else bot=mid+1;
            }
            printf("%i\n",(ans==0?-1:Kth(a,b,ans)));
		}
    }
	return 0;
}