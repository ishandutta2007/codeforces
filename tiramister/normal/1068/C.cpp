#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> path[n];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (u > v) swap(u, v);
        path[u].push_back(v);
    }

    vector<int> ans[n];
    for (int v = 0; v < n; ++v) {
        int itr = v * 100 + 1;
        for (int sv : path[v]) {
            ans[v].push_back(itr);
            ans[sv].push_back(itr);
            ++itr;
        }
    }

    for (int v = 0; v < n; ++v) {
        if (ans[v].empty()) {
            cout << 1 << endl;
            cout << v + 1 << " " << 100000 + v << endl;
        } else {
            cout << ans[v].size() << endl;
            for (int x : ans[v]) {
                cout << v + 1 << " " << x << endl;
            }
        }
    }
    return 0;
}