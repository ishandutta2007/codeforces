#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<pair<int, int>> sol;
int r = 1;

void dfs(int n, int p, int l) {
    r += adj[n].size();
    sol[n] = {l, r};
    int i = r;
    for (auto c : adj[n]) {
        if (c != p) {
            dfs(c, n, --i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    adj[1].push_back(0);

    sol.resize(n + 1);
    dfs(1, 0, 1);
    for (int i = 1; i <= n; ++i) {
        cout << sol[i].first << ' ' << sol[i].second << '\n';
    }
}