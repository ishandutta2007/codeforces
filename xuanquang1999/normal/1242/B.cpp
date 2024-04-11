#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> pset;
    int nComp;

    DSU(int n) {
        pset.assign(n+1, 0);
        for(int i = 1; i <= n; ++i)
            pset[i] = i;
        nComp = n;
    }

    int findSet(int i) {
        return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);
    }

    bool unionSet(int i, int j) {
        int p = findSet(i), q = findSet(j);
        if (p == q)
            return false;
        pset[p] = q;
        --nComp;
        return true;
    }
};

const int MAXN = 100005;

int n, m;
vector<int> graph[MAXN];
set<int> s;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int u = 1; u <= n; ++u) {
        graph[u].push_back(0);
        graph[u].push_back(n+1);
        sort(graph[u].begin(), graph[u].end());
    }

    set<int> s;
    for(int u = 1; u <= n+1; ++u) 
        s.insert(u);

    DSU dsu(n);
    for(int u = 1; u <= n; ++u) {
        for(int i = 1; i < graph[u].size(); ++i) {
            int l = graph[u][i-1] + 1, r = graph[u][i] - 1;
            if (l > r)
                continue;
            dsu.unionSet(u, l);
            
            int v;
            while ((v = *s.lower_bound(l)) <= r) {
                dsu.unionSet(u, v);
                s.erase(v);
            }
        }
    }

    int ans = dsu.nComp - 1;
    printf("%d\n", ans);
    
    return 0;
}