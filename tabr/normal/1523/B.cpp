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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i += 2) {
            vector<int> x(3);
            x[1] = i + 1;
            x[2] = i + 2;
            for (int j = 0; j < 6; j++) {
                x[0] = j % 2 + 1;
                ans.emplace_back(x);
            }
        }
        cout << ans.size() << '\n';
        for (auto v : ans) {
            for (int i : v) {
                cout << i << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}