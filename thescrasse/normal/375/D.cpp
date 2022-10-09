// 375D
// query con numero elementi che si trovano almeno k_i volte nel subtree di v_i

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#pragma GCC optimize("Ofast")

#define endl "\n"
#define ll long long
#define INF (int)1e18
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int i, i1, j, k, k1, t, n, m, res[100010], check1, a, b, c[100010];
bool visited[100010];
vector<pair<int, int>> q[100010];
vector<int> adj[100010];
map<int, int> f[100010], curr0[100010], curr1[100010];
indexed_set g[100010];

void dfs(int s) {
    // cout << "s = " << s << endl;
    int q1, q2, u1f, u1s;
    for (auto u : adj[s]) {
        if (visited[u]) {
            continue;
        }
        // cout << "u = " << u << endl;
        visited[u] = true;
        dfs(u);
        if (f[u].size() > f[s].size()) {
            swap(f[s], f[u]);
            g[s].swap(g[u]); // lol
            swap(curr0[s], curr0[u]);
            swap(curr1[s], curr1[u]);
        }
        for (auto u1 : f[u]) {
            u1f = u1.first; u1s = u1.second;
            // cout << "u1f, u1s = " << u1f << ' ' << u1s << endl;
            if (f[s].count(u1f)) {
                g[s].erase({f[s][u1f], curr0[s][f[s][u1f]]});
                curr0[s][f[s][u1f]]++;
                // cout << "curr0 = " << curr0[s][u1f] << endl;
            }
            f[s][u1f] += u1s;
            g[s].insert({f[s][u1f], curr1[s][f[s][u1f]]});
            curr1[s][f[s][u1f]]++;
            // cout << "f[s][u1f] = " << f[s][u1f] << endl;
            // cout << "curr1 = " << curr1[s][u1f] << endl;
        }
    }
    if (!q[s].empty()) {
        for (auto u : q[s]) {
            q1 = u.first; q2 = u.second;
            res[q2] = g[s].size() - g[s].order_of_key({q1, -1});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> c[i];
        f[i][c[i]]++;
        g[i].insert({1, 0});
        curr1[i][1]++;
    }
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (i = 0; i < m; i++) {
        cin >> a >> b;
        q[a].push_back({b, i});
    }

    visited[1] = true;
    dfs(1);
    for (i = 0; i < m; i++) {
        cout << res[i] << endl;
    }

    /* for (i = 1; i <= n; i++) {
        cout << g[i].size() << endl;
        for (auto u : curr0[i]) {
            cout << u.first << ' ' << u.second << endl;
        }
        cout << endl;
        for (auto u : curr1[i]) {
            cout << u.first << ' ' << u.second << endl;
        }
        cout << endl;
    } */

    return 0;
}