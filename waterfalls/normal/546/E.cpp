#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,V;
int source,sink,found;
int visited[500];
int res[500][500];
vector<int> adj[500];

void connect(int a, int b, int c) { adj[a].push_back(b); adj[b].push_back(a); res[a][b] = c; }

void dfs(int x, int cap) {
    visited[x] = 1;
    if (x==sink) {
        found = cap;
        return;
    }
    for (int i=0;i<adj[x].size();i++) {
        if (!visited[adj[x][i]] && res[x][adj[x][i]]) {
            dfs(adj[x][i],min(cap,res[x][adj[x][i]]));
            if (found) {
                res[x][adj[x][i]]-=found;
                res[adj[x][i]][x]+=found;
                return;
            }
        }
    }
}

int maxflow() {
    int flow = 0;
    while (true) {
        for (int i=0;i<V;i++) visited[i] = 0;
        found = 0;
        dfs(source,1e9);
        if (!found) break;
        flow+=found;
    }
    return flow;
}

int main() {
    source = 0; sink = 1;
    scanf("%d%d",&n,&m);
    V = 2*n+2;
    int tot = 0;
    for (int i=2;i<n+2;i++) {
        int a;
        scanf("%d",&a);
        tot+=a;
        connect(source,i,a);
    }
    int tot2 = 0;
    for (int i=n+2;i<2*n+2;i++) {
        int b;
        scanf("%d",&b);
        tot2+=b;
        connect(i,sink,b);
    }
    if (tot!=tot2) {
        printf("NO\n");
        return 0;
    }
    for (int i=2;i<n+2;i++) connect(i,i+n,1e9);
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        connect(a+1,b+n+1,1e9);
        connect(b+1,a+n+1,1e9);
    }
    int flow = maxflow();
    if (flow!=tot) printf("NO\n");
    else {
        printf("YES\n");
        for (int i=2;i<n+2;i++) {
            for (int j=n+2;j<2*n+2;j++) printf("%d ",res[j][i]);
            printf("\n");
        }
    }

    return 0;
}