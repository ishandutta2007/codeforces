// 1324F
// per ogni nodo di un tree trovare differenza massima tra nodi bianchi e neri di un subtree che passa per quel nodo
// idee: dfs per calcolare con dp differenza massima con root 1, altra dfs per spostare la root

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res[200010], check1, a, b, c[200010], v[200010], dp[200010];
bool visited[200010];
vector<long long> adj[200010];
queue<long long> q;

void dfs(int s) {
    visited[s] = true;
    v[s] = c[s];
    for (auto u : adj[s]) {
        if (visited[u]) {
            continue;
        }
        dfs(u);
        v[s] += max(v[u], (long long)0);
    }
}

void rrt(int s) {
    res[s] = v[s];
    visited[s] = true;
    for (auto u : adj[s]) {
        if (visited[u]) {
            continue;
        }
        v[s] = v[s] - max(v[u], (long long)0);
        v[u] = v[u] + max(v[s], (long long)0);
        rrt(u);
        v[u] = v[u] - max(v[s], (long long)0);
        v[s] = v[s] + max(v[u], (long long)0);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a;
        c[i] = 2 * a - 1;
    }
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for (i = 1; i <= n; i++) {
        visited[i] = false;
    }
    rrt(1);

    for (i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }

    return 0;
}