#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> adj[200013];
int leaves[200013];
int sz[200013];
bool visited[200013];


void dfs(int x) {
    visited[x] = 1;
    sz[x] = 1;
    for (int i=0;i<adj[x].size();i++) if (!visited[adj[x][i]]) dfs(adj[x][i]), sz[x]+=sz[adj[x][i]], leaves[x]+=leaves[adj[x][i]];
    if (sz[x]==1) leaves[x] = 1;
}

pair<pair<int,int>,pair<int,int> > dfs1(int x) {
    visited[x] = 1;
    if (sz[x]==1) return make_pair(make_pair(1,0),make_pair(1,0));
    pair<pair<int,int>,pair<int,int> > r;
    for (int i=0;i<adj[x].size();i++) {
        if (visited[adj[x][i]]) continue;
        pair<pair<int,int>,pair<int,int> > next = dfs1(adj[x][i]);
        r.first.first+=leaves[adj[x][i]]-next.second.second;
        r.first.second = max(r.first.second,leaves[x]-next.second.first);
        r.second.first+=leaves[adj[x][i]]-next.first.second;
        r.second.second = max(r.second.second,leaves[x]-next.first.first);
    }
    return r;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        u-=1; v-=1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    for (int i=0;i<n;i++) visited[i] = 0;
    pair<pair<int,int>,pair<int,int> > ans = dfs1(0);
    printf("%d %d\n",ans.first.second+1,ans.first.first); // this line during contest said leaves[0]+1-ans.first.first >.>

    return 0;
}