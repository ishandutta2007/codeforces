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
        int ans = 0;
        vector<vector<vector<int>>> c(1, vector<vector<int>>(2, vector<int>(n)));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> c[0][i][j];
            }
        }
        for (int i = 29; i >= 0; i--) {
            vector<vector<vector<int>>> new_c;
            bool ok = true;
            for (auto v : c) {
                vector<int> cnt(2);
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < (int) v[j].size(); k++) {
                        if (v[j][k] & (1 << i)) {
                            cnt[j]++;
                        }
                    }
                }
                if (cnt[0] + cnt[1] == (int) v[0].size()) {
                    vector<vector<int>> nv0(2), nv1(2);
                    for (int k = 0; k < (int) v[0].size(); k++) {
                        if (v[0][k] & (1 << i)) {
                            nv0[0].emplace_back(v[0][k]);
                        } else {
                            nv1[0].emplace_back(v[0][k]);
                        }
                        if (v[1][k] & (1 << i)) {
                            nv1[1].emplace_back(v[1][k]);
                        } else {
                            nv0[1].emplace_back(v[1][k]);
                        }
                    }
                    if (!nv0[0].empty()) {
                        new_c.emplace_back(nv0);
                    }
                    if (!nv1[0].empty()) {
                        new_c.emplace_back(nv1);
                    }
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans |= 1 << i;
                swap(c, new_c);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}