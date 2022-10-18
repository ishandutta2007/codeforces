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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int k = n;
        for (int i = 0; i < n; i++) {
            if (b[i] <= i) {
                k = i;
                break;
            }
        }
        cout << k << '\n';
        vector<vector<int>> c(n + 2);
        for (int i = 0; i < n; i++) {
            c[b[i]].emplace_back(i + 1);
        }
        int id = 0;
        if (c[0].empty()) {
            id = n + 1;
        }
        vector<int> ans;
        debug(c);
        while ((int) ans.size() < n) {
            int new_id = -1;
            for (int i : c[id]) {
                if (!c[i].empty()) {
                    assert(new_id == -1);
                    new_id = i;
                }
            }
            for (int i : c[id]) {
                if (i != new_id) {
                    ans.emplace_back(i);
                }
            }
            id = new_id;
            ans.emplace_back(id);
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}