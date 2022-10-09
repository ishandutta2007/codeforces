#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, degr[100010], dist[100010], nl, root, check0, anc[100010];
bool visited[100010];
vector<long long> adj[100010];
set<long long> s;

void dfs(int s) {
    for (auto u : adj[s]) {
        if (!visited[u]) {
            visited[u] = true;
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

    cin >> n;
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degr[a]++;
        degr[b]++;
    }

    nl = 0;
    for (i = 1; i <= n; i++) {
        if (degr[i] == 1) {
            nl++;
        } else {
            root = i;
        }
    }

    visited[root] = true;
    dist[root] = 0;
    dfs(root);

    check0 = 0; check1 = 0;
    for (i = 1; i <= n; i++) {
        if (degr[i] == 1) {
            if (dist[i] % 2 == 0) {
                check0 = 1;
            } else {
                check1 = 1;
            }
        }
    }
    if (check0 == 1 && check1 == 1) {
        cout << 3 << ' ';
    } else {
        cout << 1 << ' ';
    }

    for (i = 1; i <= n; i++) {
        if (degr[i] == 1) {
            anc[i] = adj[i][0];
        }
    }
    for (i = 1; i <= n; i++) {
        if (degr[i] == 1) {
            s.insert(anc[i]);
            res = n - 1 - nl + s.size();
        }
    }

    cout << res;

    return 0;
}