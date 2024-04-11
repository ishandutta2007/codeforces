#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

vector<int> adj[N];
bool winner[N];

void dfs(int u) {
    winner[u] = true;
    for (auto c : adj[u]) {
        if (!winner[c]) {
            dfs(c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (auto &i : a) {
            cin >> i;
        }
        for (auto &i : b) {
            cin >> i;
        }

        vector<int> ranking(n);
        iota(ranking.begin(), ranking.end(), 0);

        fill(adj, adj + n, vector<int>());
        fill(winner, winner + n, false);

        for (auto strength : {a, b}) {
            sort(ranking.begin(), ranking.end(), [&](int i, int j) {
                return strength[i] < strength[j];
            });
            for (int i = 0; i < n - 1; ++i) {
                adj[ranking[i]].push_back(ranking[i + 1]);
            }
        }

        dfs(ranking[n - 1]);

        for (int i = 0; i < n; ++i) {
            cout << winner[i];
        }
        cout << "\n";
    }
}