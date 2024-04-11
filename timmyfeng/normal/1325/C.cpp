#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    bool ok = false;
    vector<int> ans(n - 1, -1);
    vector<vector<int>> edge(n + 1);
    for (int i = 0; i < n - 1 && !ok; ++i) {
        int u, v;
        cin >> u >> v;
        for (auto j : {u, v}) {
            edge[j].push_back(i);
            if (edge[j].size() >= 3) {
                for (int k = 0; k < 3; ++k) {
                    ans[edge[j][k]] = k;
                }
                ok = true;
                break;
            }
        }
    }

    int ct = (ok ? 2 : -1);
    for (auto i : ans) {
        cout << (i == -1 ? ++ct : i) << '\n';
    }
}