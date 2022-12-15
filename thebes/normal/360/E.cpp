#include <bits/stdc++.h>
using namespace std;

const int MN = 1e4+4;
typedef long long ll;
typedef pair<ll,ll> pii;
ll n, m, k, s1, s2, f, x, y, a, w[MN], st[MN], l[MN], r[MN], dif[MN], tot, vis[MN], i;
struct pq{bool operator()(const pii&i,const pii&j){return i.second>j.second;}};
priority_queue<pii,vector<pii>,pq> q;
vector<pii> adj[MN];
vector<ll> edges;
ll solve(){
    ll tot = 0;
    q.push({s1, 0});
    memset(vis, 0, sizeof(vis));
    memset(dif, 0, sizeof(dif));
    while(q.size()){
        auto cur = q.top(); q.pop();
        if(vis[cur.first]) continue;
        else vis[cur.first]=1;
        dif[cur.first]+=cur.second;
        tot += cur.second;
        for(auto v : adj[cur.first]){
            if(vis[v.first]) continue;
            if(v.second<0) q.push({v.first,cur.second-v.second});
            else q.push({v.first,cur.second+w[v.second]});
        }
    }
    for(i=1;i<=n;i++){
        if(!vis[i]) dif[i] += 1LL<<60;
    }
    q.push({s2, 0});
    memset(vis, 0, sizeof(vis));
    while(q.size()){
        auto cur = q.top(); q.pop();
        if(vis[cur.first]) continue;
        else vis[cur.first]=1;
        dif[cur.first]-=cur.second;
        tot -= cur.second;
        for(auto v : adj[cur.first]){
            if(vis[v.first]) continue;
            if(v.second<0) q.push({v.first,cur.second-v.second});
            else q.push({v.first,cur.second+w[v.second]});
        }
    }
    for(i=1;i<=n;i++){
        if(!vis[i]) dif[i]-=1LL<<60;
    }
    return tot;
}
int main(){
    scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&k,&s1,&s2,&f);
    for(i=1;i<=m;i++){
        scanf("%lld%lld%lld",&x,&y,&a);
        adj[x].push_back({y,-a});
    }
    for(i=1;i<=k;i++){
        scanf("%lld%lld%lld%lld",&x,&y,&l[i],&r[i]);
        w[i] = r[i]; st[i] = x;
        adj[x].push_back({y,i});
    }
    solve();
    for(i=1;i<=k;i++) edges.push_back(i);
    while(1){
        bool fnd = 0;
        for(i=0;i<edges.size();i++){
            if(dif[st[edges[i]]]<0){
                w[edges[i]]=l[edges[i]];
                edges.erase(edges.begin()+i);
                solve(); fnd = 1;
            }
        }
        if(!fnd) break;
    }
    if(dif[f]<0){
        printf("WIN\n");
        for(i=1;i<=k;i++)
            printf("%lld ",w[i]);
        printf("\n");
        return 0;
    }
    for(i=1;i<=k;i++) w[i]=r[i];
    solve();
    edges.clear();
    for(i=1;i<=k;i++) edges.push_back(i);
    while(1){
        bool fnd = 0;
        for(i=0;i<edges.size();i++){
            if(dif[st[edges[i]]]<0){
                w[edges[i]]=l[edges[i]];
                edges.erase(edges.begin()+i);
                solve(); fnd = 1;
            }
        }
        if(!fnd) break;
    }
    if(dif[f]<=0){
        printf("DRAW\n");
        for(i=1;i<=k;i++)
            printf("%lld ",w[i]);
        printf("\n");
        return 0;
    }
    printf("LOSE\n");
    return 0;
}