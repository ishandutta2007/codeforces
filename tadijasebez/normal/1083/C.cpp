//svaki klub me dobro zna
//svaka noc je pijana
//nije me promenila
//zato je i otisla
//sve do zadnje pare
//na provod sam trosio
//sipaj opet duplo care
//jer bez nje sam ostao
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
int ri(){int x;scanf("%i",&x);return x;}
const int N=400050;
const int L=20;
pii rmq[L][N];
vector<int> E[N];
int dep[N],tid,fai[N],lgs[N],p[N];
void DFS(int u,int p){
    dep[u]=dep[p]+1;
    rmq[0][++tid]={dep[u],u};
    fai[u]=tid;
    for(int v:E[u]){
        DFS(v,u);
        rmq[0][++tid]={dep[u],u};
    }
}
int LCA(int u,int v){
    u=fai[u],v=fai[v];
    if(u>v)swap(u,v);
    int k=lgs[v-u+1];
    return min(rmq[k][u],rmq[k][v-(1<<k)+1]).se;
}
int dist(int u,int v){return dep[u]+dep[v]-2*dep[LCA(u,v)];}
pii mrg(pii a,int b){
    if(b==0)return a;
    if(a.fi==-1 || b==-1)return {-1,-1};
    static vector<pair<int,pii>> v(3);
    v[0]={dist(a.fi,a.se),{a.fi,a.se}};
    v[1]={dist(a.fi,b),{a.fi,b}};
    v[2]={dist(a.se,b),{a.se,b}};
    sort(v.begin(),v.end());
    if(v[0].fi+v[1].fi==v[2].fi)
        return v[2].se;
    else return {-1,-1};
}
pii mrg(pii a,pii b){return mrg(mrg(a,b.fi),b.se);}
int ls[N],rs[N],root,tsz,n;
pii node[N];
void Build(int &c,int ss,int se){
    c=++tsz;if(ss==se)return;
    int mid=ss+se>>1;
    Build(ls[c],ss,mid);
    Build(rs[c],mid+1,se);
}
void Set(int c,int ss,int se,int qi,pii x){
    if(ss==se){node[c]=x;return;}
    int mid=ss+se>>1;
    if(qi<=mid)Set(ls[c],ss,mid,qi,x);
    else Set(rs[c],mid+1,se,qi,x);
    node[c]=mrg(node[ls[c]],node[rs[c]]);
    //printf("(%i %i) %i - %i\n",ss,se,node[c].fi,node[c].se);
}
int Get(int c,int ss,int se,pii k){
    if(~mrg(node[c],k).fi)return se;
    if(ss==se)return ss-1;
    int mid=ss+se>>1;
    if(~mrg(node[ls[c]],k).fi)return Get(rs[c],mid+1,se,mrg(node[ls[c]],k));
    else return Get(ls[c],ss,mid,k);
}
int main(){
    int n=ri();
    for(int i=1;i<=n;i++)p[i]=ri()+1;
    for(int i=2;i<=n;i++)E[ri()].pb(i);
    DFS(1,0);
    for(int j=1;j<L;j++)
        for(int i=1;i<=tid-(1<<j)+1;++i)
            rmq[j][i]=min(rmq[j-1][i],rmq[j-1][i+(1<<j-1)]);
    for(int i=2;i<=tid;i++)lgs[i]=lgs[i>>1]+1;
    Build(root,1,n);
    for(int i=1;i<=n;i++)Set(root,1,n,p[i],{i,i});
    int q=ri();
    while(q--){
        int t=ri();
        if(t==1){
            int i=ri(),j=ri();
            Set(root,1,n,p[i],{j,j});
            Set(root,1,n,p[j],{i,i});
            swap(p[i],p[j]);
        }else printf("%i\n",Get(root,1,n,{0,0}));
    }
    return 0;
}