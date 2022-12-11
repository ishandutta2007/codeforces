#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct edge{
    int w,to,nex,num;
};
edge ed[N<<1];
int cnt=1,h[N],arcc[N];
void add(int st,int et,int wi,int num){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].w=wi;
    ed[cnt].nex=h[st];
    ed[cnt].num=num;
    h[st]=cnt;
}
int dfn[N],s,t;
bool bfs(){
    memset(dfn,0,sizeof dfn);
    queue<int>q;
    q.push(s);
    dfn[s]=1;
    arcc[s]=h[s];
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=h[u];i;i=ed[i].nex){
            int v=ed[i].to;
            if(ed[i].w&&!dfn[v]){q.push(v);arcc[v]=h[v];dfn[v]=dfn[u]+1;if(v==t)return 1;}
        }
    }
    return 0;
}
int dinic(int u,int flow){
    if(u==t)return flow;
    int rest=flow,i;
    for(i=arcc[u];i&&rest;i=ed[i].nex){
        int v=ed[i].to;
        if(ed[i].w&&dfn[v]==dfn[u]+1){
            int k=dinic(v,min(ed[i].w,rest));
            if(!k)dfn[v]=0;
            ed[i].w-=k;
            ed[i^1].w+=k;
            rest-=k;
        }
    }
    arcc[u]=i;
    return flow-rest;
}
int n1,n2,m,q,ot[N],fx[N],fy[N],val[N],exi[N];
int main(){
    scanf("%d%d%d%d",&n1,&n2,&m,&q);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&fx[i],&fy[i]);
        add(fx[i],fy[i]+n1,1,i);
        add(fy[i]+n1,fx[i],0,i);
    }
    s=n1+n2+1;
    t=n1+n2+2;
    for(int i=1;i<=n1;i++)add(s,i,1,0),add(i,s,0,0);
    for(int i=1;i<=n2;i++)add(i+n1,t,1,0),add(t,i+n1,0,0);
    int ans=0;
    while(bfs())ans+=dinic(s,1e9);
    vector<int>vec;
    for(int i=1;i<=n1;i++){
        for(int o=h[i];o;o=ed[o].nex){
            if(ed[o].to!=s&&ed[o].w==0)val[i]=ed[o].num,exi[ed[o].num]=1;
        }
    }
    for(int i=1;i<=n2;i++){
        for(int o=h[i+n1];o;o=ed[o].nex){
            if(ed[o].to!=t&&ed[o].w==1)val[i+n1]=ed[o].num,exi[ed[o].num]=1;
        }
    }
    for(int i=1;i<=n1;i++){
        if(!dfn[i])vec.push_back(i);
    }
    for(int i=1;i<=n2;i++){
        if(dfn[i+n1])vec.push_back(i+n1);
    }
    long long tot=0;
    for(int i=1;i<=n1;i++)tot+=val[i];
    while(q--){
        int x;
        scanf("%d",&x);
        if(x==1){
            int now=vec.back();
            vec.pop_back();
            int edg=val[now];
            val[fx[edg]]=val[fy[edg]+n1]=0;
            tot-=edg;
            printf("1\n%d\n%lld\n",now>n1?-(now-n1):now,tot);
            ans--;
        }
        else{
            printf("%d\n",ans);
            for(int i=1;i<=n1;i++)if(val[i])printf("%d ",val[i]);
            puts("");
        }
        fflush(stdout);
    }
    return 0;
}