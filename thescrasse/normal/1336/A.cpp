#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, dist[200010], parent[200010], subtree[200010];
bool visited[200010];
vector<long long> v;
vector<long long> adj[200010];

void dfs(int s) {
    subtree[s] = 1;
    for (auto u : adj[s]) {
        if (!visited[u]) {
            visited[u] = true;
            dist[u] = dist[s] + 1;
            parent[u] = s;
            dfs(u);
            subtree[s] += subtree[u];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> k;
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited[1] = true;
    dist[1] = 0;
    dfs(1);

    res = 0;

    for (i = 1; i <= n; i++) {
        v.push_back({dist[i] - subtree[i] + 1});
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (i = 0; i < k; i++) {
        res += v[i];
    }

    cout << res;

    return 0;
}