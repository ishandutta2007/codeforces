#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m,ok;
vector<pair<int,int> > edges;
int p[100013];
vector<int> adj[100013];
int visited[100013];
const int MOD = 1000000007;

int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) { p[find(a)] = find(b); }

void dfs(int x, int c) {
    visited[x] = c;
    for (int& i: adj[x]) {
        if (!visited[i]) dfs(i,3-c);
        else if (3-c!=visited[i]) ok = 0;
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) p[i] = i;
    for (int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (c==1) merge(a,b);
        else edges.push_back(MP(a,b));
    }
    ok = 1;
    for (pair<int,int>& e: edges) {
        if (find(e.A)==find(e.B)) ok = 0;
        adj[find(e.A)].push_back(find(e.B));
        adj[find(e.B)].push_back(find(e.A));
    }
    int ans = 0;
    for (int i=1;i<=n;i++) if (!visited[find(i)]) {
        dfs(find(i),1);
        if (ans) ans = (ans*2)%MOD;
        else ans = 1;
    }
    if (ok) printf("%d\n",ans);
    else printf("0\n");

    return 0;
}