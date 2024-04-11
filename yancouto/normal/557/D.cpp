#include <cstdio>
#ifndef ONLINE_JUDGE
#   define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#   define debug(args...) //
#endif
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 100009;
int n, m;
vector<int> adj[MAX];
int bip[MAX];
typedef unsigned long long ull;

bool dfs_1(int u) {
    for(int v : adj[u]) {
        if(bip[u] == bip[v]) return false;
        if(bip[v] == -1) {
            bip[v] = !bip[u];
            if(!dfs_1(v)) return false;
        }
    }
    return true;
}

int S[MAX], size[MAX], x[MAX], y[MAX];
int find(int i) {
    if(S[S[i]] != S[i]) S[i] = find(S[i]);
    return S[i];
}
void join(int a, int b) {
    if(a == b) return;
    if(size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    x[a] += x[b];
    y[a] += y[b];
    S[b] = a;
}


int deg[MAX], seen[MAX];

int main() {
    int i, a, b;
    scanf("%d %d", &n, &m);
    int deg_m = 0;
    for(i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++; deg[b]++;
        deg_m = max(deg_m, max(deg[a], deg[b]));
    }
    memset(bip, -1, sizeof(int) * (n + 2));
    bool bippp = true;
    for(i = 0; bippp && i < n; i++) {
        if(bip[i] == -1) {
            bip[i] = 0;
            if(!dfs_1(i)) bippp = false;
        }
    }
    if(!bippp) {
        printf("0 1\n");
        return 0;
    }
    if(m == 0) {
        ull xx = n;
        xx = (xx * (xx - 1) * (xx - 2)) / 6ull;
        printf("3 %I64u\n", xx);
        return 0;
    }
    if(deg_m == 1) {
        ull xx = n;
        xx = (xx - 2) * m;
        printf("2 %I64u\n", xx);
        return 0;
    }
    for(i = 0; i < n; i++) {
        S[i] = i;
        size[i] = 1;
        (bip[i]? x : y)[i] = 1;
    }
    for(i = 0; i < n; i++)
        for(int j : adj[i])
            join(find(i), find(j));
    ull resp = 0;
    for(i = 0; i < n; i++) {
        if(!seen[find(i)]) {
            seen[find(i)] = 1;
            ull xx = x[find(i)], yy = y[find(i)];
            if(!xx || !yy) continue;
            ull zz = (xx * (xx - 1)) / 2 + (yy * (yy - 1)) / 2;
            resp += zz;
        }
    }
    printf("1 %I64u\n", resp);
    return 0;
}