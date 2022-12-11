#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
struct edge{
    int to,nxt;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
int dfn[N],en[N],dep[N],fa[N][21],ct;
void dfs(int x,int f){
    fa[x][0]=f;
    dep[x]=dep[f]+1;
    dfn[x]=++ct;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==f)continue;
        dfs(v,x);
    }
    en[x]=ct;
}
struct BIT{
    int ts[N];
    int ask(int x){
        int res=0;
        for(;x;x-=x&-x)res+=ts[x];
        return res;
    }
    void add(int x,int d){
        if(!x)return;
        x=dfn[x];
        for(;x<=n;x+=x&-x)ts[x]+=d;
    }
    int query(int l,int r){
        return ask(r)-ask(l-1);
    }
}tr1[22],tr2[22];
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    int ste=dep[x]-dep[y];
    for(int i=20;i>=0;i--){
        if(ste>=(1<<i))ste-=(1<<i),x=fa[x][i];
    }
    if(x==y)return y;
    for(int i=20;i>=0;i--){
        if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];
} 
void lca_init(){
    for(int o=1;o<=20;o++)
    for(int i=1;i<=n;i++){
        fa[i][o]=fa[fa[i][o-1]][o-1];
    }
}
void upd(int x,int d,int k){
    if(d<0)return;
    if(d)tr2[d-1].add(x,k),tr2[d-1].add(fa[x][0],-k);
    tr1[d].add(fa[x][0],k),tr1[d].add(fa[fa[x][0]][0],-k);
    upd(fa[x][0],d-1,k);
}
void ope(int u,int v,int k,int d){
    int kk=lca(u,v);
    tr1[d].add(u,k);tr1[d].add(v,k);
    tr1[d].add(kk,-k);tr1[d].add(fa[kk][0],-k);
    if(d)tr2[d-1].add(u,k),tr2[d-1].add(v,k),tr2[d-1].add(kk,-2*k);
    upd(kk,d-1,k);
}
int query(int x,int res,int d){
    if(res<0||!x)return 0;
    int ans=0;
    for(int i=d;i<=20;i++)ans+=tr1[i].query(dfn[x],en[x]);
    if(res&&x!=1)for(int i=d;i<=20;i++)ans-=tr2[i].query(dfn[x],en[x]);
    return ans+query(fa[x][0],res-1,d+1);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    lca_init();
    scanf("%d",&m);
    while(m--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            printf("%d\n",query(x,21,0));
        }
        else{
            int u,v,k,d;
            scanf("%d%d%d%d",&u,&v,&k,&d);
            ope(u,v,k,d);
        }
    }
    return 0;
}