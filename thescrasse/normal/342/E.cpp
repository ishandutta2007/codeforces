// 342E
// query con colorazione di un nodo e distanza minima da un nodo colorato

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, x, s, sq, c[100010], parent[100010][20], dist[100010], distsp[100010], nw;
bool visited[100010];
vector<long long> adj[100010];
vector<long long> st;
queue<long long> q;

void dfs(int s) {
    for (auto u : adj[s]) {
        if (!visited[u]) {
            visited[u] = true;
            dist[u] = dist[s] + 1;
            parent[u][0] = s;
            k = 1;
            while (dist[u] >= (1 << k)) {
                parent[u][k] = parent[parent[u][k - 1]][k - 1];
                k++;
            }
            dfs(u);
        }
    }
}

void bfs(vector<long long> st) {
    long long i, j, k, res, s;

    for (i = 1; i <= n; i++) {
        visited[i] = false;
    }
    for (auto u : st) {
        q.push(u);
        visited[u] = true;
        distsp[u] = 0;
    }

    while (!q.empty()) {
        s = q.front(); q.pop();
        for (auto u : adj[s]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
                distsp[u] = distsp[s] + 1;
            }
        }
    }
}

long long lca(long long a, long long b) {
    long long i, j, k, res, s;
    res = dist[a] + dist[b];

    if (dist[a] < dist[b]) {
        swap(a, b);
    }
    k = dist[a] - dist[b];
    for (i = 0; i < 20; i++) {
        if ((k >> i) & 1 == 1) {
            a = parent[a][i];
        }
    }

    k = -1;
    while (dist[b] >= (1 << (k + 1))) {
        k++;
    }

    while (k >= 0) {
        if (parent[a][k] != parent[b][k]) {
            a = parent[a][k]; b = parent[b][k];
        }
        k--;
    }

    res -= (2 * dist[a]);
    if (a != b) {
        res += 2;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m;
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited[1] = true;
    dist[1] = 0;
    dfs(1);

    sq = sqrt(m);
    st.push_back(1);

    for (i = 0; i < m; i += sq) {
        nw = -1;
        bfs(st);
        for (j = i; j < min(i + sq, m); j++) {
            cin >> t >> x;
            if (t == 1) {
                st.push_back(x);
                if (nw == -1) {
                    nw = st.size() - 1;
                }
            } else {
                res = distsp[x];
                if (nw != -1) {
                    s = st.size();
                    for (k = nw; k < s; k++) {
                        res = min(res, lca(x, st[k]));
                    }
                }
                cout << res << endl;
            }
        }
    }

    return 0;
}