#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[500001];
vector<int> ansDepth[500001];
int depth[500001];
int par[500001];
int n,m;
bool found = false;
void dfs(int i){
    ansDepth[depth[i]].push_back(i);
    for(int next : adj[i]){
        if(depth[next]==0 && !found){
            depth[next] = depth[i]+1;
            par[next] = i;
            if(depth[next]>=(n+1)/2){
                found = true;
                //do stuff
                cout << "PATH" << endl;
                printf("%d\n",depth[next]);
                while(next!=-1){
                    printf("%d ",next+1);
                    next = par[next];
                }
                cout << endl;
            }
            else{
                dfs(next);
            }
        }
    }
}
void solve(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        adj[i].clear();
        depth[i] = 0;
        par[i] = 0;
        ansDepth[i].clear();
    }
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[0] = 1;
    par[0] = -1;
    found = false;
    dfs(0);
    if(!found){
        cout << "PAIRING" << endl;
        vector<pair<int,int>> curr;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<ansDepth[i].size()/2;j++){
                ++ans;
                curr.push_back({ansDepth[i][2*j],ansDepth[i][2*j+1]});
            }
        }
        printf("%d\n",ans);
        for(auto &it : curr){
            printf("%d %d\n",(it.first+1),(it.second+1));
        }
    }
}
int main(){
    int t; scanf("%d",&t);
    while(t--) solve();
}