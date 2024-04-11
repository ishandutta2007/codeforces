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
    int n = (int) 5e5 + 5;
    vector<vector<int>> a(n);
    int q;
    cin >> q;
    int id = 0;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        int x;
        cin >> x;
        if (op == 1) {
            a[x].emplace_back(id++);
        } else {
            int y;
            cin >> y;
            if (x == y) {
                continue;
            }
            if (a[x].size() > a[y].size()) {
                swap(a[x], a[y]);
            }
            a[y].insert(a[y].end(), a[x].begin(), a[x].end());
            a[x].clear();
        }
    }
    vector<int> ans(id);
    for (int i = 0; i < n; i++) {
        for (int j : a[i]) {
            ans[j] = i;
        }
    }
    for (int i : ans) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}