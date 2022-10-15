#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Kuhn {
    int N, M;
    vector<vector<int>> E;
    vector<int> matchA, matchB;
    vector<bool> vis;
    Kuhn(int N, int M) : N(N), M(M), E(N), matchA(N, -1), matchB(M, -1), vis(N) {}
    void add_edge(int u, int v) {
        E[u].push_back(v);
    }
    bool augment(int u) {
        vis[u] = true;
        for (auto v : E[u]) {
            int w = matchB[v];
            if (w == -1 || (not vis[w] && augment(w))) {
                matchA[u] = v, matchB[v] = u;
                return true;
            }
        }
        return false;
    }
    int mx = 0;
    int maximum_matching() {
        while (true) {
            bool converged = true;
            fill(begin(vis), end(vis), false);
            for (int u = 0; u < N; ++u) {
                if (not vis[u] && matchA[u] == -1 && augment(u)) {
                    converged = false;
                    break;
                    ++mx;
                }
            }
            if (converged) break;
        }
        return mx;
    }
    vector<int> left_cover() const {
        vector<int> U;
        for (int u = 0; u < N; ++u) {
            if (not vis[u]) U.push_back(u);
        }
        return U;
    }
    vector<int> right_cover() const {
        vector<int> V;
        for (int v = 0; v < M; ++v) {
            int u = matchB[v];
            if (u != -1 && vis[u]) V.push_back(v);
        }
        return V;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int d, n;
    cin >> d >> n;
    vector<int> V(n);
    for (int u = 0; u < n; ++u) {
        string s;
        cin >> s;
        for (int i = 0; i < d; ++i) {
            if (s[i] == '1') {
                V[u] |= 1 << i;
            }
        }
    }
    vector<int> popcount(1 << d);
    for (int mask = 1; mask < (1 << d); ++mask) {
        int lsb = mask & -mask;
        popcount[mask] = 1 + popcount[mask ^ lsb];
    }
    sort(begin(V), end(V), [&](int mask1, int mask2) { return popcount[mask1] > popcount[mask2]; });
    Kuhn kuhn(n, n);
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < u; ++v) {
            if ((V[u] & V[v]) == V[u]) {
                kuhn.add_edge(u, v);
            }
        }
    }
    kuhn.maximum_matching();
    vector<bool> vis(n);
    vector<int> op;
    for (int u = n - 1; u >= 0; --u) {
        if (vis[u]) continue;
        int last = 0;
        for (int v = u; v != -1; vis[v] = true, v = kuhn.matchA[v]) {
            int x = V[v] ^ last;
            for (int i = 0; i < d; ++i) {
                if (x >> i & 1) {
                    op.push_back(i);
                }
            }
            last = V[v];
        }
        op.push_back(-1);
    }
    op.pop_back();
    int k = (int)size(op);
    cout << k << endl;
    for (int j = 0; j < k; ++j) {
        if (op[j] == -1) {
            cout << 'R' << " ";
        }
        else {
            cout << op[j] << "\n "[j + 1 < k];
        }
    }
    exit(0);
}