#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<int> adj[100013];
int visited[100013];
int h[100013];
int s[100013];
int ancestor[100013][20];

void dfs(int x) {
    visited[x] = 1;
    s[x] = 1;
    for (int i=0;i<adj[x].size();i++) {
        if (!visited[adj[x][i]]) {
            h[adj[x][i]] = h[x]+1;
            dfs(adj[x][i]);
            s[x]+=s[adj[x][i]];
            ancestor[adj[x][i]][0] = x;
        }
    }
    ancestor[x][0] = -1;
}

int findkth(int x, int k) {
    int where = x;
    for (int i=19;i>=0;i--) if (k&(1<<i)) where = ancestor[where][i];
    return where;
}

int lca(int a, int b) {
    if (h[a]>h[b]) swap(a,b);
    b = findkth(b,h[b]-h[a]);
    if (a==b) return a;
    for (int i=19;i>=0;i--) {
        if (h[a]<(1<<i)) continue;
        int na = ancestor[a][i];
        int nb = ancestor[b][i];
        if (na!=nb) a = na, b = nb;
    }
    return ancestor[a][0];
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n-1;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a-=1; b-=1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    for (int i=1;i<20;i++) {
        for (int j=0;j<n;j++) {
            if (h[j]<(1<<i)) ancestor[j][i] = -1;
            else ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];
        }
    }
    scanf("%d",&m);
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a-=1; b-=1;
        if (a==b) printf("%d\n",n);
        else {
            int l = lca(a,b);
            int dist = h[a]+h[b]-2*h[l];
            if (dist%2!=0) printf("0\n");
            else {
                if (h[a]<h[b]) swap(a,b);
                if (h[a]==h[b]) printf("%d\n",n-s[findkth(a,dist/2-1)]-s[findkth(b,dist/2-1)]);
                else printf("%d\n",s[findkth(a,dist/2)]-s[findkth(a,dist/2-1)]);
            }
        }
    }

    return 0;
}