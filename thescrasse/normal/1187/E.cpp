// 1187E
// colorazione tree, guadagno punti in base alla grandezza della componente connessa bianca

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, subtree[200010], st;
bool visited[200010];
vector<long long> adj[200010];

void dfs(int s) {
    subtree[s] = 1;
    visited[s] = true;
    for (auto u : adj[s]) {
        if (!visited[u]) {
            dfs(u);
            subtree[s] += subtree[u];
        }
    }
    st += subtree[s];
}

void solve(int s, long long pts) {
    res = max(res, pts);
    visited[s] = true;
    for (auto u : adj[s]) {
        if (!visited[u]) {
            solve(u, pts + n - 2 * subtree[u]);
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
    }

    st = 0;
    dfs(1);

    for (i = 1; i <= n; i++) {
        visited[i] = false;
    }
    res = st;
    solve(1, st);

    cout << res << endl;

    return 0;
}