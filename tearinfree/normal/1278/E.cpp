#include <bits/stdc++.h>
using namespace std;

int n,l[500001],r[500001],ed=1;
vector<int> adj[500001];

void dfs(int cur,int p) {
    int cnt=0;
    for(auto &it:adj[cur]) if(it!=p) cnt++;

    ed += cnt + 1;
    r[cur] = ed;
    
    int nl = ed - 1;
    for(auto &it:adj[cur]) if(it!=p) {
        l[it] = nl--;
        dfs(it, cur);
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1,u,v;i<n;i++) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    l[1] = 1;
    dfs(1,0);

    for(int i=1;i<=n;i++) printf("%d %d\n",l[i],r[i]);
    
    return 0;
}