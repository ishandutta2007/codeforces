#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m,q,counter;
int p[200013];
multiset<int> adj[200013];
int num[200013];
int low[200013];
vector<pair<int,int> > bridges;
vector<int> bcc[200013];
int h[200013];
int up[20][200013];
int addU[200013];
int addD[200013];
int rem[200013];

int find(int x) { return p[x]==x ? x : p[x] = find(p[x]); }
void merge(int a, int b) { p[find(a)] = find(b); }

void dfs(int x, int pa) {
    num[x] = low[x] = counter++;
    for (const int& i: adj[x]) {
        if (!num[i]) {
            dfs(i,x);
            low[x] = min(low[x],low[i]);
            if (low[i]>num[x]) {
                bridges.push_back(MP(x,i));
            }
        } else if (i!=pa) low[x] = min(low[x],num[i]);
        else pa = -1;
    }
}

void dfs2(int x, int pa, int d) {
    num[x] = 1;
    up[0][x] = pa;
    h[x] = d;
    for (int& i: bcc[x]) if (!num[i]) dfs2(i,x,d+1);
}

int lca(int a, int b) {
    if (h[a]<h[b]) swap(a,b);
    int d = h[a]-h[b];
    for (int i=0;i<20;i++) if (d&(1<<i)) a = up[i][a];
    if (a==b) return a;
    for (int i=19;i>=0;i--) if (up[i][a]!=up[i][b]) {
        a = up[i][a];
        b = up[i][b];
    }
    return up[0][a];
}

int ok;
pair<int,int> dfs3(int x) {
    num[x] = 1;
    int u = addU[x];
    int d = addD[x];
    for (int& i: bcc[x]) if (!num[i]) {
        pair<int,int> r = dfs3(i);
        u+=r.A;
        d+=r.B;
    }
    u-=rem[x];
    d-=rem[x];
    if (u && d) ok = 0;
    return MP(u,d);
}

int main() {
    scanf("%d%d%d",&n,&m,&q);
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    counter = 1;
    for (int i=1;i<=n;i++) if (!num[i]) dfs(i,-1);
    for (pair<int,int>& e: bridges) {
        adj[e.A].erase(e.B);
        adj[e.B].erase(e.A);
    }
    for (int i=1;i<=n;i++) p[i] = i;
    for (int i=1;i<=n;i++) for (const int& j: adj[i]) merge(i,j);
    for (pair<int,int>& e: bridges) {
        e.A = find(e.A);
        e.B = find(e.B);
        bcc[e.A].push_back(e.B);
        bcc[e.B].push_back(e.A);
    }
    for (int i=1;i<=n;i++) num[i] = 0;
    for (int i=1;i<=n;i++) if (!num[find(i)]) dfs2(find(i),0,0);
    for (int i=1;i<20;i++) for (int j=1;j<=n;j++) {
        up[i][j] = up[i-1][up[i-1][j]];
    }
    for (int i=0;i<q;i++) {
        int s,d;
        scanf("%d%d",&s,&d);
        s = find(s); d = find(d);
        if (s==d) continue;
        addU[s]+=1;
        addD[d]+=1;
        int l = lca(s,d);
        if (l==0) {
            printf("No\n");
            return 0;
        }
        rem[l]+=1;
    }
    for (int i=1;i<=n;i++) num[i] = 0;
    ok = 1;
    for (int i=1;i<=n;i++) if (!num[find(i)]) dfs3(find(i));
    if (ok) printf("Yes\n");
    else printf("No\n");

    return 0;
}