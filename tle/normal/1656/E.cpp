#include <bits/stdc++.h>
using namespace std;
int T,n,v[233333],dep[233333];
vector<int> adj[233333];
void dfs(int x,int fa=0) {
    vector<int> ch; dep[x]=dep[fa]^1;
    for(auto c:adj[x]) if(c!=fa) ch.push_back(c);
    for(auto c:ch) dfs(c,x);
    v[x]=((dep[x])?(-1):1)*int(adj[x].size());
}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;++i) adj[i].clear();
        for(int i=1,a,b;i<n;++i) {
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ro=0;
        for(int i=1;i<=n;++i)
            if(adj[i].size()<=1) ro=i;
        dfs(ro);
        for(int i=1;i<=n;++i)
            printf("%d ",v[i]);
        puts("");
    }
}