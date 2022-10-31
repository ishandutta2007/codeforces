#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,q;
vector<pair<int,int> > adj[100013];
int visited[100013];
int sizst[100013];
int sumst[100013];
int sqsst[100013];
int sumsq[100013];
int sumsm[100013];
int depth[100013];
int h[100013];
int ancestor[100013][20];
int up[100013];
int MOD = 1000000007;

void dfsLCA(int x) {
    visited[x] = 1;
    for (int i=0;i<adj[x].size();i++) {
        int next = adj[x][i].first;
        int dist = adj[x][i].second;
        if (!visited[next]) {
            h[next] = h[x]+1;
            depth[next] = (depth[x]+dist)%MOD;
            dfsLCA(next);
            ancestor[next][0] = x;
            up[next] = dist;
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

void dfs(int x) {
    visited[x] = 1;
    sizst[x] = 1;
    for (int i=0;i<adj[x].size();i++) {
        int next = adj[x][i].first;
        if (visited[next]) continue;
        dfs(next);
        int dist = adj[x][i].second;
        sizst[x]+=sizst[next];
        sumst[x] = (sumst[x]+sumst[next]+(long long) dist*sizst[next])%MOD;
        int distsq = ((long long) dist*dist)%MOD;
        sqsst[x] = (sqsst[x]+(long long) distsq*sizst[next]+(long long) 2*dist*sumst[next]+sqsst[next])%MOD;
    }
}

void dfs2(int x) {
    visited[x] = 1;
    if (x==0) {
        sumsm[x] = sumst[x];
        sumsq[x] = sqsst[x];
    } else {
        int prev = ancestor[x][0];
        int dist = up[x];
        int distsq = ((long long) dist*dist)%MOD;
        int below = (sqsst[x]+(long long) 2*dist*sumst[x]+(long long) sizst[x]*distsq)%MOD;
        int abovesq = (sumsq[prev]-below+MOD)%MOD;
        int abovesm = ((sumsm[prev]-sumst[x]-(long long) dist*sizst[x]+MOD)%MOD+MOD)%MOD;
        int num = n-sizst[x];
        sumsm[x] = (sumst[x]+abovesm+(long long) num*dist)%MOD;
        sumsq[x] = (sqsst[x]+(long long) distsq*num+((long long) 2*dist*abovesm)%MOD+abovesq)%MOD;
    }
    for (int i=0;i<adj[x].size();i++) if (!visited[adj[x][i].first]) dfs2(adj[x][i].first);
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<n;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a-=1; b-=1;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    dfsLCA(0);
    for (int i=1;i<20;i++) {
        for (int j=0;j<n;j++) {
            if (h[j]<(1<<i)) ancestor[j][i] = -1;
            else ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];
        }
    }
    for (int i=0;i<n;i++) visited[i] = 0;
    dfs(0);
    for (int i=0;i<n;i++) visited[i] = 0;
    dfs2(0);
    scanf("%d",&q);
    for (int i=0;i<q;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        u-=1; v-=1;
        int l = lca(u,v);
        if (l==v) {
            int diff = (depth[u]-depth[v]+MOD)%MOD;
            int diffsq = ((long long) diff*diff)%MOD;
            int abovesq = (sumsq[v]-sqsst[v]+MOD)%MOD;
            int abovesm = (sumsm[v]-sumst[v]+MOD)%MOD;
            int tops = ((long long) diffsq*(n-sizst[v])+((long long) 2*diff*abovesm)%MOD+abovesq)%MOD;
            int part1 = (sumsq[u]-tops+MOD)%MOD;
            printf("%d\n",((long long) 2*part1-sumsq[u]+MOD)%MOD);
        } else {
            int diff = ((long long) depth[u]+depth[v]-2*depth[l]+2*MOD)%MOD;
            int diffsq = ((long long) diff*diff)%MOD;
            int part1 = ((long long) diffsq*sizst[v]+((long long) 2*diff*sumst[v])%MOD+sqsst[v])%MOD;
            printf("%d\n",((long long) 2*part1-sumsq[u]+MOD)%MOD);
        }
    }

    return 0;
}