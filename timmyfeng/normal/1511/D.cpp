#include <bits/stdc++.h>
using namespace std;

const int A = 26;

set<int> adj[A];
string euler;

void dfs(int u) {
    while (!adj[u].empty()) {
        int c = *adj[u].begin();
        adj[u].erase(adj[u].begin());
        dfs(c);
    }
    euler.push_back('a' + u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            adj[i].insert(j);
        }
    }

    dfs(0);

    euler.pop_back();

    for (int i = 0; i < n; ++i) {
        cout << euler[i % euler.size()];
    }
    cout << "\n";
}