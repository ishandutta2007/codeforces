#include <bits/stdc++.h>
using namespace std;

const int N = 3001;

vector<array<int, 2>> visited;
vector<int> adj[N], tour;
set<int> euler[N];
int n;

void dfs(int u) {
    while (!euler[u].empty()) {
        int v = *euler[u].begin();
        visited.push_back({u, v});
        euler[u].erase(v);
        euler[v].erase(u);
        dfs(v);
    }
    tour.push_back(u);
}

void check(int i, vector<int> &shift) {
    int odd = 0;
    for (int j = 1; j <= n; ++j) {
        odd += euler[j].size() % 2;
    }
    odd -= 2 * (euler[i].size() % 2);

    if (odd == 0) {
        tour.clear();
        dfs(i);

        bool ok = true;
        for (int j = 1; j <= n; ++j) {
            ok &= euler[j].empty();
        }

        if (ok) {
            tour.push_back(-1);
            for (auto j : shift) {
                tour.push_back(j);
                tour.push_back(i);
            }

            cout << tour.size() << "\n";
            for (auto j : tour) {
                cout << j << " ";
            }
            cout << "\n";

            exit(0);
        }
    }

    for (auto [u, v] : visited) {
        euler[u].insert(v);
        euler[v].insert(u);
    }
    visited.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            euler[j] = set<int>(adj[j].begin(), adj[j].end());
        }

        vector<int> shift;
        for (auto j : adj[i]) {
            if (euler[j].size() % 2 == 1) {
                shift.push_back(j);
                euler[j].erase(i);
                euler[i].erase(j);
            }
        }

        check(i, shift);

        for (int k = 0; k < (int) shift.size(); ++k) {
            int j = shift[k];
            shift.erase(shift.begin() + k);
            euler[i].insert(j);
            euler[j].insert(i);

            check(i, shift);

            shift.insert(shift.begin() + k, j);
            euler[i].erase(j);
            euler[j].erase(i);
        }
    }

    cout << 0 << "\n";
}