#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    int n = 0;
    map<int, vector<int>> indices;

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int x; cin >> x;
            indices[x].push_back(n++);
        } else {
            int x, y; cin >> x >> y;
            if (x == y) continue;
            
            if (indices[x].size() > indices[y].size()) {
                swap(indices[x], indices[y]);
            }

            indices[y].insert(indices[y].end(), indices[x].begin(), indices[x].end());
            indices.erase(x);
        }
    }

    vector<int> ans(n);
    for (auto &[value, where] : indices) {
        for (auto i : where) {
            ans[i] = value;
        }
    }

    for (auto &i : ans) {
        cout << i << " ";
    }
    cout << "\n";
}