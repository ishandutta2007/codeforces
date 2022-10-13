#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[100001];
int depth[100001];
int dp[100001];
vector<pair<int,int>> edges;
bool  work = true;
void dfs(int i){
    for(int next : adj[i]){
        if(depth[next]==0){
            edges.push_back({i,next});
            depth[next] = depth[i]+1;
            dfs(next);
            dp[i]+=dp[next];
        }
    }
    for(int next : adj[i]){
        if(depth[next]<depth[i]-1){
            ++dp[i];
            edges.push_back({i,next});
        }
        if(depth[next]>depth[i]+1){
            --dp[i];
        }
    }
    if(i!=0 && dp[i]==0) work = false;
    
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[0] = 1;
    dfs(0);
    if(work){
        for(auto &it : edges){
            printf("%d %d\n", it.first+1,it.second+1);
        }
    }
    else printf("%d\n",0);
}