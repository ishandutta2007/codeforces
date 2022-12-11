#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,inf=1e9;
int n,m,g[N],c[N],d[N],w[N],r,b;
struct edge{
    int w,to,nex;
};
edge ed[N<<1];
int cnt=1,h[N];
void add(int st,int et,int wi){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].w=wi;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
void Add(int st,int et,int w){
    add(st,et,w);
    add(et,st,0);  
}
int dfn[N],s,t;
bool bfs(){
    for(int i=1;i<=n+m+4;i++)dfn[i]=0;
    queue<int>q;
    q.push(s);
    dfn[s]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=h[u];i;i=ed[i].nex){
            int v=ed[i].to;
            if(ed[i].w&&!dfn[v]){q.push(v);dfn[v]=dfn[u]+1;if(v==t)return 1;}
        }
    }
    return 0;
}
int dinic(int u,int flow){
    if(u==t)return flow;
    int rest=flow,i;
    for(i=h[u];i&&rest;i=ed[i].nex){
        int v=ed[i].to;
        if(ed[i].w&&dfn[v]==dfn[u]+1){
            int k=dinic(v,min(ed[i].w,rest));
            if(!k)dfn[v]=0;
            ed[i].w-=k;
            ed[i^1].w+=k;
            rest-=k;
        }
    }
    return flow-rest;
}
vector<int>cx,cy;
vector<pair<int,int>>vec;
int visx[N],visy[N],ctx[N],cty[N],pd,pdd[N];
map<pair<int,int>,int>mp;
int main(){
    scanf("%d%d%d%d",&n,&m,&r,&b);
    if(r<b)swap(r,b),pd=1;
    vec.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&vec[i].first,&vec[i].second);
        cx.push_back(vec[i].first);
        cy.push_back(vec[i].second);
    }
    stable_sort(cx.begin(),cx.end());
    stable_sort(cy.begin(),cy.end());
    cx.erase(unique(cx.begin(),cx.end()),cx.end());
    cy.erase(unique(cy.begin(),cy.end()),cy.end());
    int s1=1,s2=2,t1=3,t2=4;
    for(auto &[x,y]:vec){
        x=lower_bound(cx.begin(),cx.end(),x)-cx.begin()+1;
        y=lower_bound(cy.begin(),cy.end(),y)-cy.begin()+1;
        ctx[x]++;
        cty[y]++;
    }
    for(int i=0;i<n;i++)mp[vec[i]]=i;
    for(int i=1;i<=n;i++)visx[i]=visy[i]=1e9;
    for(int i=1;i<=m;i++){
        int tp,x,d;
        scanf("%d%d%d",&tp,&x,&d);
        if(tp==1){
            auto it=lower_bound(cx.begin(),cx.end(),x);
            if(it!=cx.end()&&*it==x){
                visx[it-cx.begin()+1]=min(visx[it-cx.begin()+1],d);
            }
        }
        else{
            auto it=lower_bound(cy.begin(),cy.end(),x);
            if(it!=cy.end()&&*it==x){
                visy[it-cy.begin()+1]=min(visy[it-cy.begin()+1],d);
            }
        }
    }
    for(int i=1;i<=(int)cx.size();i++){
        int fl=max((ctx[i]-visx[i]+1)/2,0),cl=(ctx[i]+visx[i])/2;
        if(fl>cl)return puts("-1"),0;
        w[s1]-=fl;
        w[i+4]+=fl;
        Add(s1,i+4,cl-fl);
    }
    for(int i=1;i<=(int)cy.size();i++){
        int fl=max((cty[i]-visy[i]+1)/2,0),cl=(cty[i]+visy[i])/2;
        if(fl>cl)return puts("-1"),0;
        w[i+4+n]-=fl;
        w[t1]+=fl;
        Add(i+4+n,t1,cl-fl);
    }
    int kpp=0;
    for(auto [x,y]:vec){
        Add(x+4,y+4+n,1);
        pdd[kpp++]=cnt-1;
    }
    long long tot=0;
    for(int i=1;i<=(int)cx.size();i++){
        if(w[i+4]>0)Add(s2,i+4,w[i+4]),tot+=w[i+4];
        else Add(i+4,t2,-w[i+4]);
    }
    for(int i=1;i<=(int)cy.size();i++){
        if(w[i+4+n]>0)Add(s2,i+4+n,w[i+4+n]),tot+=w[i+4+n];
        else Add(i+4+n,t2,-w[i+4+n]);
    }
    if(w[s1]>0)Add(s2,s1,w[s1]),tot+=w[s1];     
    else Add(s1,t2,-w[s1]);
    if(w[t1]>0)Add(s2,t1,w[t1]),tot+=w[t1];
    else Add(t1,t2,-w[t1]);
    Add(t1,s1,1e9);
    long long res=0,ans=0;
    s=s2,t=t2;
    while(bfs())res+=dinic(s,1e9);
    if(res!=tot)return puts("-1"),0;
    s=s1,t=t1;
    while(bfs())ans+=dinic(s,1e9);
    printf("%lld\n",1ll*r*n-1ll*ans*(r-b));
    for(int i=0;i<n;i++){
        putchar(ed[pdd[i]].w^pd?'r':'b');
    }
    return  0;
}