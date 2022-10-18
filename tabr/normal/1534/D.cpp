#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    auto ask = [&](int x) {
        cout << "? " << x + 1 << endl;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        return d;
    };
    vector<vector<int>> d(n);
    d[0] = ask(0);
    int even = 0, odd = 0;
    for (int i = 1; i < n; i++) {
        if (d[0][i] % 2 == 1) {
            odd++;
        } else {
            even++;
        }
    }
    int id = 0;
    if (odd < even) {
        id = 1;
    }
    for (int i = 1; i < n; i++) {
        if (d[0][i] % 2 == id) {
            d[i] = ask(i);
        }
    }
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        if (d[i].empty()) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (d[i][j] == 1) {
                if (i < j) {
                    edges.emplace_back(i, j);
                } else {
                    edges.emplace_back(j, i);
                }
            }
        }
    }
    sort(edges.begin(), edges.end());
    edges.resize(unique(edges.begin(), edges.end()) - edges.begin());
    cout << "!" << endl;
    for (auto p : edges) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
    return 0;
}