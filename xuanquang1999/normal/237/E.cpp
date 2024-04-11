#include <bits/stdc++.h>

using namespace std;

const int oo = 1000000007;

struct Edge {
    int v, rev, cap, f, cost;
};

class MaxFlow {
private:
    int n;
    vector<vector<Edge>> g;
    vector<int> pNode, pEdge;

    bool spfa(int s, int t) {
        queue<int> q;
        vector<bool> inQueue(n, false);
        vector<int> dist(n, oo);
        pNode.assign(n, -1);
        pEdge.assign(n, -1);

        q.push(s);
        inQueue[s] = true;
        dist[s] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            inQueue[u] = false;

            for(int i = 0; i < g[u].size(); ++i) {
                Edge e = g[u][i];
                if (e.cap - e.f == 0)
                    continue;
                if (dist[u] + e.cost < dist[e.v]) {
                    dist[e.v] = dist[u] + e.cost;
                    pNode[e.v] = u;
                    pEdge[e.v] = i;
                    if (!inQueue[e.v]) {
                        q.push(e.v);
                        inQueue[e.v] = true;
                    }
                }
            }
        }

        return (dist[t] != oo);
    }

    pair<int, int> increaseFlow(int s, int t) {
        int df = oo;
        for(int v = t; v != s; v = pNode[v]) {
            int u = pNode[v], i = pEdge[v];
            df = min(df, g[u][i].cap - g[u][i].f);
        }

        int dcost = 0;
        for(int v = t; v != s; v = pNode[v]) {
            int u = pNode[v], i = pEdge[v];
            g[u][i].f += df;
            g[v][g[u][i].rev].f -= df;
            dcost += g[u][i].cost * df;
        }

        return {df, dcost};
    }

public:
    MaxFlow(int n): n(n) {
        g.assign(n, vector<Edge>());
    }

    void addEdge(int u, int v, int cap, int cost) {
        g[u].push_back({v, g[v].size(), cap, 0, cost});
        g[v].push_back({u, g[u].size() - 1, 0, 0, -cost});
    }

    pair<int, int> getMaxFlow(int s, int t) {
        int flow = 0, cost = 0;
        while (spfa(s, t)) {
            pair<int, int> res = increaseFlow(s, t);
            flow += res.first; cost += res.second;
        }

        return {flow, cost};
    }
};

vector<int> getCharCount(string s) {
    vector<int> cnt(26, 0);
    for(char c: s)
        ++cnt[c - 'a'];
    return cnt;
}

int main() {
    string t; int n;
    cin >> t >> n;

    MaxFlow f(n + 28);
    /*
       0: source
       1 -> 26: alphabet
       27 -> n + 26: string
       n + 27: sink
    */

    vector<int> cntT = getCharCount(t);
    for(int c = 0; c < 26; ++c)
        f.addEdge(0, c + 1, cntT[c], 0);

    for(int i = 0; i < n; ++i) {
        string s; int a;
        cin >> s >> a;

        vector<int> cntS = getCharCount(s);
        for(int c = 0; c < 26; ++c)
            f.addEdge(c + 1, i + 27, cntS[c], 0);
        f.addEdge(i + 27, n + 27, a, i+1);
    }

    pair<int, int> res = f.getMaxFlow(0, n + 27);
    if (res.first != t.length())
        cout << -1 << endl;
    else
        cout << res.second << endl;

    return 0;
}