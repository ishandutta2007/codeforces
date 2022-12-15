#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back
#define int long long
#define pii pll

const int MN = 1e4+4;
int N, M, L, S, T, i, x, y, w, dist[MN][2], vis[MN];
struct edge{int x, y, w;}e[MN];
struct pq{bool operator()(const pii&i,const pii&j){return i.second>j.second;}};
priority_queue<pii,vector<pii>,pq> q;
vector<pii> adj[MN];

signed main(){
    scanf("%lld%lld%lld%lld%lld",&N,&M,&L,&S,&T);
    for(i=1;i<=M;i++){
        scanf("%lld%lld%lld",&x,&y,&w);
        e[i] = {x, y, w};
        adj[x].pb({y, i});
        adj[y].pb({x, i});
    }
    memset(dist,-1,sizeof(dist));
    q.push({T,0});
    while(q.size()){
        pii cur = q.top(); q.pop();
        if(dist[cur.first][1]!=-1) continue;
        dist[cur.first][1] = cur.second;
        for(auto v : adj[cur.first]){
            if(e[v.second].w) q.push({v.first,cur.second+e[v.second].w});
        }
    }
    q.push({S,0});
    while(q.size()){
        pii cur = q.top(); q.pop();
        if(dist[cur.first][0]!=-1) continue;
        dist[cur.first][0] = cur.second;
        for(auto v : adj[cur.first]){
            if(e[v.second].w==0){
                if(dist[v.first][1]!=-1){
                    w = L-dist[v.first][1]-cur.second;
                    if(w<=0) e[v.second].w = 1;
                    else e[v.second].w = w;
                }
                else e[v.second].w = 1;
            }
            q.push({v.first,cur.second+e[v.second].w});
        }
    }
    if(dist[T][0]!=L) printf("NO\n");
    else{
        printf("YES\n");
        for(i=1;i<=M;i++){
            if(e[i].w==0) e[i].w = L+1;
            printf("%lld %lld %lld\n",e[i].x,e[i].y,e[i].w);
        }
    }
    return 0;
}