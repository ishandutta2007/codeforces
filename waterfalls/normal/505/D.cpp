#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,num;
vector<int> adj[100013];
vector<int> adjUn[100013];
int comp[100013];
vector<int> comps[100013];
int cycle;

void dfs(int x) {
    comp[x] = num;
    comps[num].push_back(x);
    for (int i=0;i<adjUn[x].size();i++) if (!comp[adjUn[x][i]]) dfs(adjUn[x][i]);
}

void dfsCycle(int x) {
    comp[x] = 1;
    for (int i=0;i<adj[x].size();i++) {
        if (!comp[adj[x][i]]) dfsCycle(adj[x][i]);
        else if (comp[adj[x][i]]==1) cycle = 1;
    }
    comp[x] = 2;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a-=1; b-=1;
        adj[a].push_back(b);
        adjUn[a].push_back(b);
        adjUn[b].push_back(a);
    }
    num = 0;
    for (int i=0;i<n;i++) if (!comp[i]) num+=1, dfs(i);
    int ans = 0;
    for (int i=0;i<n;i++) comp[i] = 0;
    for (int i=1;i<=num;i++) {
        cycle = 0;
        for (int j=0;j<comps[i].size();j++) if (!comp[comps[i][j]]) dfsCycle(comps[i][j]);
        ans+=comps[i].size()-1+cycle;
    }
    printf("%d\n",ans);

    return 0;
}