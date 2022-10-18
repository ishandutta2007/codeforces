#include <bits/stdc++.h>

using namespace std;

const int oo = 1000000007;

struct Edge {
    int v, rev, c, f;
};

class MaxFlow {
private:
    vector<vector<Edge>> g;
    vector<int> level, pos;
    int n, t;

    bool dinic_bfs(int s, int t) {
        level.assign(n, -1);
        level[s] = 0;

        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = 0; i < g[u].size(); ++i) {
                Edge e = g[u][i];
                if (level[e.v] != -1 || e.c - e.f == 0)
                    continue;
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
        }

        return (level[t] != -1);
    }

    int dinic_dfs(int u, int f) {
        if (u == t)
            return f;

        for(; pos[u] < g[u].size(); ++pos[u]) {
            Edge &e = g[u][pos[u]];
            if (level[u] == level[e.v] - 1 && e.c - e.f > 0) {
                int df = dinic_dfs(e.v, min(f, e.c - e.f));
                if (df > 0) {
                    e.f += df;
                    g[e.v][e.rev].f -= df;
                    return df;
                }
            }
        }

        return 0;
    }

public:
    MaxFlow(int n): n(n) {
        g.assign(n, vector<Edge>());
    }

    void addEdge(int u, int v, int c) {
        g[u].push_back({v, g[v].size(), c, 0});
        g[v].push_back({u, g[u].size() - 1, 0, 0});
    }

    int getMaxFlow(int s, int t) {
        this->t = t;
        int res = 0;

        while (dinic_bfs(s, t)) {
            pos.assign(n, 0);
            int df;
            while (df = dinic_dfs(s, oo))
                res += df;
        }

        return res;
    }
};

struct ColorEdge {
    int u, v, c, cycInd;
};

int n, m;
vector<ColorEdge> e;
vector<vector<int>> g, cycle;
vector<int> d, pEdge, pNode;

void dfs(int u) {
    for(int i: g[u]) {
        int v = e[i].u + e[i].v - u;
        if (pNode[u] == v)
            continue;

        if (d[v] == -1) {
            d[v] = d[u] + 1;
            pEdge[v] = i;
            pNode[v] = u;
            dfs(v);
        } else if (d[v] < d[u]) {
            vector<int> newCyc;
            newCyc.push_back(i);
            e[i].cycInd = cycle.size();
            for(int t = u; t != v; t = pNode[t]) {
                newCyc.push_back(pEdge[t]);
                e[pEdge[t]].cycInd = cycle.size();
            }

            cycle.push_back(newCyc);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    g.assign(n, vector<int>());
    for(int i = 0; i < m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        --u; --v; --c;
        e.push_back({u, v, c, -1});
        g[u].push_back(i);
        g[v].push_back(i);
    }

    pNode.assign(n, -1);
    pEdge.assign(n, -1);
    d.assign(n, -1);
    d[0] = 0;

    dfs(0);

    for(int i = 0; i < m; ++i) {
        if (e[i].cycInd == -1) {
            e[i].cycInd = cycle.size();
            cycle.push_back(vector<int>(1, i));
        }
    }

    MaxFlow f(2*m + 2);
    for(int i = 0; i < m; ++i) {
        f.addEdge(2*m, i, 1);
        f.addEdge(e[i].c, e[i].cycInd + m, 1);
    }
    for(int i = 0; i < cycle.size(); ++i)
        f.addEdge(i + m, 2*m + 1, max((int)cycle[i].size() - 1, 1));

    int ans = f.getMaxFlow(2*m, 2*m+1);
    printf("%d", ans);

    return 0;
}