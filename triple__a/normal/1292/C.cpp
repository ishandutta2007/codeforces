#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=3007;
int sz[maxn][maxn],par[maxn][maxn],dp[maxn][maxn];
int n,ans;
vector<int> vec[maxn];

void dfs(int u,int p,int r){
    sz[u][r]=1;
    par[u][r]=p;
    for (auto c:vec[u]){
        if (c==p) continue;
        dfs(c,u,r);
        sz[u][r]+=sz[c][r];
    }
}

int f(int u,int v){
    if (u==v) return 0;
    if (dp[u][v]) return dp[u][v];
    int ret=sz[u][v]*sz[v][u]+max(f(par[u][v],v),f(u,par[v][u]));
    return dp[u][v]=ret;
}

#undef int
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for (int i=1;i<=n;++i){
        dfs(i,-1,i);
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            ans=max(ans,f(i,j));
        }
    }
    printf("%lld\n",ans);
    return 0;
}