#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m,counter,tot;
int low[2013];
int num[2013];
set<int> adj[2013];
vector<pair<int,int> > bridges;
int can[2013];
vector<int> has;

int p[2013];
int s[2013];
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) {
    if (find(a)==find(b)) return;
    s[find(b)]+=s[find(a)];
    p[find(a)] = find(b);
}

void dfs(int x, int pp) {
    num[x] = low[x] = counter++;
    for (int i: adj[x]) {
        if (!num[i]) {
            dfs(i,x);
            low[x] = min(low[x],low[i]);
            if (low[i]>num[x]) bridges.push_back(MP(x,i));
        } else if (i!=pp) low[x] = min(low[x],num[i]);
    }
}

int dfs2(int x, int pp, int cur) {
    tot+=s[x];
    int res = cur*s[x];
    for (int i: adj[x]) if (i!=pp) res+=dfs2(i,x,cur+s[x]);
    return res;
}

int sc[2013];
int findC(int x=find(1), int pp=0) {
    int ok = 1;
    sc[x] = s[x];
    for (int i: adj[x]) if (i!=pp) {
        int pos = findC(i,x);
        if (pos) return pos;
        if (sc[i]>n/2) ok = 0;
        sc[x]+=sc[i];
    }
    if (n-sc[x]>n/2) ok = 0;
    return ok ? x : 0;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].insert(v);
        adj[v].insert(u);
    }
    counter = 1;
    dfs(1,0);
    for (pair<int,int> e: bridges) {
        adj[e.A].erase(e.B);
        adj[e.B].erase(e.A);
    }
    for (int i=1;i<=n;i++) p[i] = i, s[i] = 1;
    for (int i=1;i<=n;i++) for (int j: adj[i]) merge(i,j);
    for (int i=1;i<=n;i++) adj[i].clear();
    for (pair<int,int> e: bridges) {
        adj[find(e.A)].insert(find(e.B));
        adj[find(e.B)].insert(find(e.A));
    }
    int ans = 0;
    for (int c=findC();c<=n;c+=n) if (find(c)==c) {
        int cur = 0;
        for (int i=1;i<=n;i++) if (find(i)==i) cur+=s[i]*s[i];
        has.clear();
        for (int i: adj[c]) {
            tot = 0;
            cur+=dfs2(i,c,s[c]);
            has.push_back(tot);
        }
        for (int i=0;i<=n;i++) can[i] = 0;
        can[0] = 1;
        for (int j: has) {
            for (int i=n;i>=0;i--) if (i+j<=n) can[i+j]|=can[i];
        }
        int best = 0;
        for (int i=1;i<=n;i++) if (can[i]) best = max(best,i*(n-s[c]-i));
        cur+=best;
        ans = max(ans,cur);
    }
    printf("%d\n",ans);

    return 0;
}