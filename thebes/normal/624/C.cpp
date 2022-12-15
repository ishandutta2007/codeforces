#include <bits/stdc++.h>
using namespace std;

const int MN = 505;
int N, M, i, j, x, y, vis[MN], a[MN], sz, ed;
vector<int> adj[MN], cc, e;
vector<vector<int>> elem;
string ans;

void dfs(int n){
    vis[n]=i; e.push_back(n);
    sz++; 
    for(auto v : adj[n]){
        if(!vis[v]) dfs(v);
        if(!a[v]) ed++;
    }
}

int main(){
    scanf("%d%d",&N,&M);
    for(i=1;i<=M;i++){
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(i=1;i<=N;i++){
        if(adj[i].size()==N-1){
            vis[i]=1,a[i]=1;
        }
    }
    for(i=1;i<=N;i++){
        if(vis[i]) continue;
        sz=ed=0; e.clear();
        dfs(i); ed/=2;
        if(sz*(sz-1)/2!=ed){
            printf("No\n");
            return 0;
        }
        cc.push_back(i);
        elem.push_back(e);
    }
    if(cc.size()>2) printf("No\n");
    else{
        printf("Yes\n");
        for(i=0;i<elem.size();i++){
            for(j=0;j<elem[i].size();j++)
                a[elem[i][j]]=2*i;
        }
        for(i=1;i<=N;i++) printf("%c",a[i]+'a');
        printf("\n");
    }
    return 0;
}