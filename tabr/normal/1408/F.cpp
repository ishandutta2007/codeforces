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
    vector<pair<int, int>> ans;
    for (int j = 0; j < 14; j++) {
        for (int i = 0; i + (1 << (j + 1)) - 1 < n; i += (1 << (j + 1))) {
            for (int k = 0; k < (1 << j); k++) {
                ans.emplace_back(i + k, i + k + (1 << j));
            }
        }
    }
    vector<int> b;
    vector<vector<int>> c;
    int d = 0;
    for (int i = 13; i >= 0; i--) {
        if (n & (1 << i)) {
            b.emplace_back(1 << i);
            vector<int> v(1 << i);
            for (int j = 0; j < (1 << i); j++) {
                v[j] = (d + j);
            }
            d += 1 << i;
            c.emplace_back(v);
        }
    }
    debug(b, c);
    while ((int)b.size() > 2) {
        int sz = (int)b.size();
        while (b[sz - 1] != b[sz - 2]) {
            for (int i = 0; i < b[sz - 1]; i++) {
                ans.emplace_back(c[0].back(), c[sz - 1][i]);
                c[sz - 1].emplace_back(c[0].back());
                c[0].pop_back();
                b[0]--;
            }
            b[sz - 1] *= 2;
        }
        debug(b, c);
        for (int i = 0; i < b[sz - 1]; i++) {
            ans.emplace_back(c[sz - 1][i], c[sz - 2][i]);
            c[sz - 2].emplace_back(c[sz - 1][i]);
        }
        b[sz - 2] += b[sz - 1];
        c.pop_back();
        b.pop_back();
    }
    cout << ans.size() << '\n';
    for (auto p : ans) {
        p.first++, p.second++;
        cout << p.first << " " << p.second << '\n';
    }
    return 0;
}