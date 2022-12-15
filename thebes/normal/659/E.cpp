#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

const int MN = 1e5+5;
int N, M, i, x, y, vis[MN], ans;
vi adj[MN];

int dfs(int n){
    int ret = -1;
    vis[n] = 1;
    for(auto v : adj[n]){
        if(v<n) ret ++;
        if(!vis[v]) ret += dfs(v);
    }
    return ret;
}

int main(){
    for(scanf("%d%d",&N,&M),i=1;i<=M;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(i=1;i<=N;i++){
        if(vis[i]) continue;
        if(dfs(i)<0) ans++;
    }
    printf("%d\n",ans);
    return 0;
}