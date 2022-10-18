#include <bits/stdc++.h>

using namespace std;

const int MOD = 2520;

struct Function {
    int n;
    vector<int> g;

    Function(int n): n(n) {
        g.assign(n, -1);
    }

    void setEdge(int u, int v) {
        g[u] = v;
    }

    vector<int> getCycLen() {
        vector<int> cycLen(n, -1);
        vector<bool> visited(n, false);

        for(int s = 0; s < n; ++s) {
            if (!visited[s]) {
                vector<int> vtx;
                int u = s;
                while (!visited[u]) {
                    visited[u] = true;
                    vtx.push_back(u);
                    u = g[u];
                }

                if (cycLen[u] == -1) {
                    for(int i = 0; i < vtx.size(); ++i) {
                        if (vtx[i] == u) {
                            unordered_set<int> cycVtx;
                            for(int j = i; j < vtx.size(); ++j)
                                cycVtx.insert(vtx[j] / MOD);
                            cycLen[u] = cycVtx.size();
                            break;
                        }
                    }
                }
                for(int v: vtx)
                    cycLen[v] = cycLen[u];
            }
        }

        return cycLen;
    }
};

const int MAXN = 1005;

int n, q, k[MAXN];
vector<int> g[MAXN];

int toInd(int u, int c) {
    return u * MOD + c;
}

int main() {
    scanf("%d", &n);
    for(int u = 0; u < n; ++u)
        scanf("%d", &k[u]);

    for(int u = 0; u < n; ++u) {
        int m;
        scanf("%d", &m);

        g[u].resize(m);
        for(int i = 0; i < m; ++i) {
            scanf("%d", &g[u][i]);
            --g[u][i];
        }
    }

    Function f(n * MOD);

    for(int u = 0; u < n; ++u) {
        for(int c = 0; c < MOD; ++c) {
            int newC = ((c + k[u])%MOD + MOD) % MOD;
            int newU = g[u][newC % g[u].size()];
            f.setEdge(toInd(u, c), toInd(newU, newC));
        }
    }

    vector<int> cycLen = f.getCycLen();

    scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
        int u, c;
        scanf("%d%d", &u, &c);
        --u;
        c = ((c % MOD) + MOD) % MOD;
        printf("%d\n", cycLen[toInd(u, c)]);
    }

    return 0;
}