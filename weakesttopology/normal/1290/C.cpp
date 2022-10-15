#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU {
    vector<int> p, rk, color;
    vector<array<int, 2>> cost, need;
    DSU(int n) : p(n), rk(n), color(n), cost(n, {1, 0}), need(n) {
        iota(begin(p), end(p), 0);
    }
    int find(int u) {
        if (p[u] == u) return u;
        int v = find(p[u]);
        color[u] ^= color[p[u]];
        return p[u] = v;
    }
    int find_color(int u) {
        find(u);
        return color[u];
    }
    void flip(int u) {
        u = find(u);
        color[u] ^= 1;
        swap(cost[u][0], cost[u][1]);
        swap(need[u][0], need[u][1]);
    }
    int unite(int u, int v, int b) {
        u = find(u), v = find(v);
        if (u == v) return 0;
        int diff = -(get_cost(u) + get_cost(v));
        if (rk[u] < rk[v]) swap(u, v);
        if (b) flip(v);
        p[v] = u, rk[u] += (rk[u] == rk[v]);
        for (int t : {0, 1}) {
            cost[u][t] += cost[v][t];
            if (need[v][t]) need[u][t] = 1;
        }
        diff += get_cost(u);
        return diff;
    }
    int get_cost(int u) {
        u = find(u);
        for (int t : {0, 1}) {
            if (need[u][t]) return cost[u][t];
        }
        return min(cost[u][0], cost[u][1]);
    }
    int request(int u, int b) {
        int pu = find(u), t = color[u] ^ b;
        int diff = -get_cost(u);
        need[pu][t] = 1;
        diff += get_cost(u);
        return diff;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vector<int>> E(n);
    for (int j = 0; j < k; ++j) {
        int c;
        cin >> c;
        for (int l = 0; l < c; ++l) {
            int i;
            cin >> i;
            --i;
            E[i].push_back(j);
        }
    }
    DSU dsu(k);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (size(E[i]) == 1) {
            int u = E[i][0];
            ans += dsu.request(u, s[i] - '0');
        }
        else if (size(E[i]) == 2) {
            int u = E[i][0], v = E[i][1];
            if (dsu.find(u) != dsu.find(v)) {
                ans += dsu.unite(u, v, (dsu.find_color(u) ^ dsu.find_color(v)) ^ (s[i] - '0') ^ 1);
            }
        }
        cout << ans << endl;
    }
    exit(0);
}