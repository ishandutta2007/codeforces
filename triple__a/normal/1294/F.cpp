#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn=200007;
int n,par[maxn],dist[maxn];
VI vec[maxn];
bool vis[maxn];

int bfs(int u){
    queue<int>q;
    q.push(u);
    vis[u]=1;
    par[u]=-1;
    dist[u]=0;
    int x;
    while (q.size()){
        x=q.front();
        q.pop();
        for (auto c:vec[x]){
            if (!vis[c]){
                dist[c]=dist[x]+1;
                vis[c]=1;
                par[c]=x;
                q.push(c);
            }
        }
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        vec[u].pb(v), vec[v].pb(u);
    }
    memset(vis,0,sizeof(vis));
    memset(dist,0,sizeof(dist));
    int l=bfs(1);
    memset(vis,0,sizeof(vis));
    memset(dist,0,sizeof(dist));
    int r=bfs(l);
    int ret=dist[r];
    VI ans;
    ans.clear();
    int ll=l, rr=r;
    while (r!=l){
        ans.pb(r);
        r=par[r];
    }
    ans.pb(l);
    memset(vis,0,sizeof(vis));
    memset(dist,0,sizeof(dist));
    for (auto c:ans){
        vis[c]=1;
    }
    int uu=-1,rrr=0;
    for (auto c:ans){
        int tt=bfs(c);
        if (dist[tt]>rrr) uu=tt, rrr=dist[tt];
    }
    cout<<rrr+ret<<endl;
    if (uu==-1){
        for (int i=1;i<=n;++i){
            if (i!=ll&&i!=rr){
                cout<<ll<<" "<<rr<<" "<<i<<endl;
                return 0;
            }
        }
    }
    cout<<ll<<" "<<rr<<" "<<uu<<endl;
    return 0;
}