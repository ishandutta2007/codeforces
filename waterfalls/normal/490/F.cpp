#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int r[6000];
pair<int,int> pops[6000];
vector<int> adj[6000];
int visited[6000];
vector<int> best[6000];

void dfs(int x, int start, int dir) {
    if (x==start) for (int i=0;i<n;i++) visited[i] = 0;
    visited[x] = 1;
    if (x==start) {
        dfs(adj[x][dir],start,dir);
        return;
    }
    if (r[start]>r[x]) {
        best[start][dir] = max(best[start][dir],2);
        for (int i=0;i<adj[x].size();i++) {
            if (visited[adj[x][i]]) continue;
            best[start][dir] = max(best[start][dir],1+best[x][i]);
        }
    }
    for (int i=0;i<adj[x].size();i++) if (!visited[adj[x][i]]) dfs(adj[x][i],start,dir);
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&r[i]);
        pops[i] = make_pair(r[i],i);
    }
    for (int i=0;i<n-1;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a-=1; b-=1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0;i<n;i++) for (int j=0;j<adj[i].size();j++) best[i].push_back(1);
    sort(pops,pops+n);
    for (int p=0;p<n;p++) {
        int i = pops[p].second;
        for (int j=0;j<adj[i].size();j++) dfs(i,i,j);
    }
    int ans = 0;
    for (int i=0;i<n;i++) for (int j=0;j<adj[i].size();j++) ans = max(ans,best[i][j]);
    printf("%d\n",ans);

    return 0;
}