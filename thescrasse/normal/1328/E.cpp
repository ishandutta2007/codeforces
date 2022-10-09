#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, check2, a[200010], b, w, v, dist[200010], q, st, p2[20], steps, cur, bt;
int anc[200010][20], parent[200010];
bool visited[200010];
vector<long long> adj[200010];
vector<long long> qv;

void dfs(int s) {
    visited[s] = true;
    j = 0;
    while (p2[j] <= dist[s]) {
        if (j == 0) {
            anc[s][j] = parent[s];
        } else {
            anc[s][j] = anc[anc[s][j - 1]][j - 1];
            // cout << s << ' ' << j << ' ' << anc[s][j - 1] << ' ' << anc[anc[s][j - 1]][j - 1] << endl;
        }
        j++;
    }
    for (auto u : adj[s]) {
        if (!visited[u]) {
            parent[u] = s;
            dist[u] = dist[s] + 1;
            dfs(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> q;
    for (i = 0; i < n - 1; i++) {
        cin >> w >> v;
        adj[w].push_back(v);
        adj[v].push_back(w);
    }

    p2[0] = 1;
    for (i = 1; i <= 20; i++) {
        p2[i] = p2[i - 1] * 2;
    }

    dist[1] = 0;
    dfs(1);
    parent[1] = -1;

    for (i1 = 0; i1 < q; i1++) {
        qv.clear();
        cin >> b;
        for (i = 0; i < b; i++) {
            cin >> w;
            qv.push_back(w);
        }

        m = -1;
        st = -1;
        for (auto u : qv) {
            if (dist[u] > m) {
                m = dist[u];
                st = u;
            }
        }

        // cout << st << endl;

        check1 = 1;
        for (auto u : qv) {
            // cout << "u = " << u << endl;
            cur = st;
            steps = dist[st] - dist[u];
            bt = 0;
            while (steps != 0) {
                if ((steps >> bt) & 1 == 1) {
                    // cout << "bt = " << bt << endl;
                    cur = anc[cur][bt];
                    // cout << cur << endl;
                    steps -= p2[bt];
                }
                bt++;
            }
            // cout << cur << endl;
            if (u == cur) {
                continue;
            }
            if (parent[u] == parent[cur]) {
                continue;
            }
            check1 = 0;
            // cout << check1 << endl;
        }

        if (check1 == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}