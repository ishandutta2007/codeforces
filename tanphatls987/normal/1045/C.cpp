#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int M = 5e5 + 10;

int n;
struct blockCutTree{
    int lv[N];
    int w[N];
    int pa[N][20];
    int mapping[N];
    bool isCut(int ru) {
        return ru <= n;
    }
    int LCA(int x, int y) {
        if (lv[x] < lv[y]) swap(x, y);
        for(int i = 0, d = lv[x] - lv[y]; d; i++, d >>= 1)
            if (d & 1) x = pa[x][i];
        if (x == y) return x;
        for(int i = 19; i >= 0; i--) if (pa[x][i] != pa[y][i])
            x = pa[x][i], y = pa[y][i];
        return pa[x][0];
    }
    void buildLCA() {
        for(int j = 1; j < 20; j++)
            for(int i = 0; i < N; i++)
                pa[i][j] = pa[pa[i][j - 1]][j - 1];
    }
    int countCutVer(int rx, int ry) {
        int rz = LCA(rx, ry);
        return w[rx] + w[ry] - w[rz] - w[pa[rz][0]];
    }
}tree;





struct graph{
    ///this will also work on multigraph,
    ///also for each component add a fake edge from 0 to dfs root to simplify implementation
    /// Attention: for simplification assume that dfs root is alway a cut vertex(not true)
    /// if cutV[root] >= 2 then it is a real cut vertex
    vector<int> adj[N];
    int e[M][2];
    int m;
    int num[N], low[N];
    int cutV[N];
    int pE[N], pV[N];
    int n1;
    int nTree;

    stack<int> st, rq;

    void reset() {
        m = n1 = 0;
        for(int i = 0; i < N; i++)
            adj[i].clear();
        memset(cutV, 0, sizeof(cutV));
        memset(num, 0, sizeof(num));
    }
    void addEdge(int u, int v) {
        ++m;
        e[m][0] = u; e[m][1] = v;
        adj[u].push_back(m);
        adj[v].push_back(m);
    }
    void DFS(int u) {
        num[u] = low[u] = ++n1;
        st.push(u);
        for(auto i : adj[u]) if (i != pE[u]) {
            int v = e[i][0] + e[i][1] - u;
            if (num[v] != 0) {
                low[u] = min(low[u], num[v]);
            } else {
                pE[v] = i; pV[v] = u;
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
        }
        if (low[u] >= num[pV[u]]) {
            nTree++;
            while (1) {
                int x = st.top(); st.pop();
                if (cutV[x]) {
                    tree.pa[x][0] = nTree;
                    tree.mapping[x] = x;
                    rq.push(x);
                } else {
                    tree.mapping[x] = nTree;
                }
                if (x == u) break;
                
            }
            tree.pa[nTree][0] = pV[u];
            rq.push(nTree);
            cutV[pV[u]]++;
        }
    }

    void decompose() {
        nTree = n;
        st.push(0);
        for(int i = 1; i <= n; i++) if (num[i] == 0)
            DFS(i);
        st.pop();
        assert(st.empty());
        while (!rq.empty()) {
            int x = rq.top(); rq.pop();
            tree.lv[x] = tree.lv[tree.pa[x][0]] + 1;
            tree.w[x] = tree.w[tree.pa[x][0]] + (x <= n);
        }
        tree.buildLCA();

    }
}graph;

int getDistance(int x, int y) {
    if (x == y) return 0;
    int ans = tree.countCutVer(tree.mapping[x], tree.mapping[y]);
    if (graph.cutV[x]) ans--;
    if (!graph.cutV[y]) ans++;
    return ans;
}

///testing using https://codeforces.com/contest/1045/problem/C
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, test;
    cin >> n >> m >> test;
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }
    graph.decompose();

    while (test--) {
        int u, v;
        cin >> u >> v;
        //assert(getDistance(u, v) == getDistance(v, u));
        cout << getDistance(u, v) << '\n';
    }

}