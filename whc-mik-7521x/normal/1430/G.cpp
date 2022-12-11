#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
struct edge{
    long long w,to,nex;
};
edge ed[N<<1];
long long cnt=1,h[N];
void add(long long st,long long et,long long wi){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].w=wi;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
long long dfn[N],s,t;
bool bfs(){
    memset(dfn,0,sizeof dfn);
    queue<long long>q;
    q.push(s);
    dfn[s]=1;
    while(q.size()){
        long long u=q.front();
        q.pop();
        for(long long i=h[u];i;i=ed[i].nex){
            long long v=ed[i].to;
            if(ed[i].w&&!dfn[v]){q.push(v),dfn[v]=dfn[u]+1;if(v==t)return 1;}
        }
    }
    return 0;
}
long long dinic(long long u,long long flow){
    if(u==t)return flow;
    long long rest=flow;
    for(long long i=h[u];i&&rest;i=ed[i].nex){
        long long v=ed[i].to;
        if(ed[i].w&&dfn[v]==dfn[u]+1){
            long long k=dinic(v,min(ed[i].w,rest));
            if(!k)dfn[v]=0;
            ed[i].w-=k;
            ed[i^1].w+=k;
            rest-=k;
        }
    }
    return flow-rest;
}
void ad(long long x,long long y,long long w){
    add(x,y,w);
    add(y,x,0);
}
struct node{
    long long x,y,w;
}a[N];
long long n,m,val[N],res[N];
long long num(long long x,long long step){
    return step*n+x+2;
}
int main(){
    s=1,t=2;
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=m;i++){
        scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].w);
        val[a[i].x]+=a[i].w;
        val[a[i].y]-=a[i].w;
    }
    for(long long i=1;i<=n;i++){
        for(long long o=1;o<=n;o++){
            ad(num(i,o),num(i,o+1),val[i]*o+1e9);
        }
    }
    for(long long i=1;i<=n;i++){
        ad(s,num(i,1),1e18);
        ad(num(i,n+1),t,1e18);
    }
    for(long long i=1;i<=m;i++){
        for(long long o=1;o<=n;o++){
            ad(num(a[i].y,o),num(a[i].x,o+1),1e18);
        }
    }
    long long ans=0;
    while(bfs())ans+=dinic(s,1e18);
    for(long long i=1;i<=n;i++){
        for(long long o=1;o<=n;o++){
            if(dfn[num(i,o)]&&!dfn[num(i,o+1)])res[i]=o;
        }
    }
    for(long long i=1;i<=n;i++)printf("%lld ",res[i]);
    return  0;
}