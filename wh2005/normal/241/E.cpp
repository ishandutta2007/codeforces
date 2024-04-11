#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define ri int
#define ll long long
#define pii pair<int,int>
const ll mod=1e9+7;
ll add(ll x,ll y){return (x+=y)<mod?x:x-mod;}
ll dec(ll x,ll y){return (x-=y)<0?x+mod:x;}
const int MAXN=1e3+7,MAXM=5e3+7;
int n,m,visa[MAXN],visb[MAXN],dis[MAXN],mark[MAXN],cnt[MAXN];
vector<int> g[MAXN],rg[MAXN];
pii e[MAXM];
void dfsa(int u){
    if(visa[u]) return;
    visa[u]=1;
    for(auto v:g[u]) dfsa(v);
}
void dfsb(int u){
    if(visb[u]) return;
    visb[u]=1;
    for(auto v:rg[u]) dfsb(v);
}
vector<pii> to[MAXN];
void SPFA(){
    queue<int> q;
    memset(dis,0x3f,sizeof(dis));
    q.push(1),dis[1]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        mark[u]=0;
        for(auto x:to[u]){
            int v=x.first;
            if(dis[v]>dis[u]+x.second){
                dis[v]=dis[u]+x.second;
                if(++cnt[v]>n){
                    puts("No");
                    exit(0);
                }
                if(!mark[v]) q.push(v),mark[v]=1;
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(ri i=1;i<=m;++i){
        int u,v;scanf("%d%d",&u,&v);
        g[u].push_back(v),rg[v].push_back(u);
        e[i]=(pii){u,v};
    }
    dfsa(1),dfsb(n);
    for(ri i=1;i<=m;++i){
        int u=e[i].first,v=e[i].second;
        if(!visa[u]||!visb[u]||!visa[v]||!visb[v]) continue;
        to[u].push_back((pii){v,+2});
        to[v].push_back((pii){u,-1});
    }
    SPFA();
    puts("Yes");
    for(ri i=1;i<=m;++i){
        int u=e[i].first,v=e[i].second;
        if(!visa[u]||!visb[u]||!visa[v]||!visb[v]) printf("%d\n",1);
        else printf("%d\n",dis[v]-dis[u]);
    }
}