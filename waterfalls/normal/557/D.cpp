#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,cyc;
vector<int> adj[100013];
int visited[100013];

pair<int,int> dfs(int x, int d) {
    pair<int,int> r = make_pair(0,1);
    visited[x] = d;
    for (int i=0;i<adj[x].size();i++) {
        if (!visited[adj[x][i]]) {
            pair<int,int> n = dfs(adj[x][i],3-d);
            r.first+=n.second;
            r.second+=n.first;
        } else if (visited[adj[x][i]]!=3-d) cyc = 1;
    }
    return r;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int found = 0;
    for (int i=1;i<=n;i++) if (adj[i].size()>=2) found = 1;
    if (!found) {
        if (m==0) printf("3 %lld\n",(long long) n*(n-1)*(n-2)/6);
        else printf("2 %lld\n",(long long) m*(n-2));
        return 0;
    }
    long long ans = 0;
    cyc = 0;
    for (int i=1;i<=n;i++) if (!visited[i]) {
        pair<int,int> r = dfs(i,1);
        ans+=(long long) r.first*(r.first-1)/2;
        ans+=(long long) r.second*(r.second-1)/2;
    }
    if (cyc==1) printf("0 1\n");
    else printf("1 %lld\n",ans);

    return 0;
}