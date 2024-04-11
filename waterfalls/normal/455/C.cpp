#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,q;
int p[300013];
int h[300013];
int l[300013];
vector<int> adj[300013];
int visited[300013];
int dist[300013];
vector<int> cur;

int findSet(int x) { return p[x]==x ? x : p[x]=findSet(p[x]); }
void mergeSets(int a, int b) {
    int r1 = findSet(a), r2 = findSet(b);
    if (r1==r2) return;
    if (h[r1]<h[r2]) p[r1] = r2;
    else p[r2] = r1;
    if (h[r1]==h[r2]) h[r1]+=1;
    l[findSet(r1)] = max(max(l[r1],l[r2]),(l[r1]+1)/2+(l[r2]+1)/2+1);
}
bool sameSet(int a, int b) { return findSet(a)==findSet(b); }

void dfs(int x, int d) {
    dist[x] = d;
    visited[x] = 1;
    cur.push_back(x);
    for (int i=0;i<adj[x].size();i++) if (!visited[adj[x][i]]) dfs(adj[x][i],d+1);
}

int main() {
    scanf("%d%d%d",&n,&m,&q);
    for (int i=0;i<n;i++) p[i] = i, h[i] = 0, l[i] = 0;
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a-=1; b-=1;
        mergeSets(a,b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int j=0;j<n;j++) if (!visited[j]) {
        cur.clear();
        dfs(j,0);
        int worst1 = cur[0];
        for (int i=0;i<cur.size();i++) if (dist[cur[i]]>dist[worst1]) worst1 = cur[i];
        for (int i=0;i<cur.size();i++) visited[cur[i]] = 0;
        cur.clear();
        dfs(worst1,0);
        int worst2 = cur[0];
        for (int i=0;i<cur.size();i++) if (dist[cur[i]]>dist[worst2]) worst2 = cur[i];
        l[findSet(j)] = dist[worst2];
    }
    for (int i=0;i<q;i++) {
        int type;
        scanf("%d",&type);
        if (type==1) {
            int x;
            scanf("%d",&x);
            printf("%d\n",l[findSet(x-1)]);
        } else {
            int a,b;
            scanf("%d%d",&a,&b);
            mergeSets(a-1,b-1);
        }
    }

    return 0;
}