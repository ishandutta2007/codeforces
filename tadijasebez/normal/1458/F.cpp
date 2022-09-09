#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=200050;
const int L=20;
vector<int> E[N],G[N];
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
    return u==v?v:par[v][0];
}
int Dist(int u,int v){return dep[u]+dep[v]-2*dep[LCA(u,v)];}
int Lift(int u,int k){for(int i=0;i<L;i++)if(k>>i&1)u=par[u][i];return u;}
int Kth(int u,int v,int k){
    int lca=LCA(u,v);
    if(dep[u]-dep[lca]>=k)return Lift(u,k);
    else return Lift(v,Dist(u,v)-k);
}
bool was[N];
int sz[N],root;
void DFSSZ(int u,int p){sz[u]=1;for(int v:E[u])if(!was[v]&&v!=p)DFSSZ(v,u),sz[u]+=sz[v];}
int Find(int u,int p,int n){for(int v:E[u])if(!was[v]&&v!=p&&sz[v]*2>=n)return Find(v,u,n);return u;}
int Find(int u){DFSSZ(u,u);return Find(u,u,sz[u]);}
int dst[N][L],go[N][L],lvl[N];
void Build(int u,int p,int l,int i){
    go[u][l]=i;
    dst[u][l]=dst[p][l]+1;
    for(int v:E[u])if(!was[v]&&v!=p)Build(v,u,l,i);
}
ll all_sum[N],all_cnt[N];
vector<ll> sub_sum[N],sub_cnt[N];
int Cen(int u,int l){
    u=Find(u);
    was[u]=true;
    lvl[u]=l;
    for(int i=0;i<E[u].size();i++){
        int v=E[u][i];
        if(!was[v]){
            Build(v,u,l,i);
        }
    }
    sub_sum[u].resize(E[u].size());
    sub_cnt[u].resize(E[u].size());
    G[u].resize(E[u].size());
    for(int i=0;i<E[u].size();i++){
        int v=E[u][i];
        if(!was[v]){
            G[u][i]=Cen(v,l+1);
        }
    }
    return u;
}
void Add(int u,int f){
    int cen=root;
    int l=0;
    while(1){
        all_sum[cen]+=f*dst[u][l];
        all_cnt[cen]+=f;
        if(cen!=u){
            sub_sum[cen][go[u][l]]+=f*dst[u][l];
            sub_cnt[cen][go[u][l]]+=f;
        }
        if(cen==u)break;
        cen=G[cen][go[u][l]];
        l++;
    }
}
ll Get(int u){
    int cen=root;
    int l=0;
    ll ans=0;
    while(1){
        ans+=all_sum[cen];
        if(cen!=u)ans-=sub_sum[cen][go[u][l]];
        ans+=dst[u][l]*all_cnt[cen];
        if(cen!=u)ans-=dst[u][l]*sub_cnt[cen][go[u][l]];
        if(cen==u)break;
        cen=G[cen][go[u][l]];
        l++;
    }
    return ans;
}
int o[N],r[N];
ll sum[N];
ll Solve(int l,int r){
    if(l==r)return 0;
    int mid=l+r>>1;
    o[mid+1]=mid+1;
    ::r[mid+1]=0;
    sum[mid]=0;
    sum[mid+1]=0;
    for(int i=mid+2;i<=r;i++){
        int d=Dist(o[i-1],i);
        if(d>::r[i-1]){
            ::r[i]=(d+::r[i-1])/2;
            o[i]=Kth(o[i-1],i,(d-::r[i-1])/2);
        }else{
            o[i]=o[i-1];
            ::r[i]=::r[i-1];
        }
        sum[i]=sum[i-1]+::r[i];
    }
    ll ans=0;
    int O=mid,R=0;
    int ptl=mid,ptr=mid+1;
    for(int i=mid;i>=l;i--){
        int d=Dist(O,i);
        if(d>R){
            O=Kth(O,i,(d-R)/2);
            R=(R+d)/2;
        }
        while(ptr<=r&&Dist(O,o[ptr])+R>::r[ptr])Add(o[ptr],1),ptr++;
        while(ptl<r&&Dist(O,o[ptl+1])+::r[ptl+1]<R)ptl++,Add(o[ptl],-1);
        ans+=(ll)R*(ptl-mid);
        ans+=sum[r]-sum[ptr-1];
        ans+=((ll)R*(ptr-ptl-1)+sum[ptr-1]-sum[ptl]+Get(O))/2;
    }
    while(ptl+1<ptr)ptl++,Add(o[ptl],-1);
    ans+=Solve(l,mid);
    ans+=Solve(mid+1,r);
    return ans;
}
int main(){
    int n;
    scanf("%i",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%i %i",&u,&v);
        E[u].pb(i+n);
        E[i+n].pb(u);
        E[v].pb(i+n);
        E[i+n].pb(v);
    }
    DFS(1,0);
    root=Cen(1,0);
    printf("%lld\n",Solve(1,n));
    return 0;
}